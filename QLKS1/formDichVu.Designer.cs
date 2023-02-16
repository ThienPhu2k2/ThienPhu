namespace QLKS1
{
    partial class formDichVu
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
            this.txtGiadichvu = new System.Windows.Forms.TextBox();
            this.txtHotenkhachhang = new System.Windows.Forms.TextBox();
            this.txtMakhachhang = new System.Windows.Forms.TextBox();
            this.dtDichvu = new System.Windows.Forms.DataGridView();
            this.ngaysudungDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.madichvuDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.mahoadonDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.chitietdichvuBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.qLKSDataSet1 = new QLKS1.QLKSDataSet1();
            this.label5 = new System.Windows.Forms.Label();
            this.cbxLoaidichvu = new System.Windows.Forms.ComboBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.btXoa = new System.Windows.Forms.Button();
            this.btDat = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.chitietdichvuTableAdapter = new QLKS1.QLKSDataSet1TableAdapters.ChitietdichvuTableAdapter();
            this.btnDong = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dtDichvu)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.chitietdichvuBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.qLKSDataSet1)).BeginInit();
            this.SuspendLayout();
            // 
            // txtGiadichvu
            // 
            this.txtGiadichvu.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtGiadichvu.Location = new System.Drawing.Point(322, 224);
            this.txtGiadichvu.Margin = new System.Windows.Forms.Padding(4);
            this.txtGiadichvu.Name = "txtGiadichvu";
            this.txtGiadichvu.Size = new System.Drawing.Size(135, 26);
            this.txtGiadichvu.TabIndex = 28;
            // 
            // txtHotenkhachhang
            // 
            this.txtHotenkhachhang.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtHotenkhachhang.Location = new System.Drawing.Point(184, 129);
            this.txtHotenkhachhang.Margin = new System.Windows.Forms.Padding(4);
            this.txtHotenkhachhang.Name = "txtHotenkhachhang";
            this.txtHotenkhachhang.Size = new System.Drawing.Size(196, 26);
            this.txtHotenkhachhang.TabIndex = 26;
            // 
            // txtMakhachhang
            // 
            this.txtMakhachhang.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtMakhachhang.Location = new System.Drawing.Point(184, 74);
            this.txtMakhachhang.Margin = new System.Windows.Forms.Padding(4);
            this.txtMakhachhang.Name = "txtMakhachhang";
            this.txtMakhachhang.Size = new System.Drawing.Size(196, 26);
            this.txtMakhachhang.TabIndex = 25;
            // 
            // dtDichvu
            // 
            this.dtDichvu.AutoGenerateColumns = false;
            this.dtDichvu.BackgroundColor = System.Drawing.SystemColors.Control;
            this.dtDichvu.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dtDichvu.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.ngaysudungDataGridViewTextBoxColumn,
            this.madichvuDataGridViewTextBoxColumn,
            this.mahoadonDataGridViewTextBoxColumn});
            this.dtDichvu.DataSource = this.chitietdichvuBindingSource;
            this.dtDichvu.Location = new System.Drawing.Point(13, 310);
            this.dtDichvu.Margin = new System.Windows.Forms.Padding(4);
            this.dtDichvu.Name = "dtDichvu";
            this.dtDichvu.RowHeadersWidth = 51;
            this.dtDichvu.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dtDichvu.Size = new System.Drawing.Size(494, 234);
            this.dtDichvu.TabIndex = 24;
            this.dtDichvu.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dtDichvu_CellClick);
            // 
            // ngaysudungDataGridViewTextBoxColumn
            // 
            this.ngaysudungDataGridViewTextBoxColumn.DataPropertyName = "ngaysudung";
            this.ngaysudungDataGridViewTextBoxColumn.HeaderText = "Ngày sử dụng";
            this.ngaysudungDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.ngaysudungDataGridViewTextBoxColumn.Name = "ngaysudungDataGridViewTextBoxColumn";
            this.ngaysudungDataGridViewTextBoxColumn.Width = 125;
            // 
            // madichvuDataGridViewTextBoxColumn
            // 
            this.madichvuDataGridViewTextBoxColumn.DataPropertyName = "madichvu";
            this.madichvuDataGridViewTextBoxColumn.HeaderText = "Mã dịch vụ";
            this.madichvuDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.madichvuDataGridViewTextBoxColumn.Name = "madichvuDataGridViewTextBoxColumn";
            this.madichvuDataGridViewTextBoxColumn.Width = 125;
            // 
            // mahoadonDataGridViewTextBoxColumn
            // 
            this.mahoadonDataGridViewTextBoxColumn.DataPropertyName = "mahoadon";
            this.mahoadonDataGridViewTextBoxColumn.HeaderText = "Mã hóa đơn";
            this.mahoadonDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.mahoadonDataGridViewTextBoxColumn.Name = "mahoadonDataGridViewTextBoxColumn";
            this.mahoadonDataGridViewTextBoxColumn.Width = 125;
            // 
            // chitietdichvuBindingSource
            // 
            this.chitietdichvuBindingSource.DataMember = "Chitietdichvu";
            this.chitietdichvuBindingSource.DataSource = this.qLKSDataSet1;
            // 
            // qLKSDataSet1
            // 
            this.qLKSDataSet1.DataSetName = "QLKSDataSet1";
            this.qLKSDataSet1.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(318, 200);
            this.label5.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(98, 20);
            this.label5.TabIndex = 23;
            this.label5.Text = "Giá dịch vụ:";
            // 
            // cbxLoaidichvu
            // 
            this.cbxLoaidichvu.AutoCompleteMode = System.Windows.Forms.AutoCompleteMode.Append;
            this.cbxLoaidichvu.AutoCompleteSource = System.Windows.Forms.AutoCompleteSource.ListItems;
            this.cbxLoaidichvu.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cbxLoaidichvu.FormattingEnabled = true;
            this.cbxLoaidichvu.Location = new System.Drawing.Point(17, 224);
            this.cbxLoaidichvu.Margin = new System.Windows.Forms.Padding(4);
            this.cbxLoaidichvu.Name = "cbxLoaidichvu";
            this.cbxLoaidichvu.Size = new System.Drawing.Size(160, 28);
            this.cbxLoaidichvu.TabIndex = 22;
            this.cbxLoaidichvu.SelectedIndexChanged += new System.EventHandler(this.cbxLoaidichvu_SelectedIndexChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(13, 200);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(104, 20);
            this.label4.TabIndex = 21;
            this.label4.Text = "Loại dịch vụ:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(13, 135);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(154, 20);
            this.label3.TabIndex = 20;
            this.label3.Text = "Họ tên khách hàng:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(13, 80);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(127, 20);
            this.label2.TabIndex = 19;
            this.label2.Text = "Mã khách hàng:";
            // 
            // btXoa
            // 
            this.btXoa.Location = new System.Drawing.Point(203, 269);
            this.btXoa.Margin = new System.Windows.Forms.Padding(4);
            this.btXoa.Name = "btXoa";
            this.btXoa.Size = new System.Drawing.Size(100, 28);
            this.btXoa.TabIndex = 17;
            this.btXoa.Text = "Xoá";
            this.btXoa.UseVisualStyleBackColor = true;
            this.btXoa.Click += new System.EventHandler(this.btXoa_Click);
            // 
            // btDat
            // 
            this.btDat.Location = new System.Drawing.Point(17, 269);
            this.btDat.Margin = new System.Windows.Forms.Padding(4);
            this.btDat.Name = "btDat";
            this.btDat.Size = new System.Drawing.Size(100, 28);
            this.btDat.TabIndex = 16;
            this.btDat.Text = "Đặt ";
            this.btDat.UseVisualStyleBackColor = true;
            this.btDat.Click += new System.EventHandler(this.btDat_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.SystemColors.Control;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(137, 20);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(191, 24);
            this.label1.TabIndex = 15;
            this.label1.Text = "Dịch Vụ Khách Sạn";
            // 
            // chitietdichvuTableAdapter
            // 
            this.chitietdichvuTableAdapter.ClearBeforeFill = true;
            // 
            // btnDong
            // 
            this.btnDong.Location = new System.Drawing.Point(407, 269);
            this.btnDong.Margin = new System.Windows.Forms.Padding(4);
            this.btnDong.Name = "btnDong";
            this.btnDong.Size = new System.Drawing.Size(100, 28);
            this.btnDong.TabIndex = 29;
            this.btnDong.Text = "Đóng";
            this.btnDong.UseVisualStyleBackColor = true;
            this.btnDong.Click += new System.EventHandler(this.btnDong_Click);
            // 
            // formDichVu
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Linen;
            this.ClientSize = new System.Drawing.Size(534, 556);
            this.Controls.Add(this.btnDong);
            this.Controls.Add(this.txtGiadichvu);
            this.Controls.Add(this.txtHotenkhachhang);
            this.Controls.Add(this.txtMakhachhang);
            this.Controls.Add(this.dtDichvu);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.cbxLoaidichvu);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.btXoa);
            this.Controls.Add(this.btDat);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.Name = "formDichVu";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "formDichVu";
            this.Load += new System.EventHandler(this.formDichVu_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dtDichvu)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.chitietdichvuBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.qLKSDataSet1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtGiadichvu;
        private System.Windows.Forms.TextBox txtHotenkhachhang;
        private System.Windows.Forms.TextBox txtMakhachhang;
        private System.Windows.Forms.DataGridView dtDichvu;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ComboBox cbxLoaidichvu;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button btXoa;
        private System.Windows.Forms.Button btDat;
        private System.Windows.Forms.Label label1;
        private QLKSDataSet1 qLKSDataSet1;
        private System.Windows.Forms.BindingSource chitietdichvuBindingSource;
        private QLKSDataSet1TableAdapters.ChitietdichvuTableAdapter chitietdichvuTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn ngaysudungDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn madichvuDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn mahoadonDataGridViewTextBoxColumn;
        private System.Windows.Forms.Button btnDong;
    }
}