using System;
using System.Collections.Generic;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Data.SqlTypes;
using System.Drawing;
using System.Linq;
using System.Net.NetworkInformation;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.TextBox;
using System.Xml.Linq;

namespace QLKS1
{
    public partial class formDatPhong : Form
    {
        private string idKh = "";
        private string idNv = "";
        private string nameKh = "";
        private DataTable table = new DataTable();
        private List<int> countHD = new List<int>();
        private string idHD = "HD";
        public formDatPhong()
        {
            InitializeComponent();
        }
        public formDatPhong(string idKh, string idNv)
        {
            InitializeComponent();
            this.idKh = idKh;
            this.idNv = idNv;
        }

        public int ConvertString(string str)
        {
            int answer = 0;
            string subStr = "";
            for (int i = 2; i < str.Length; i++)
            {
                subStr += str[i];
            }
            answer = subStr[0] - '0';
            if (subStr.Length > 1)
            {
                for (int i = 1; i < subStr.Length; i++)
                {
                    answer *= 10;
                    answer += (subStr[i] - '0');
                }
            }
            return answer;
        }

        private void formDatPhong_Load(object sender, EventArgs e)
        {
            txtIdNv.Text = this.idNv;
            txtIdKh.Text = this.idKh;
            table.Columns.Add("Mã phòng", typeof(string));
            table.Columns.Add("Loại phòng", typeof(string));
            table.Columns.Add("Giá phòng (VND)", typeof(Double));
            table.Columns.Add("Trạng thái", typeof(string));
            SqlConnection cnn = new SqlConnection(@"Data Source=DESKTOP-VO4Q3H8\PHU;Initial Catalog=QLKS;Integrated Security=True");
            cnn.Open();
            SqlCommand cmd = new SqlCommand("Select * from phong where tinhtrangphong = '" + "No" + "'", cnn);
            SqlDataReader reader = cmd.ExecuteReader();
            while (reader.Read())
            {
                DataRow row = table.NewRow();
                row["Mã phòng"] = (string)reader.GetValue(0);
                row["Loại phòng"] = (string)reader.GetValue(1);
                row["Giá phòng (VND)"] = (Double)reader.GetValue(2);
                row["Trạng thái"] = (string)reader.GetValue(3);
                table.Rows.Add(row);
            }
            reader.Close();
            cmd = new SqlCommand("select makhachhang, hoten from khachhang where makhachhang = '" + idKh + "'", cnn);
            reader = cmd.ExecuteReader();
            while (reader.Read())
            {
                nameKh = txtName.Text = reader.GetString(1);
                txtIdNv.Text = reader.GetString(0);
            }
            reader.Close();
            cmd = new SqlCommand("select mahoadon from hoadon", cnn);
            reader = cmd.ExecuteReader();
            while (reader.Read())
            {
                countHD.Add(ConvertString(reader.GetString(0)));
            }
            reader.Close();
            dtVDs.DataSource = table;
            countHD.Sort();
            int count = 1;
            while (countHD.Contains(count))
            {
                count++;
            }
            this.idHD += count;
            cmd = new SqlCommand("insert into hoadon values(N'" + idHD + "', N'" + null + "', '" + 0 + "','" + idKh + "', '" + idNv + "' )", cnn);
            SqlDataAdapter adapter = new SqlDataAdapter();
            adapter.InsertCommand = new SqlCommand("insert into hoadon values(N'" + idHD + "', N'" + null + "', '" + 0 + "','" + idKh + "', '" + idNv + "')", cnn);
            adapter.InsertCommand.ExecuteNonQuery();
            cmd.Dispose();
            cnn.Close();
        }

        private void btDoi_Click(object sender, EventArgs e)
        {
            table.Clear();
            SqlConnection cnn = new SqlConnection(@"Data Source=DESKTOP-VO4Q3H8\PHU;Initial Catalog=QLKS;Integrated Security=True");
            cnn.Open();
            SqlCommand cmd = new SqlCommand("Select * from phong where loaiphong = N'" + "Phòng đôi" + "'", cnn);
            SqlDataReader reader = cmd.ExecuteReader();
            while (reader.Read())
            {
                DataRow row = table.NewRow();
                row["Mã phòng"] = (string)reader.GetValue(0);
                row["Loại phòng"] = (string)reader.GetValue(1);
                row["Giá phòng (VND)"] = (Double)reader.GetValue(2);
                row["Trạng thái"] = (string)reader.GetValue(3);
                table.Rows.Add(row);
            }
            cmd.Dispose();
            reader.Close();
            cnn.Close();
            dtVDs.DataSource = table;
        }

        private void btDon_Click(object sender, EventArgs e)
        {
            table.Clear();
            SqlConnection cnn = new SqlConnection(@"Data Source=DESKTOP-VO4Q3H8\PHU;Initial Catalog=QLKS;Integrated Security=True");
            cnn.Open();
            SqlCommand cmd = new SqlCommand("Select * from phong where loaiphong = N'" + "Phòng đơn" + "'", cnn);
            SqlDataReader reader = cmd.ExecuteReader();
            while (reader.Read())
            {
                DataRow row = table.NewRow();
                row["Mã phòng"] = (string)reader.GetValue(0);
                row["Loại phòng"] = (string)reader.GetValue(1);
                row["Giá phòng (VND)"] = (Double)reader.GetValue(2);
                row["Trạng thái"] = (string)reader.GetValue(3);
                table.Rows.Add(row);
            }
            cmd.Dispose();
            reader.Close();
            cnn.Close();
            dtVDs.DataSource = table;
        }

        private void btLoad_Click(object sender, EventArgs e)
        {
            txtIdNv.Text = this.idNv;
            dateT.Value = DateTime.Now;
            table.Clear();
            SqlConnection cnn = new SqlConnection(@"Data Source=DESKTOP-VO4Q3H8\PHU;Initial Catalog=QLKS;Integrated Security=True");
            cnn.Open();
            SqlCommand cmd = new SqlCommand("Select * from phong where tinhtrangphong = N'" + "No" + "'", cnn);
            SqlDataReader reader = cmd.ExecuteReader();
            while (reader.Read())
            {
                DataRow row = table.NewRow();
                row["Mã phòng"] = (string)reader.GetValue(0);
                row["Loại phòng"] = (string)reader.GetValue(1);
                row["Giá phòng (VND)"] = (Double)reader.GetValue(2);
                row["Trạng thái"] = (string)reader.GetValue(3);
                table.Rows.Add(row);
            }
            reader.Close();
            cmd = new SqlCommand("select makhachhang, hoten from khachhang where makhachhang = '" + idKh + "'", cnn);
            reader = cmd.ExecuteReader();
            while (reader.Read())
            {
                txtName.Text = reader.GetString(1);
                txtIdKh.Text = reader.GetString(0);
            }
            cmd.Dispose();
            reader.Close();
            cnn.Close();
            dtVDs.DataSource = table;
        }

        private void btDat_Click(object sender, EventArgs e)
        {
            List<string> listRoom = new List<string>();
            if (dtVDs.SelectedRows.Count > 0)
            {
                SqlConnection cnn = new SqlConnection(@"Data Source=DESKTOP-VO4Q3H8\PHU;Initial Catalog=QLKS;Integrated Security=True");
                cnn.Open();
                SqlCommand cmd = new SqlCommand();
                for (int i = 0; i < dtVDs.SelectedRows.Count; i++)
                {
                    cmd = new SqlCommand("insert into chitietthue values (N'" + DateTime.Now.ToString("yyyy-MM-dd") + "', N'" + null + "', '" + idHD + "',N'"+ dtVDs.SelectedCells[i].Value.ToString() + "')", cnn);
                    SqlDataAdapter adapter = new SqlDataAdapter();
                    adapter.InsertCommand = new SqlCommand("insert into chitietthue values (N'" + DateTime.Now.ToString("yyyy-MM-dd") + "', N'" + null + "', '" + idHD + "',N'"+ dtVDs.SelectedCells[i].Value.ToString() + "')", cnn);
                    adapter.InsertCommand.ExecuteNonQuery();
                    cmd = new SqlCommand("update phong set tinhtrangphong = '" + "Yes" + "' where maphong = '" + dtVDs.SelectedCells[i].Value.ToString() + "'", cnn);
                    adapter.UpdateCommand = new SqlCommand("update phong set tinhtrangphong = '" + "Yes" + "' where maphong = '" + dtVDs.SelectedCells[i].Value.ToString() + "'", cnn);
                    adapter.UpdateCommand.ExecuteNonQuery();
                }
                table.Clear();
                cmd = new SqlCommand("Select * from phong where tinhtrangphong = '" + "No" + "'", cnn);
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    DataRow row = table.NewRow();
                    row["Mã phòng"] = (string)reader.GetValue(0);
                    row["Loại phòng"] = (string)reader.GetValue(1);
                    row["Giá phòng (VND)"] = (Double)reader.GetValue(2);
                    row["Trạng thái"] = (string)reader.GetValue(3);
                    table.Rows.Add(row);
                }
                reader.Close();
                DataTable tableDat = new DataTable();
                tableDat.Columns.Add("Số hóa đơn", typeof(string));
                tableDat.Columns.Add("Tên khách hàng", typeof(string));
                tableDat.Columns.Add("Mã phòng", typeof(string));
                tableDat.Columns.Add("Ngày thuê", typeof(DateTime));
                tableDat.Columns.Add("Ngày trả", typeof(DateTime));
                cmd = new SqlCommand("select * from chitietthue where mahoadon = '" + idHD + "'", cnn);
                reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    DataRow row = tableDat.NewRow();
                    row["Số hóa đơn"] = (string)reader.GetValue(2);
                    row["Tên khách hàng"] = this.nameKh;
                    row["Mã phòng"] = (string)reader.GetValue(3);
                    row["Ngày thuê"] = (DateTime)reader.GetValue(0);
                    row["Ngày trả"] = (DateTime)reader.GetValue(1);
                    tableDat.Rows.Add(row);
                }
                reader.Close();
                cmd.Dispose();
                cnn.Close();
                dtgVdat.DataSource = tableDat;
            }
        }

        private void btXoa_Click(object sender, EventArgs e)
        {
            string id = "";
            if (dtgVdat.SelectedRows.Count > 0)
            {
                foreach (DataGridViewRow row in dtgVdat.SelectedRows)
                {
                    id = row.Cells[1].Value.ToString();
                    SqlConnection cnn = new SqlConnection(@"Data Source=DESKTOP-VO4Q3H8\PHU;Initial Catalog=QLKS;Integrated Security=True");
                    cnn.Open();
                    SqlCommand cmd = new SqlCommand("delete from chitietthue where maphong = '" + id + "'", cnn);
                    SqlDataAdapter adapter = new SqlDataAdapter();
                    adapter.DeleteCommand = new SqlCommand("delete from chitietthue where maphong = '" + id + "'", cnn);
                    adapter.DeleteCommand.ExecuteNonQuery();
                    cmd = new SqlCommand("update phong set tinhtrangphong = N'" + "No" + "' where maphong = '" + id + "'", cnn);
                    adapter.UpdateCommand = new SqlCommand("update phong set tinhtrangphong = N'" + "No" + "' where maphong = '" + id + "'", cnn);
                    adapter.UpdateCommand.ExecuteNonQuery();
                    cmd.Dispose();
                    cnn.Close();
                }
            }
            if (id.Length == 0)
            {
                MessageBox.Show("Xóa không thành công !", "Thông báo");
            }
            else
            {
                MessageBox.Show("Xóa thành công !", "Thông báo");
            }
        }

        private void btQuay_Click(object sender, EventArgs e)
        {
            this.Hide();
            new formLeTan(idNv).ShowDialog();
            this.Close();
        }

        private void dtVDs_DoubleClick(object sender, EventArgs e)
        {
            List<string> listRoom = new List<string>();
            if (dtVDs.SelectedRows.Count > 0)
            {
                SqlConnection cnn = new SqlConnection(@"Data Source=DESKTOP-VO4Q3H8\PHU;Initial Catalog=QLKS;Integrated Security=True");
                cnn.Open();
                SqlCommand cmd = new SqlCommand();
                for (int i = 0; i < dtVDs.SelectedRows.Count; i++)
                {
                    cmd = new SqlCommand("insert into chitietthue values (N'" + DateTime.Now.ToString("yyyy-MM-dd") + "', N'" + null + "', '" + idHD + "',N'" + dtVDs.SelectedCells[i].Value.ToString() + "')", cnn);
                    SqlDataAdapter adapter = new SqlDataAdapter();
                    adapter.InsertCommand = new SqlCommand("insert into chitietthue values (N'" + DateTime.Now.ToString("yyyy-MM-dd") + "', N'" + null + "', '" + idHD + "',N'" + dtVDs.SelectedCells[i].Value.ToString() + "')", cnn);
                    adapter.InsertCommand.ExecuteNonQuery();
                    cmd = new SqlCommand("update phong set tinhtrangphong = '" + "Yes" + "' where maphong = '" + dtVDs.SelectedCells[i].Value.ToString() + "'", cnn);
                    adapter.UpdateCommand = new SqlCommand("update phong set tinhtrangphong = '" + "Yes" + "' where maphong = '" + dtVDs.SelectedCells[i].Value.ToString() + "'", cnn);
                    adapter.UpdateCommand.ExecuteNonQuery();
                }
                table.Clear();
                cmd = new SqlCommand("Select * from phong where tinhtrangphong = '" + "No" + "'", cnn);
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    DataRow row = table.NewRow();
                    row["Mã phòng"] = (string)reader.GetValue(0);
                    row["Loại phòng"] = (string)reader.GetValue(1);
                    row["Giá phòng (VND)"] = (Double)reader.GetValue(2);
                    row["Trạng thái"] = (string)reader.GetValue(3);
                    table.Rows.Add(row);
                }
                reader.Close();
                DataTable tableDat = new DataTable();
                tableDat.Columns.Add("Số hóa đơn", typeof(string));
                tableDat.Columns.Add("Tên khách hàng", typeof(string));
                tableDat.Columns.Add("Mã phòng", typeof(string));
                tableDat.Columns.Add("Ngày thuê", typeof(DateTime));
                tableDat.Columns.Add("Ngày trả", typeof(DateTime));
                cmd = new SqlCommand("select * from chitietthue where mahoadon = '" + idHD + "'", cnn);
                reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    DataRow row = tableDat.NewRow();
                    row["Số hóa đơn"] = (string)reader.GetValue(2);
                    row["Tên khách hàng"] = this.nameKh;
                    row["Mã phòng"] = (string)reader.GetValue(3);
                    row["Ngày thuê"] = (DateTime)reader.GetValue(0);
                    row["Ngày trả"] = (DateTime)reader.GetValue(1);
                    tableDat.Rows.Add(row);
                }
                reader.Close();
                cmd.Dispose();
                cnn.Close();
                dtgVdat.DataSource = tableDat;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            new formDichVu(idKh, idHD).ShowDialog();
        }
    }
}
