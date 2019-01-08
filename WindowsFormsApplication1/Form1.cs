using MSTSCLib;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
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
            axRdpClient1.UserName = txtAccount.Text;
            axRdpClient1.Height = 1080;
            axRdpClient1.Width = 1920;
            axRdpClient1.FullScreen = true;
            axRdpClient1.Server = txtIP.Text;
            //axRdpClient1.AdvancedSettings8.RedirectDrives = true;
                 
            ((IMsTscNonScriptable)axRdpClient1.GetOcx()).ClearTextPassword = txtPwd.Text;
            axRdpClient1.Connect();
        }
    }
}
