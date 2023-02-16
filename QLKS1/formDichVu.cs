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
using System.Xml.Linq;

namespace QLKS1
{
    public partial class formDichVu : Form
    {
        public formDichVu()
        {
            InitializeComponent();
        }
        private string madvXoa = " ";
        private string mahdXoa = " ";
        private string madv = " ";
        private string idkh = " ";
        private string mahd = " ";
        DataTable dt = new DataTable();
        public formDichVu(string idkh, string mahd)
        {
            InitializeComponent();
            this.idkh = idkh;
            this.mahd = mahd;
        }
        public void Hienthi()
        {
            SqlConnection cnn = new SqlConnection(@"Data Source=DESKTOP-VO4Q3H8\PHU;Initial Catalog=QLKS;Integrated Security=True");
            cnn.Open();
            string sqlSelect = "SELECT * FROM chitietdichvu where mahoadon = N'" + mahd + "'";
            SqlCommand cmd = new SqlCommand(sqlSelect, cnn);
            SqlDataReader dr = cmd.ExecuteReader();
            DataTable dt = new DataTable();
            dt.Load(dr);
            dtDichvu.DataSource = dt;
        }

        private void formDichVu_Load(object sender, EventArgs e)
        {
            Hienthi();
            txtMakhachhang.Text = idkh;

            cbxLoaidichvu.Items.Add("Xông hơi");
            cbxLoaidichvu.Items.Add("Massage");
            cbxLoaidichvu.Items.Add("Tắm bể bơi");
            cbxLoaidichvu.Items.Add("Giặt ủi");

            SqlConnection cnn = new SqlConnection(@"Data Source=DESKTOP-VO4Q3H8\PHU;Initial Catalog=QLKS;Integrated Security=True");
            cnn.Open();
            SqlDataReader reader;
            SqlCommand cmd = new SqlCommand("select madichvu,tendichvu,giadichvu from dichvu where tendichvu = N'" + cbxLoaidichvu.Text + "'", cnn);
            reader = cmd.ExecuteReader();
            while (reader.Read())
            {
                txtGiadichvu.Text = reader.GetValue(2).ToString();
                cbxLoaidichvu.Items.Add(reader.GetValue(1).ToString() + " - " + reader.GetValue(0).ToString());
            }
            reader.Close();

            cmd = new SqlCommand("select hoten from khachhang where makhachhang = '" + idkh + "'", cnn);
            reader = cmd.ExecuteReader();
            while (reader.Read())
            {
                txtHotenkhachhang.Text = reader.GetValue(0).ToString();
            }
            reader.Close();
            cmd.Dispose();
            cnn.Close();
        }

        private void cbxLoaidichvu_SelectedIndexChanged(object sender, EventArgs e)
        {
            SqlConnection cnn = new SqlConnection(@"Data Source=DESKTOP-VO4Q3H8\PHU;Initial Catalog=QLKS;Integrated Security=True");
            cnn.Open();
            SqlCommand cmd = new SqlCommand("select giadichvu,madichvu from dichvu where tendichvu = N'" + cbxLoaidichvu.Text + "'", cnn);
            SqlDataReader reader = cmd.ExecuteReader();
            while (reader.Read())
            {
                txtGiadichvu.Text = reader.GetValue(0).ToString();
                madv = reader.GetValue(1).ToString();
            }
            reader.Close();
            cmd.Dispose();
            cnn.Close();
        }

        private void btDat_Click(object sender, EventArgs e)
        {
            SqlConnection cnn = new SqlConnection(@"Data Source=DESKTOP-VO4Q3H8\PHU;Initial Catalog=QLKS;Integrated Security=True");
            cnn.Open();
            string sqlThem = "INSERT INTO chitietdichvu VALUES (@ngaysudung,@madichvu,@mahoadon)";
            SqlCommand cmd = new SqlCommand(sqlThem, cnn);
            cmd.Parameters.AddWithValue("ngaysudung", DateTime.Now.ToString("yyyy-MM-dd"));
            cmd.Parameters.AddWithValue("madichvu", madv);
            cmd.Parameters.AddWithValue("mahoadon", mahd);
            cmd.ExecuteNonQuery();
            Hienthi();
            cmd.Dispose();
            cnn.Close();
        }

        private void btXoa_Click(object sender, EventArgs e)
        {
            DialogResult dialog = MessageBox.Show("Bạn có chắc muốn xóa ?", "Thông báo", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            SqlConnection cnn = new SqlConnection(@"Data Source=DESKTOP-VO4Q3H8\PHU;Initial Catalog=QLKS;Integrated Security=True");
            cnn.Open();
            string sqlXoa = "Delete from chitietdichvu where madichvu = @madichvu and mahoadon = @mahoadon";
            SqlCommand cmd = new SqlCommand(sqlXoa, cnn);
            cmd.Parameters.AddWithValue("madichvu", madvXoa);
            cmd.Parameters.AddWithValue("mahoadon", mahdXoa);
            cmd.ExecuteNonQuery();
            Hienthi();
            cmd.Dispose();
            cnn.Close();
        }

        private void dtDichvu_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex != -1)
            {
                DataGridViewRow dgv = dtDichvu.Rows[e.RowIndex];
                madvXoa = dgv.Cells[1].Value.ToString();
                mahdXoa = dgv.Cells[2].Value.ToString();
            }
        }

        private void btnDong_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}