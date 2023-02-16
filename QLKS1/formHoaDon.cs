
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace QLKS1
{
    public partial class formHoaDon : Form
    {
        private string IDnv;
        private string IDkh;
        private DataTable dt = new DataTable();
        public formHoaDon()
        {
            InitializeComponent();
        }
        public formHoaDon(string iDnv, string iDkh)
        {
            InitializeComponent();
            IDnv = iDnv;
            IDkh = iDkh;
        }

        private void formHoaDon_Load(object sender, EventArgs e)
        {
            DataTable dataTable= new DataTable();
            dataTable.Columns.Add("Mã hóa đơn", typeof(String));
            dataTable.Columns.Add("Mã dịch vụ", typeof(String));
            dataTable.Columns.Add("Tên dịch vụ", typeof(String));
            dataTable.Columns.Add("Ngày sử dụng", typeof(DateTime));
            SqlConnection cnn = new SqlConnection(@"Data Source=DESKTOP-VO4Q3H8\PHU;Initial Catalog=QLKS;Integrated Security=True");
            cnn.Open();
            SqlDataReader reader;
            SqlCommand cmd = new SqlCommand("select hoadon.mahoadon, chitietdichvu.madichvu, dichvu.tendichvu, ngaysudung, khachhang.hoten from Chitietdichvu, Dichvu, Hoadon, Khachhang where Chitietdichvu.madichvu = Dichvu.madichvu and Chitietdichvu.mahoadon = Hoadon.mahoadon and Hoadon.makhachhang = Khachhang.makhachhang and Khachhang.makhachhang = N'"+ this.IDkh +"' ", cnn);
            reader = cmd.ExecuteReader();
            while (reader.Read())
            {
                DataRow dr = dataTable.NewRow();
                dr["Mã hóa đơn"] = reader.GetValue(0).ToString();
                dr["Mã dịch vụ"] = reader.GetValue(1).ToString();
                dr["Tên dịch vụ"] = reader.GetValue(2).ToString();
                dr["Ngày sử dụng"] = (DateTime)reader.GetValue(3);
                txtKH.Text = reader.GetValue(4).ToString();
                dataTable.Rows.Add(dr);
            }
            reader.Close();
            dgvDichVu.DataSource = dataTable;

            dt.Columns.Add("Mã hóa đơn", typeof(String));
            dt.Columns.Add("Mã phòng", typeof(String));
            dt.Columns.Add("Ngày thuê phòng", typeof(DateTime));
            dt.Columns.Add("Ngày trả phòng", typeof(DateTime));
            cmd = new SqlCommand("select hoadon.mahoadon, maphong, ngaylapphongthue, ngaytraphong from Chitietthue, Hoadon, Khachhang where Chitietthue.mahoadon = Hoadon.mahoadon and Hoadon.makhachhang = Khachhang.makhachhang and Khachhang.makhachhang = N'"+ this.IDkh +"'", cnn);
            reader = cmd.ExecuteReader();
            while (reader.Read())
            {
                DataRow dr = dt.NewRow();
                dr["Mã hóa đơn"] = reader.GetValue(0).ToString();
                dr["Mã phòng"] = reader.GetValue(1).ToString();
                dr["Ngày thuê phòng"] = (DateTime)reader.GetValue(2);
                dr["Ngày trả phòng"] = (DateTime)reader.GetValue(3);
                dt.Rows.Add(dr);
            }
            reader.Close();
            dgvPhongThue.DataSource = dt;
            cmd = new SqlCommand("select manv, hoten from nhanvien where manv = N'" + IDnv + "'", cnn);
            reader = cmd.ExecuteReader();
            while (reader.Read()) 
            {
                txtNV.Text = reader.GetValue(1).ToString() +"-"+ reader.GetValue(0).ToString();
            }
            reader.Close();
            cmd.Dispose();
            cnn.Close();
        }

        private void dgvPhongThue_CellDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
            DialogResult dialog = MessageBox.Show("Bạn có chắc muốn trả phòng " + dgvPhongThue.SelectedRows[0].Cells[1].Value.ToString() + " ?", "Thông báo", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (dialog == DialogResult.Yes)
            {
                SqlConnection cnn = new SqlConnection(@"Data Source=DESKTOP-VO4Q3H8\PHU;Initial Catalog=QLKS;Integrated Security=True");
                cnn.Open();
                SqlCommand cmd = new SqlCommand("update chitietthue set ngaytraphong = '" + DateTime.Now.ToString("yyyy-MM-dd") + "' where maphong = N'"+ dgvPhongThue.SelectedRows[0].Cells[1].Value.ToString() + "'", cnn);
                SqlDataAdapter adapter = new SqlDataAdapter();
                adapter.UpdateCommand = new SqlCommand("update chitietthue set ngaytraphong = '" + DateTime.Now.ToString("yyyy-MM-dd") + "' where maphong = N'" + dgvPhongThue.SelectedRows[0].Cells[1].Value.ToString() + "'", cnn);
                adapter.UpdateCommand.ExecuteNonQuery();
                cmd.Dispose();
                cnn.Close();
            }
        }

        private void btnIn_Click(object sender, EventArgs e)
        {
            new formThongKe().ShowDialog();
        }
    }
}
