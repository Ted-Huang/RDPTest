namespace WindowsFormsApplication1
{
    partial class Form1
    {
        /// <summary>
        /// 設計工具所需的變數。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清除任何使用中的資源。
        /// </summary>
        /// <param name="disposing">如果應該處置 Managed 資源則為 true，否則為 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 設計工具產生的程式碼

        /// <summary>
        /// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
        /// 修改這個方法的內容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.axMsRdpClient7NotSafeForScripting1 = new AxMSTSCLib.AxMsRdpClient7NotSafeForScripting();
            this.btnDetect = new System.Windows.Forms.Button();
            this.btnOpenRDC = new System.Windows.Forms.Button();
            this.txtIP = new System.Windows.Forms.TextBox();
            this.txtUserName = new System.Windows.Forms.TextBox();
            this.txtPwd = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.txtConnectString = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.axMsRdpClient7NotSafeForScripting1)).BeginInit();
            this.SuspendLayout();
            // 
            // axMsRdpClient7NotSafeForScripting1
            // 
            this.axMsRdpClient7NotSafeForScripting1.Enabled = true;
            this.axMsRdpClient7NotSafeForScripting1.Location = new System.Drawing.Point(24, 120);
            this.axMsRdpClient7NotSafeForScripting1.Name = "axMsRdpClient7NotSafeForScripting1";
            this.axMsRdpClient7NotSafeForScripting1.OcxState = ((System.Windows.Forms.AxHost.State)(resources.GetObject("axMsRdpClient7NotSafeForScripting1.OcxState")));
            this.axMsRdpClient7NotSafeForScripting1.Size = new System.Drawing.Size(1217, 639);
            this.axMsRdpClient7NotSafeForScripting1.TabIndex = 0;
            // 
            // btnDetect
            // 
            this.btnDetect.Location = new System.Drawing.Point(24, 13);
            this.btnDetect.Name = "btnDetect";
            this.btnDetect.Size = new System.Drawing.Size(75, 23);
            this.btnDetect.TabIndex = 1;
            this.btnDetect.Text = "Detect";
            this.btnDetect.UseVisualStyleBackColor = true;
            this.btnDetect.Click += new System.EventHandler(this.btnDetect_Click);
            // 
            // btnOpenRDC
            // 
            this.btnOpenRDC.Location = new System.Drawing.Point(125, 13);
            this.btnOpenRDC.Name = "btnOpenRDC";
            this.btnOpenRDC.Size = new System.Drawing.Size(75, 23);
            this.btnOpenRDC.TabIndex = 2;
            this.btnOpenRDC.Text = "OpenRDC";
            this.btnOpenRDC.UseVisualStyleBackColor = true;
            this.btnOpenRDC.Click += new System.EventHandler(this.btnOpenRDC_Click);
            // 
            // txtIP
            // 
            this.txtIP.Location = new System.Drawing.Point(237, 13);
            this.txtIP.Name = "txtIP";
            this.txtIP.Size = new System.Drawing.Size(100, 22);
            this.txtIP.TabIndex = 3;
            this.txtIP.Text = "192.168.8.35";
            // 
            // txtUserName
            // 
            this.txtUserName.Location = new System.Drawing.Point(413, 15);
            this.txtUserName.Name = "txtUserName";
            this.txtUserName.Size = new System.Drawing.Size(100, 22);
            this.txtUserName.TabIndex = 4;
            this.txtUserName.Text = "test";
            // 
            // txtPwd
            // 
            this.txtPwd.Location = new System.Drawing.Point(556, 15);
            this.txtPwd.Name = "txtPwd";
            this.txtPwd.Size = new System.Drawing.Size(100, 22);
            this.txtPwd.TabIndex = 5;
            this.txtPwd.Text = "test";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(374, 18);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(26, 12);
            this.label1.TabIndex = 6;
            this.label1.Text = "User";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(524, 18);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(25, 12);
            this.label2.TabIndex = 7;
            this.label2.Text = "Pwd";
            // 
            // txtConnectString
            // 
            this.txtConnectString.Location = new System.Drawing.Point(24, 76);
            this.txtConnectString.Name = "txtConnectString";
            this.txtConnectString.Size = new System.Drawing.Size(1217, 22);
            this.txtConnectString.TabIndex = 9;
            this.txtConnectString.Text = "ConnectString";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1268, 771);
            this.Controls.Add(this.txtConnectString);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txtPwd);
            this.Controls.Add(this.txtUserName);
            this.Controls.Add(this.txtIP);
            this.Controls.Add(this.btnOpenRDC);
            this.Controls.Add(this.btnDetect);
            this.Controls.Add(this.axMsRdpClient7NotSafeForScripting1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.axMsRdpClient7NotSafeForScripting1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private AxMSTSCLib.AxMsRdpClient7NotSafeForScripting axMsRdpClient7NotSafeForScripting1;
        private System.Windows.Forms.Button btnDetect;
        private System.Windows.Forms.Button btnOpenRDC;
        private System.Windows.Forms.TextBox txtIP;
        private System.Windows.Forms.TextBox txtUserName;
        private System.Windows.Forms.TextBox txtPwd;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtConnectString;
    }
}

