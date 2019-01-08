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
            this.axRdpClient1 = new AxMSTSCLib.AxMsRdpClient7NotSafeForScripting();
            this.txtIP = new System.Windows.Forms.TextBox();
            this.txtAccount = new System.Windows.Forms.TextBox();
            this.txtPwd = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.axRdpClient1)).BeginInit();
            this.SuspendLayout();
            // 
            // axRdpClient1
            // 
            this.axRdpClient1.Enabled = true;
            this.axRdpClient1.Location = new System.Drawing.Point(29, 35);
            this.axRdpClient1.Name = "axRdpClient1";
            this.axRdpClient1.OcxState = ((System.Windows.Forms.AxHost.State)(resources.GetObject("axRdpClient1.OcxState")));
            this.axRdpClient1.Size = new System.Drawing.Size(867, 509);
            this.axRdpClient1.TabIndex = 0;
            // 
            // txtIP
            // 
            this.txtIP.Location = new System.Drawing.Point(59, 6);
            this.txtIP.Name = "txtIP";
            this.txtIP.Size = new System.Drawing.Size(100, 22);
            this.txtIP.TabIndex = 1;
            this.txtIP.Text = "192.168.";
            // 
            // txtAccount
            // 
            this.txtAccount.Location = new System.Drawing.Point(227, 6);
            this.txtAccount.Name = "txtAccount";
            this.txtAccount.Size = new System.Drawing.Size(100, 22);
            this.txtAccount.TabIndex = 2;
            this.txtAccount.Text = "tt";
            // 
            // txtPwd
            // 
            this.txtPwd.Location = new System.Drawing.Point(416, 5);
            this.txtPwd.Name = "txtPwd";
            this.txtPwd.Size = new System.Drawing.Size(100, 22);
            this.txtPwd.TabIndex = 3;
            this.txtPwd.Text = "tt";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(29, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(15, 12);
            this.label1.TabIndex = 4;
            this.label1.Text = "IP";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(181, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(44, 12);
            this.label2.TabIndex = 5;
            this.label2.Text = "Account";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(351, 9);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(25, 12);
            this.label3.TabIndex = 6;
            this.label3.Text = "Pwd";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1007, 598);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txtPwd);
            this.Controls.Add(this.txtAccount);
            this.Controls.Add(this.txtIP);
            this.Controls.Add(this.axRdpClient1);
            this.Name = "Form1";
            this.Text = "TestMSTSC";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.axRdpClient1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private AxMSTSCLib.AxMsRdpClient7NotSafeForScripting axRdpClient1;
        private System.Windows.Forms.TextBox txtIP;
        private System.Windows.Forms.TextBox txtAccount;
        private System.Windows.Forms.TextBox txtPwd;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
    }
}

