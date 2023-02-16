namespace QLKS1
{
    partial class formTraCuuKH
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(formTraCuuKH));
            this.txtCCCD = new System.Windows.Forms.TextBox();
            this.btnTraCuu = new System.Windows.Forms.Button();
            this.btnThoat = new System.Windows.Forms.Button();
            this.lblCCCD = new System.Windows.Forms.Label();
            this.lblSDT = new System.Windows.Forms.Label();
            this.dgvKhachhang = new System.Windows.Forms.DataGridView();
            this.makhachhangDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.hotenDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.gioitinhDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ngaysinhDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.diachiDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.cccdDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.sdtDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.khachhangBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.qLKSDataSet = new QLKS1.QLKSDataSet();
            this.khachhangTableAdapter = new QLKS1.QLKSDataSetTableAdapters.KhachhangTableAdapter();
            this.label1 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.cmbKH = new System.Windows.Forms.ComboBox();
            this.button1 = new System.Windows.Forms.Button();
            this.btnXuat = new System.Windows.Forms.Button();
            this.fileExcel = new System.Windows.Forms.SaveFileDialog();
            ((System.ComponentModel.ISupportInitialize)(this.dgvKhachhang)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.khachhangBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.qLKSDataSet)).BeginInit();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // txtCCCD
            // 
            this.txtCCCD.Enabled = false;
            this.txtCCCD.Font = new System.Drawing.Font("Microsoft Tai Le", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtCCCD.Location = new System.Drawing.Point(486, 31);
            this.txtCCCD.MaxLength = 12;
            this.txtCCCD.Multiline = true;
            this.txtCCCD.Name = "txtCCCD";
            this.txtCCCD.Size = new System.Drawing.Size(200, 30);
            this.txtCCCD.TabIndex = 8;
            this.txtCCCD.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.txtCCCD.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtCCCD_KeyPress);
            // 
            // btnTraCuu
            // 
            this.btnTraCuu.AutoSize = true;
            this.btnTraCuu.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnTraCuu.Image = ((System.Drawing.Image)(resources.GetObject("btnTraCuu.Image")));
            this.btnTraCuu.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnTraCuu.Location = new System.Drawing.Point(746, 24);
            this.btnTraCuu.Name = "btnTraCuu";
            this.btnTraCuu.Size = new System.Drawing.Size(115, 39);
            this.btnTraCuu.TabIndex = 5;
            this.btnTraCuu.Text = "Tra cứu";
            this.btnTraCuu.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnTraCuu.UseVisualStyleBackColor = true;
            this.btnTraCuu.Click += new System.EventHandler(this.btnTraCuu_Click);
            // 
            // btnThoat
            // 
            this.btnThoat.AutoSize = true;
            this.btnThoat.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnThoat.Image = ((System.Drawing.Image)(resources.GetObject("btnThoat.Image")));
            this.btnThoat.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnThoat.Location = new System.Drawing.Point(12, 500);
            this.btnThoat.Name = "btnThoat";
            this.btnThoat.Size = new System.Drawing.Size(115, 39);
            this.btnThoat.TabIndex = 6;
            this.btnThoat.Text = "Thoát";
            this.btnThoat.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnThoat.UseVisualStyleBackColor = true;
            this.btnThoat.Click += new System.EventHandler(this.btnThoat_Click);
            // 
            // lblCCCD
            // 
            this.lblCCCD.AutoSize = true;
            this.lblCCCD.Location = new System.Drawing.Point(410, 34);
            this.lblCCCD.Name = "lblCCCD";
            this.lblCCCD.Size = new System.Drawing.Size(66, 20);
            this.lblCCCD.TabIndex = 1;
            this.lblCCCD.Text = "CCCD:";
            // 
            // lblSDT
            // 
            this.lblSDT.AutoSize = true;
            this.lblSDT.Location = new System.Drawing.Point(29, 34);
            this.lblSDT.Name = "lblSDT";
            this.lblSDT.Size = new System.Drawing.Size(138, 20);
            this.lblSDT.TabIndex = 0;
            this.lblSDT.Text = "Tên khách hàng:";
            // 
            // dgvKhachhang
            // 
            this.dgvKhachhang.AutoGenerateColumns = false;
            this.dgvKhachhang.BackgroundColor = System.Drawing.SystemColors.Control;
            this.dgvKhachhang.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvKhachhang.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.makhachhangDataGridViewTextBoxColumn,
            this.hotenDataGridViewTextBoxColumn,
            this.gioitinhDataGridViewTextBoxColumn,
            this.ngaysinhDataGridViewTextBoxColumn,
            this.diachiDataGridViewTextBoxColumn,
            this.cccdDataGridViewTextBoxColumn,
            this.sdtDataGridViewTextBoxColumn});
            this.dgvKhachhang.DataSource = this.khachhangBindingSource;
            this.dgvKhachhang.Location = new System.Drawing.Point(12, 149);
            this.dgvKhachhang.Name = "dgvKhachhang";
            this.dgvKhachhang.RowHeadersWidth = 51;
            this.dgvKhachhang.RowTemplate.Height = 24;
            this.dgvKhachhang.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dgvKhachhang.Size = new System.Drawing.Size(937, 344);
            this.dgvKhachhang.TabIndex = 2;
            // 
            // makhachhangDataGridViewTextBoxColumn
            // 
            this.makhachhangDataGridViewTextBoxColumn.DataPropertyName = "makhachhang";
            this.makhachhangDataGridViewTextBoxColumn.HeaderText = "Mã khách hàng";
            this.makhachhangDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.makhachhangDataGridViewTextBoxColumn.Name = "makhachhangDataGridViewTextBoxColumn";
            this.makhachhangDataGridViewTextBoxColumn.Width = 125;
            // 
            // hotenDataGridViewTextBoxColumn
            // 
            this.hotenDataGridViewTextBoxColumn.DataPropertyName = "hoten";
            this.hotenDataGridViewTextBoxColumn.HeaderText = "Họ tên";
            this.hotenDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.hotenDataGridViewTextBoxColumn.Name = "hotenDataGridViewTextBoxColumn";
            this.hotenDataGridViewTextBoxColumn.Width = 125;
            // 
            // gioitinhDataGridViewTextBoxColumn
            // 
            this.gioitinhDataGridViewTextBoxColumn.DataPropertyName = "gioitinh";
            this.gioitinhDataGridViewTextBoxColumn.HeaderText = "Giới tính";
            this.gioitinhDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.gioitinhDataGridViewTextBoxColumn.Name = "gioitinhDataGridViewTextBoxColumn";
            this.gioitinhDataGridViewTextBoxColumn.Width = 125;
            // 
            // ngaysinhDataGridViewTextBoxColumn
            // 
            this.ngaysinhDataGridViewTextBoxColumn.DataPropertyName = "ngaysinh";
            this.ngaysinhDataGridViewTextBoxColumn.HeaderText = "Ngày sinh";
            this.ngaysinhDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.ngaysinhDataGridViewTextBoxColumn.Name = "ngaysinhDataGridViewTextBoxColumn";
            this.ngaysinhDataGridViewTextBoxColumn.Width = 125;
            // 
            // diachiDataGridViewTextBoxColumn
            // 
            this.diachiDataGridViewTextBoxColumn.DataPropertyName = "diachi";
            this.diachiDataGridViewTextBoxColumn.HeaderText = "Địa chỉ";
            this.diachiDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.diachiDataGridViewTextBoxColumn.Name = "diachiDataGridViewTextBoxColumn";
            this.diachiDataGridViewTextBoxColumn.Width = 125;
            // 
            // cccdDataGridViewTextBoxColumn
            // 
            this.cccdDataGridViewTextBoxColumn.DataPropertyName = "cccd";
            this.cccdDataGridViewTextBoxColumn.HeaderText = "CCCD";
            this.cccdDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.cccdDataGridViewTextBoxColumn.Name = "cccdDataGridViewTextBoxColumn";
            this.cccdDataGridViewTextBoxColumn.Width = 125;
            // 
            // sdtDataGridViewTextBoxColumn
            // 
            this.sdtDataGridViewTextBoxColumn.DataPropertyName = "sdt";
            this.sdtDataGridViewTextBoxColumn.HeaderText = "SĐT";
            this.sdtDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.sdtDataGridViewTextBoxColumn.Name = "sdtDataGridViewTextBoxColumn";
            this.sdtDataGridViewTextBoxColumn.Width = 125;
            // 
            // khachhangBindingSource
            // 
            this.khachhangBindingSource.DataMember = "Khachhang";
            this.khachhangBindingSource.DataSource = this.qLKSDataSet;
            // 
            // qLKSDataSet
            // 
            this.qLKSDataSet.DataSetName = "QLKSDataSet";
            this.qLKSDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // khachhangTableAdapter
            // 
            this.khachhangTableAdapter.ClearBeforeFill = true;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.DarkCyan;
            this.label1.Font = new System.Drawing.Font("Tempus Sans ITC", 19.8F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.Yellow;
            this.label1.Location = new System.Drawing.Point(256, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(492, 43);
            this.label1.TabIndex = 4;
            this.label1.Text = "Danh sách thông tin khách hàng";
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.Bisque;
            this.panel1.Controls.Add(this.cmbKH);
            this.panel1.Controls.Add(this.button1);
            this.panel1.Controls.Add(this.lblSDT);
            this.panel1.Controls.Add(this.btnTraCuu);
            this.panel1.Controls.Add(this.lblCCCD);
            this.panel1.Controls.Add(this.txtCCCD);
            this.panel1.Font = new System.Drawing.Font("Times New Roman", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.panel1.Location = new System.Drawing.Point(-24, 55);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1013, 88);
            this.panel1.TabIndex = 9;
            // 
            // cmbKH
            // 
            this.cmbKH.AutoCompleteMode = System.Windows.Forms.AutoCompleteMode.Append;
            this.cmbKH.AutoCompleteSource = System.Windows.Forms.AutoCompleteSource.ListItems;
            this.cmbKH.FormattingEnabled = true;
            this.cmbKH.Location = new System.Drawing.Point(171, 31);
            this.cmbKH.Name = "cmbKH";
            this.cmbKH.Size = new System.Drawing.Size(200, 28);
            this.cmbKH.TabIndex = 10;
            this.cmbKH.SelectedIndexChanged += new System.EventHandler(this.cmbKH_SelectedIndexChanged);
            // 
            // button1
            // 
            this.button1.AutoSize = true;
            this.button1.Cursor = System.Windows.Forms.Cursors.Hand;
            this.button1.Image = ((System.Drawing.Image)(resources.GetObject("button1.Image")));
            this.button1.Location = new System.Drawing.Point(915, 24);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(48, 38);
            this.button1.TabIndex = 9;
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // btnXuat
            // 
            this.btnXuat.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnXuat.Location = new System.Drawing.Point(834, 500);
            this.btnXuat.Name = "btnXuat";
            this.btnXuat.Size = new System.Drawing.Size(115, 39);
            this.btnXuat.TabIndex = 10;
            this.btnXuat.Text = "File Excel";
            this.btnXuat.UseVisualStyleBackColor = true;
            this.btnXuat.Click += new System.EventHandler(this.btnXuat_Click);
            // 
            // formTraCuuKH
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.BackColor = System.Drawing.Color.Linen;
            this.ClientSize = new System.Drawing.Size(964, 556);
            this.Controls.Add(this.btnXuat);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.btnThoat);
            this.Controls.Add(this.dgvKhachhang);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "formTraCuuKH";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "formTraCuuKH";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.formTraCuuKH_FormClosing);
            this.Load += new System.EventHandler(this.formTraCuuKH_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dgvKhachhang)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.khachhangBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.qLKSDataSet)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.TextBox txtCCCD;
        private System.Windows.Forms.Button btnThoat;
        private System.Windows.Forms.Button btnTraCuu;
        private System.Windows.Forms.Label lblCCCD;
        private System.Windows.Forms.Label lblSDT;
        private System.Windows.Forms.DataGridView dgvKhachhang;
        private QLKSDataSet qLKSDataSet;
        private System.Windows.Forms.BindingSource khachhangBindingSource;
        private QLKSDataSetTableAdapters.KhachhangTableAdapter khachhangTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn makhachhangDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn hotenDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn gioitinhDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn ngaysinhDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn diachiDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn cccdDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn sdtDataGridViewTextBoxColumn;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.ComboBox cmbKH;
        private System.Windows.Forms.Button btnXuat;
        private System.Windows.Forms.SaveFileDialog fileExcel;
    }
}