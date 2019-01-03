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
            this.btnOpenRDC = new System.Windows.Forms.Button();
            this.txtConnectString = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // btnOpenRDC
            // 
            this.btnOpenRDC.Location = new System.Drawing.Point(24, 18);
            this.btnOpenRDC.Name = "btnOpenRDC";
            this.btnOpenRDC.Size = new System.Drawing.Size(75, 23);
            this.btnOpenRDC.TabIndex = 2;
            this.btnOpenRDC.Text = "OpenSession";
            this.btnOpenRDC.UseVisualStyleBackColor = true;
            this.btnOpenRDC.Click += new System.EventHandler(this.btnOpenRDC_Click);
            // 
            // txtConnectString
            // 
            this.txtConnectString.Location = new System.Drawing.Point(24, 58);
            this.txtConnectString.Name = "txtConnectString";
            this.txtConnectString.Size = new System.Drawing.Size(1217, 22);
            this.txtConnectString.TabIndex = 9;
            this.txtConnectString.Text = "ConnectString";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1268, 128);
            this.Controls.Add(this.txtConnectString);
            this.Controls.Add(this.btnOpenRDC);
            this.Name = "Form1";
            this.Text = "Session";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnOpenRDC;
        private System.Windows.Forms.TextBox txtConnectString;
    }
}

