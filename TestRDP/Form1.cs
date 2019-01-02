using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Management;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        bool HasServerFeatureById(UInt32 roleId)
        {
            try
            {
                ManagementClass serviceClass = new ManagementClass("Win32_ServerFeature");
                foreach (ManagementObject feature in serviceClass.GetInstances())
                {
                    if ((UInt32)feature["ID"] == roleId)
                    {
                        return true;
                    }
                }

                return false;
            }
            catch (ManagementException ex)
            {
                // The most likely cause of this is that this is being called from an 
                // operating system that is not a server operating system.
                MessageBox.Show(string.Format("error {0}", ex.ToString()));
            }

            return false;
        }

        private void OpenRDC()
        {
            try
            {
                axMsRdpClient7NotSafeForScripting1.Server = txtIP.Text;
                axMsRdpClient7NotSafeForScripting1.FullScreen = true;
                //axMsRdpClient7NotSafeForScripting1.DesktopHeight = 800;
                //axMsRdpClient7NotSafeForScripting1.DesktopWidth = 600;

                //axMsRdpClient7NotSafeForScripting1.Width = 800;
                //axMsRdpClient7NotSafeForScripting1.Height = 600;
                axMsRdpClient7NotSafeForScripting1.Width = Screen.PrimaryScreen.Bounds.Width;
                axMsRdpClient7NotSafeForScripting1.Height = Screen.PrimaryScreen.Bounds.Height;

                axMsRdpClient7NotSafeForScripting1.AdvancedSettings5.AuthenticationLevel = 2;
                axMsRdpClient7NotSafeForScripting1.AdvancedSettings7.EnableCredSspSupport = true;

                axMsRdpClient7NotSafeForScripting1.AdvancedSettings2.RedirectDrives = false;
                axMsRdpClient7NotSafeForScripting1.AdvancedSettings2.RedirectPrinters = false;
                axMsRdpClient7NotSafeForScripting1.AdvancedSettings2.RedirectPrinters = false;
                //axMsRdpClient7NotSafeForScripting1.AdvancedSettings2.RedirectClipboard = true;
                axMsRdpClient7NotSafeForScripting1.AdvancedSettings2.RedirectSmartCards = false;

                axMsRdpClient7NotSafeForScripting1.SecuredSettings2.KeyboardHookMode = 1;

                axMsRdpClient7NotSafeForScripting1.FullScreenTitle = "test";
                if (axMsRdpClient7NotSafeForScripting1.SecuredSettingsEnabled == 0)
                    axMsRdpClient7NotSafeForScripting1.SecuredSettings.StartProgram = "notepad.exe";


                axMsRdpClient7NotSafeForScripting1.Connect();
            }
            catch (Exception ex)
            {
                MessageBox.Show(string.Format("error {0}", ex.ToString()));
            }
        }

        private void btnDetect_Click(object sender, EventArgs e)
        {
            // 14 is the identifier of the Remote Desktop Services role.
            if (HasServerFeatureById(14))
                MessageBox.Show("true");
            else
                MessageBox.Show("false");
        }

        private void btnOpenRDC_Click(object sender, EventArgs e)
        {
            OpenRDC();
        }
    }
}
