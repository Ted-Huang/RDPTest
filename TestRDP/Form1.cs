using RDPCOMAPILib;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Management;
using System.Text;
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

        private void OpenRDC()
        {
            try
            {
                RDPSession _rdpSession = new RDPSession();  // 新建RDP Session

                //_rdpSession.SetDesktopSharedRect(0, 0, 1920, 1080);// 設定共享區域，如果不設定預設為整個螢幕，當然如果有多個螢幕，還是設定下主螢幕，否則，區域會很大

                _rdpSession.Open(); // 開啟會話
                
                IRDPSRAPIInvitation invitation = _rdpSession.Invitations.CreateInvitation("baseAuth", "groupName", "", 64);  // 建立申請
                txtConnectString.Text = invitation.ConnectionString;
                _rdpSession.OnAttendeeConnected += new _IRDPSessionEvents_OnAttendeeConnectedEventHandler(OnAttendeeConnected);
            }
            catch (Exception ex)
            {
                MessageBox.Show(string.Format("error {0}", ex.ToString()));
            }
        }


        private void OnAttendeeConnected(object pObjAttendee)
        {

            IRDPSRAPIAttendee pAttendee = pObjAttendee as IRDPSRAPIAttendee;

            pAttendee.ControlLevel = CTRL_LEVEL.CTRL_LEVEL_INTERACTIVE;
        }

        private void btnOpenRDC_Click(object sender, EventArgs e)
        {
            OpenRDC();
        }
    }
}
