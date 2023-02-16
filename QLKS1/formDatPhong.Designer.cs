namespace QLKS1
{
    partial class formDatPhong
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(formDatPhong));
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.txtIdKh = new System.Windows.Forms.TextBox();
            this.txtIdNv = new System.Windows.Forms.TextBox();
            this.dateT = new System.Windows.Forms.DateTimePicker();
            this.btDoi = new System.Windows.Forms.Button();
            this.btDon = new System.Windows.Forms.Button();
            this.btLoad = new System.Windows.Forms.Button();
            this.grBoxDs = new System.Windows.Forms.GroupBox();
            this.dtVDs = new System.Windows.Forms.DataGridView();
            this.btDat = new System.Windows.Forms.Button();
            this.btQuay = new System.Windows.Forms.Button();
            this.txtName = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.dtgVdat = new System.Windows.Forms.DataGridView();
            this.btXoa = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.grBoxDs.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dtVDs)).BeginInit();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dtgVdat)).BeginInit();
            this.SuspendLayout();
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.label2.Location = new System.Drawing.Point(9, 41);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(119, 20);
            this.label2.TabIndex = 1;
            this.label2.Text = "Mã khách hàng:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.label3.Location = new System.Drawing.Point(9, 94);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(107, 20);
            this.label3.TabIndex = 2;
            this.label3.Text = "Mã nhân viên:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.label5.Location = new System.Drawing.Point(496, 41);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(78, 20);
            this.label5.TabIndex = 4;
            this.label5.Text = "Thời gian:";
            // 
            // txtIdKh
            // 
            this.txtIdKh.Enabled = false;
            this.txtIdKh.Location = new System.Drawing.Point(134, 41);
            this.txtIdKh.Name = "txtIdKh";
            this.txtIdKh.Size = new System.Drawing.Size(111, 22);
            this.txtIdKh.TabIndex = 5;
            // 
            // txtIdNv
            // 
            this.txtIdNv.Enabled = false;
            this.txtIdNv.Location = new System.Drawing.Point(134, 94);
            this.txtIdNv.Name = "txtIdNv";
            this.txtIdNv.Size = new System.Drawing.Size(111, 22);
            this.txtIdNv.TabIndex = 6;
            // 
            // dateT
            // 
            this.dateT.Format = System.Windows.Forms.DateTimePickerFormat.Short;
            this.dateT.Location = new System.Drawing.Point(580, 39);
            this.dateT.Name = "dateT";
            this.dateT.Size = new System.Drawing.Size(144, 22);
            this.dateT.TabIndex = 7;
            // 
            // btDoi
            // 
            this.btDoi.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.btDoi.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btDoi.Location = new System.Drawing.Point(381, 90);
            this.btDoi.Name = "btDoi";
            this.btDoi.Size = new System.Drawing.Size(146, 29);
            this.btDoi.TabIndex = 8;
            this.btDoi.Text = "Phòng đôi";
            this.btDoi.UseVisualStyleBackColor = false;
            this.btDoi.Click += new System.EventHandler(this.btDoi_Click);
            // 
            // btDon
            // 
            this.btDon.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.btDon.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btDon.Location = new System.Drawing.Point(533, 90);
            this.btDon.Name = "btDon";
            this.btDon.Size = new System.Drawing.Size(141, 29);
            this.btDon.TabIndex = 9;
            this.btDon.Text = "Phòng đơn";
            this.btDon.UseVisualStyleBackColor = false;
            this.btDon.Click += new System.EventHandler(this.btDon_Click);
            // 
            // btLoad
            // 
            this.btLoad.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.btLoad.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("btLoad.BackgroundImage")));
            this.btLoad.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btLoad.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btLoad.Location = new System.Drawing.Point(687, 90);
            this.btLoad.Name = "btLoad";
            this.btLoad.Size = new System.Drawing.Size(37, 29);
            this.btLoad.TabIndex = 10;
            this.btLoad.UseVisualStyleBackColor = false;
            this.btLoad.Click += new System.EventHandler(this.btLoad_Click);
            // 
            // grBoxDs
            // 
            this.grBoxDs.Controls.Add(this.dtVDs);
            this.grBoxDs.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.grBoxDs.Location = new System.Drawing.Point(-2, 142);
            this.grBoxDs.Name = "grBoxDs";
            this.grBoxDs.Size = new System.Drawing.Size(827, 259);
            this.grBoxDs.TabIndex = 11;
            this.grBoxDs.TabStop = false;
            this.grBoxDs.Text = "Danh sách";
            // 
            // dtVDs
            // 
            this.dtVDs.BackgroundColor = System.Drawing.SystemColors.Control;
            this.dtVDs.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dtVDs.Location = new System.Drawing.Point(0, 26);
            this.dtVDs.Name = "dtVDs";
            this.dtVDs.RowHeadersWidth = 51;
            this.dtVDs.RowTemplate.Height = 24;
            this.dtVDs.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dtVDs.Size = new System.Drawing.Size(821, 233);
            this.dtVDs.TabIndex = 0;
            this.dtVDs.DoubleClick += new System.EventHandler(this.dtVDs_DoubleClick);
            // 
            // btDat
            // 
            this.btDat.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.btDat.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btDat.Location = new System.Drawing.Point(33, 413);
            this.btDat.Name = "btDat";
            this.btDat.Size = new System.Drawing.Size(94, 29);
            this.btDat.TabIndex = 12;
            this.btDat.Text = "Đặt";
            this.btDat.UseVisualStyleBackColor = false;
            this.btDat.Click += new System.EventHandler(this.btDat_Click);
            // 
            // btQuay
            // 
            this.btQuay.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.btQuay.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btQuay.Location = new System.Drawing.Point(665, 413);
            this.btQuay.Name = "btQuay";
            this.btQuay.Size = new System.Drawing.Size(94, 29);
            this.btQuay.TabIndex = 14;
            this.btQuay.Text = "Quay lại";
            this.btQuay.UseVisualStyleBackColor = false;
            this.btQuay.Click += new System.EventHandler(this.btQuay_Click);
            // 
            // txtName
            // 
            this.txtName.Enabled = false;
            this.txtName.Location = new System.Drawing.Point(350, 41);
            this.txtName.Name = "txtName";
            this.txtName.Size = new System.Drawing.Size(111, 22);
            this.txtName.TabIndex = 17;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Bold);
            this.label4.Location = new System.Drawing.Point(282, 41);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(62, 20);
            this.label4.TabIndex = 16;
            this.label4.Text = "Họ Tên:";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.dtgVdat);
            this.groupBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox1.Location = new System.Drawing.Point(-2, 453);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(827, 259);
            this.groupBox1.TabIndex = 18;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Danh sách";
            // 
            // dtgVdat
            // 
            this.dtgVdat.BackgroundColor = System.Drawing.SystemColors.Control;
            this.dtgVdat.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dtgVdat.Location = new System.Drawing.Point(0, 23);
            this.dtgVdat.Name = "dtgVdat";
            this.dtgVdat.RowHeadersWidth = 51;
            this.dtgVdat.RowTemplate.Height = 24;
            this.dtgVdat.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dtgVdat.Size = new System.Drawing.Size(821, 233);
            this.dtgVdat.TabIndex = 0;
            // 
            // btXoa
            // 
            this.btXoa.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.btXoa.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btXoa.Location = new System.Drawing.Point(465, 413);
            this.btXoa.Name = "btXoa";
            this.btXoa.Size = new System.Drawing.Size(94, 29);
            this.btXoa.TabIndex = 13;
            this.btXoa.Text = "Xóa";
            this.btXoa.UseVisualStyleBackColor = false;
            this.btXoa.Click += new System.EventHandler(this.btXoa_Click);
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.Location = new System.Drawing.Point(242, 413);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(94, 29);
            this.button1.TabIndex = 19;
            this.button1.Text = "Dịch vụ";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // formDatPhong
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Linen;
            this.ClientSize = new System.Drawing.Size(829, 735);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.txtName);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.btQuay);
            this.Controls.Add(this.btXoa);
            this.Controls.Add(this.btDat);
            this.Controls.Add(this.grBoxDs);
            this.Controls.Add(this.btLoad);
            this.Controls.Add(this.btDon);
            this.Controls.Add(this.btDoi);
            this.Controls.Add(this.dateT);
            this.Controls.Add(this.txtIdNv);
            this.Controls.Add(this.txtIdKh);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "formDatPhong";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "formDatPhong";
            this.Load += new System.EventHandler(this.formDatPhong_Load);
            this.grBoxDs.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dtVDs)).EndInit();
            this.groupBox1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dtgVdat)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox txtIdKh;
        private System.Windows.Forms.TextBox txtIdNv;
        private System.Windows.Forms.DateTimePicker dateT;
        private System.Windows.Forms.Button btDoi;
        private System.Windows.Forms.Button btDon;
        private System.Windows.Forms.Button btLoad;
        private System.Windows.Forms.GroupBox grBoxDs;
        private System.Windows.Forms.DataGridView dtVDs;
        private System.Windows.Forms.Button btDat;
        private System.Windows.Forms.Button btQuay;
        private System.Windows.Forms.TextBox txtName;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.DataGridView dtgVdat;
        private System.Windows.Forms.Button btXoa;
        private System.Windows.Forms.Button button1;
    }
}