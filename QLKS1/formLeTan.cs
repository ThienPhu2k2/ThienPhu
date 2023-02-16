using QLKS1.QLKSDataSetTableAdapters;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Net.NetworkInformation;
using System.Xml.Linq;
using System.Windows.Media;

namespace QLKS1
{
    public partial class formLeTan : Form
    {

        public formLeTan()
        {
            InitializeComponent();
        }
        private string IdKh = "";
        private string IdNv = "";
        private string IdHd = "";
        public formLeTan(string IdNv)
        {
            InitializeComponent();
            this.IdNv = IdNv;
        }

        SqlConnection con;

        public void Hienthi()
        {
            string sqlSelect = "SELECT * FROM Khachhang";
            SqlCommand cmd = new SqlCommand(sqlSelect, con);
            SqlDataReader dr = cmd.ExecuteReader();
            DataTable dt = new DataTable();
            dt.Load(dr);
            dgvKhachHang.DataSource = dt;
        }

        public void Hienthi_1_Khachhang(string makh)
        {
            string sqlSelect = "SELECT * FROM Khachhang where makhachhang = @makhachhang";
            SqlCommand cmd = new SqlCommand(sqlSelect, con);
            cmd.Parameters.AddWithValue("makhachhang", makh);
            SqlDataReader dr = cmd.ExecuteReader();
            DataTable dt = new DataTable();
            dt.Load(dr);
            dgvKhachHang.DataSource = dt;
        }
        private void txtSDT_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!Char.IsDigit(e.KeyChar) && !Char.IsControl(e.KeyChar))
                e.Handled = true;
        }

        private void txtCCCD_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!Char.IsDigit(e.KeyChar) && !Char.IsControl(e.KeyChar))
                e.Handled = true;
        }

        private void txtTimKiem_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!Char.IsDigit(e.KeyChar) && !Char.IsControl(e.KeyChar))
                e.Handled = true;
        }

        private void formLeTan_Load(object sender, EventArgs e)
        {
            con = new SqlConnection(@"Data Source=DESKTOP-VO4Q3H8\PHU;Initial Catalog=QLKS;Integrated Security=True");
            con.Open();
            SqlCommand cmd = new SqlCommand("select * from Khachhang inner join Hoadon on Khachhang.makhachhang = Hoadon.makhachhang where Hoadon.thanhtien = 0", con);
            SqlDataReader readerdr = cmd.ExecuteReader();
            while (readerdr.Read())
            {
                cmbTimKiem.Items.Add(readerdr.GetValue(1).ToString());
            }
            readerdr.Close();
            cmd.Dispose();
            Hienthi();
        }
        private void formLeTan_FormClosing(object sender, FormClosingEventArgs e)
        {
            con.Close();
        }

        private void traCứuThôngTinKháchHàngToolStripMenuItem_Click(object sender, EventArgs e)
        {
            kháchHàngToolStripMenuItem.BackColor = ColorTranslator.FromHtml("255,255,255");
            phòngToolStripMenuItem.BackColor = ColorTranslator.FromHtml("255, 222, 89");
            thoátToolStripMenuItem.BackColor = ColorTranslator.FromHtml("255, 222, 89");
            formTraCuuKH form = new formTraCuuKH(IdNv);
            pnLT.Size = form.Size;
            pnLT.Controls.Clear();
            form.TopLevel = false;
            form.Dock = DockStyle.Fill;
            pnLT.Controls.Add(form);
            form.Show();
        }

        private void dgvKhachHang_Click(object sender, EventArgs e)
        {

        }


        private void dgvKhachHang_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if(e.RowIndex != -1)
            {
                DataGridViewRow dgvrow = dgvKhachHang.Rows[e.RowIndex];
                IdKh = txtMakhachhang.Text = dgvrow.Cells[0].Value.ToString();
                txtTen.Text = dgvrow.Cells[1].Value.ToString();
                dateTimePicker1.Text = dgvrow.Cells[3].Value.ToString();
                txtDiaChi.Text = dgvrow.Cells[4].Value.ToString();
                txtCCCD.Text = dgvrow.Cells[5].Value.ToString();
                txtSDT.Text = dgvrow.Cells[6].Value.ToString();
                if (dgvrow.Cells[2].Value.ToString() == "Nam")
                {
                    rbtnNam.Checked = true;
                }
                else
                {
                    rbtnNu.Checked = true;
                }
                SqlConnection cnn = new SqlConnection(@"Data Source=DESKTOP-VO4Q3H8\PHU;Initial Catalog=QLKS;Integrated Security=True");
                cnn.Open();
                SqlCommand cmd = new SqlCommand("select mahoadon from Hoadon where makhachhang = N'" + IdKh + "'", cnn);
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    IdHd = reader.GetValue(0).ToString();
                }
                cmd.Dispose();
                reader.Close();
                cnn.Close();
            }
        }

        private void btnThem_Click(object sender, EventArgs e)
        {
            if(txtSDT.TextLength < 10)
            {
                MessageBox.Show("Số điện thoại phải gồm 10 số");
            }
            else if(txtCCCD.TextLength < 12)
            {
                MessageBox.Show("Căn cước công dân phải gồm 12 số");
            }
            else
            {
                int count = 0;
                count = dgvKhachHang.Rows.Count;
                txtMakhachhang.Text = "KH" + count.ToString();
                string sqlThem = "INSERT INTO Khachhang VALUES (@makhachhang, @hoten, @gioitinh, @ngaysinh, @diachi, @cccd, @sdt)";
                SqlCommand cmd = new SqlCommand(sqlThem, con);
                cmd.Parameters.AddWithValue("makhachhang", txtMakhachhang.Text);
                cmd.Parameters.AddWithValue("hoten", txtTen.Text);
                if (rbtnNam.Checked == true)
                {
                    cmd.Parameters.AddWithValue("gioitinh", "Nam");
                }
                else if (rbtnNu.Checked == true)
                {
                    cmd.Parameters.AddWithValue("gioitinh", "Nữ");
                }
                cmd.Parameters.AddWithValue("ngaysinh", dateTimePicker1.Value.ToString("yyyy-MM-dd"));
                cmd.Parameters.AddWithValue("diachi", txtDiaChi.Text);
                cmd.Parameters.AddWithValue("cccd", txtCCCD.Text);
                cmd.Parameters.AddWithValue("sdt", txtSDT.Text);
                cmd.ExecuteNonQuery();
                Hienthi_1_Khachhang(txtMakhachhang.Text);
            }
        }

        private void btnXoa_Click(object sender, EventArgs e)
        {
            DialogResult dialog = MessageBox.Show("Bạn có chắc muốn xóa khách hàng này không ?", "Thông báo", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if(dialog == DialogResult.Yes)
            {
                string sqlXoa = "DELETE FROM Khachhang WHERE makhachhang = @makhachhang";
                SqlCommand cmd = new SqlCommand(sqlXoa, con);
                cmd.Parameters.AddWithValue("makhachhang", txtMakhachhang.Text);
                cmd.ExecuteNonQuery();
                Hienthi();
                txtMakhachhang.Clear();
                txtTen.Clear();
                rbtnNam.Checked = false;
                rbtnNu.Checked = false;
                txtDiaChi.Clear();
                txtSDT.Clear();
                txtCCCD.Clear();
            }
        }
        private void btnSua_Click(object sender, EventArgs e)
        {
            string sqlSua = "UPDATE Khachhang SET hoten = @hoten, gioitinh = @gioitinh, ngaysinh = @ngaysinh, diachi = @diachi, cccd = @cccd, sdt = @sdt WHERE makhachhang = @makhachhang";
            SqlCommand cmd = new SqlCommand(sqlSua, con);
            cmd.Parameters.AddWithValue("makhachhang", txtMakhachhang.Text);
            cmd.Parameters.AddWithValue("hoten", txtTen.Text);
            if (rbtnNam.Checked == true)
            {
                cmd.Parameters.AddWithValue("gioitinh", "Nam");
            }
            else if (rbtnNu.Checked == true)
            {
                cmd.Parameters.AddWithValue("gioitinh", "Nữ");
            }
            cmd.Parameters.AddWithValue("ngaysinh", dateTimePicker1.Value.ToString("yyyy-MM-dd"));
            cmd.Parameters.AddWithValue("diachi", txtDiaChi.Text);
            cmd.Parameters.AddWithValue("cccd", txtCCCD.Text);
            cmd.Parameters.AddWithValue("sdt", txtSDT.Text);
            cmd.ExecuteNonQuery();
            Hienthi_1_Khachhang(txtMakhachhang.Text);
        }

        private void btnLammoi_Click(object sender, EventArgs e)
        {
            txtMakhachhang.Clear();
            txtTen.Clear();
            rbtnNam.Checked = false;
            rbtnNu.Checked = false;
            txtDiaChi.Clear();
            txtSDT.Clear();
            txtCCCD.Clear();
            Hienthi();
        }

        private void phòngToolStripMenuItem_Click(object sender, EventArgs e)
        {
            kháchHàngToolStripMenuItem.BackColor = ColorTranslator.FromHtml("255, 222, 89");
            phòngToolStripMenuItem.BackColor = ColorTranslator.FromHtml("255,255,255");
            thoátToolStripMenuItem.BackColor = ColorTranslator.FromHtml("255, 222, 89");
            formDatPhong form = new formDatPhong(IdKh,IdNv);
            pnLT.Size = form.Size;
            pnLT.Controls.Clear();
            form.TopLevel = false;
            form.Dock = DockStyle.Fill;
            pnLT.Controls.Add(form);
            form.Show();
        }

        //Dich vu
        private void thoátToolStripMenuItem_Click_1(object sender, EventArgs e)
        {
            kháchHàngToolStripMenuItem.BackColor = ColorTranslator.FromHtml("255, 222, 89");
            phòngToolStripMenuItem.BackColor = ColorTranslator.FromHtml("255, 222, 89");
            thoátToolStripMenuItem.BackColor = ColorTranslator.FromHtml("255,255,255");
            new formDichVu(IdKh, IdHd).ShowDialog();
        }

        //Thoat
        private void thoátToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnTimKiem_Click(object sender, EventArgs e)
        {
            if(txtTimKiem.Text.Length == 12)
            {
                string sqlTracuu = "SELECT * FROM Khachhang WHERE cccd = @cccd";
                SqlCommand cmd = new SqlCommand(sqlTracuu, con);
                cmd.Parameters.AddWithValue("cccd", txtTimKiem.Text);
                cmd.ExecuteNonQuery();
                SqlDataReader dr = cmd.ExecuteReader();
                DataTable dt = new DataTable();
                dt.Load(dr);
                dgvKhachHang.DataSource = dt;
            }
            else
            {
                MessageBox.Show("CCCD phải đủ gồm 12 số");
            }

        }

        private void cmbTimKiem_SelectedIndexChanged(object sender, EventArgs e)
        {
            string sqlTracuu = "SELECT * FROM Khachhang WHERE hoten = @hoten";
            SqlCommand cmd = new SqlCommand(sqlTracuu, con);
            cmd.Parameters.AddWithValue("hoten", cmbTimKiem.Text);
            cmd.ExecuteNonQuery();
            SqlDataReader dr = cmd.ExecuteReader();
            DataTable dt = new DataTable();
            dt.Load(dr);
            dgvKhachHang.DataSource = dt;
        }

        private void kháchHàngToolStripMenuItem_Click(object sender, EventArgs e)
        {
        }
    }
}
