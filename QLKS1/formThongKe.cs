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
    public partial class formThongKe : Form
    {
        SqlConnection cn = new SqlConnection();
        string ketnoi = @"Data Source=DESKTOP-VO4Q3H8\PHU;Initial Catalog=QLKS;Integrated Security=True";
        SqlDataAdapter da, ad;
        string SQL;
        DataTable dt, ht;

        SqlDataReader docdulieu;
        SqlCommand command, cmd;

        private void btquaylai_Click(object sender, EventArgs e)
        {
            this.Hide();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DialogResult result = MessageBox.Show("Bạn có muốn thoát?", "Confirm", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (result == DialogResult.Yes)
            {
                this.Close();
            }
            else if (result == DialogResult.No)
            {
                MessageBox.Show("Mời bạn tiếp tục sử dụng phần mềm");
            }
        }

        public formThongKe()
        {
            InitializeComponent();
        }

        private void formThongKe_Load(object sender, EventArgs e)
        {
            //Load chart hinh cot
            cn = new SqlConnection(ketnoi);
            SqlDataAdapter da = new SqlDataAdapter("select  MONTH(Hoadon.ngaylaphd) as Thang, Phong.giaphong*(DAY(Chitietthue.ngaytraphong) - DAY(Chitietthue.ngaylapphongthue))as TienPhong,sum(Dichvu.giadichvu) as TienDV,\r\n(Phong.giaphong*(DAY(Chitietthue.ngaytraphong) - DAY(Chitietthue.ngaylapphongthue))+sum(Dichvu.giadichvu)) as TongDoanhThu \r\nfrom  Hoadon inner join Chitietthue on Hoadon.mahoadon = Chitietthue.mahoadon \r\n             inner join Phong on chitietthue.maphong = Phong.maphong\r\n\t\t\t inner join Chitietdichvu on Hoadon.mahoadon=Chitietdichvu.mahoadon\r\n\t\t\t inner join Dichvu on Dichvu.madichvu=Chitietdichvu.madichvu\r\ngroup by  MONTH(Hoadon.ngaylaphd),Phong.giaphong*(DAY(Chitietthue.ngaytraphong) - DAY(Chitietthue.ngaylapphongthue))", cn);
            DataTable dt = new DataTable();
            da.Fill(dt);
            chart2.DataSource = dt;
            chart2.Series["TongDoanhThu"].XValueMember = "Thang";
            chart2.Series["TongDoanhThu"].YValueMembers = "TongDoanhThu";
            chart2.Series["DoanhThuPhong"].XValueMember = "Thang";
            chart2.Series["DoanhThuPhong"].YValueMembers = "TienPhong";
            chart2.Series["DoanhThuDichVu"].XValueMember = "Thang";
            chart2.Series["DoanhThuDichVu"].YValueMembers = "TienDV";

            //Load 3 label Doanh Thu
            cn.Open();
            SQL = "select  sum(Dichvu.giadichvu)as TongDV, (select sum(Phong.giaphong*(DAY(Chitietthue.ngaytraphong) - DAY(Chitietthue.ngaylapphongthue)))\r\nfrom Chitietthue inner join Phong on chitietthue.maphong = Phong.maphong) as TongPhong,\r\n(sum(Dichvu.giadichvu)) + (select sum(Phong.giaphong*(DAY(Chitietthue.ngaytraphong) - DAY(Chitietthue.ngaylapphongthue)))\r\nfrom Chitietthue inner join Phong on chitietthue.maphong = Phong.maphong) as TongDoanhThu\r\nfrom Dichvu inner join Chitietdichvu on Dichvu.madichvu=Chitietdichvu.madichvu inner join Hoadon on Hoadon.mahoadon=Chitietdichvu.mahoadon\r\n";
            command = new SqlCommand(SQL, cn);
            docdulieu = command.ExecuteReader();
            while (docdulieu.Read())
            {
                lbdtp.Text = docdulieu.GetValue(1).ToString();
                lbdtdv.Text = docdulieu.GetValue(0).ToString();
                lbdt.Text = docdulieu.GetValue(2).ToString();
            }
            docdulieu.Close();
            command.Dispose();
            cn.Close();


            //load chart hinh tron
            DataTable ht = new DataTable();
            cn.Open();
            SqlCommand cmd = new SqlCommand("select round( (select sum(Phong.giaphong*(DAY(Chitietthue.ngaytraphong) - DAY(Chitietthue.ngaylapphongthue)))\r\nfrom Chitietthue inner join Phong on chitietthue.maphong = Phong.maphong)  *100/\r\n\t( (sum(Dichvu.giadichvu)) + (select sum(Phong.giaphong*(DAY(Chitietthue.ngaytraphong) - DAY(Chitietthue.ngaylapphongthue)))\r\n\tfrom Chitietthue inner join Phong on chitietthue.maphong = Phong.maphong) ),2 )\r\nfrom Dichvu inner join Chitietdichvu on Dichvu.madichvu=Chitietdichvu.madichvu inner join Hoadon on Hoadon.mahoadon=Chitietdichvu.mahoadon\r\nunion\r\nselect round( sum(Dichvu.giadichvu)*100/( (sum(Dichvu.giadichvu)) + (select sum(Phong.giaphong*(DAY(Chitietthue.ngaytraphong) - DAY(Chitietthue.ngaylapphongthue)))\r\n\t\t\t\t\t\t\t\t\tfrom Chitietthue inner join Phong on chitietthue.maphong = Phong.maphong) ), 2 ) \r\nfrom Dichvu inner join Chitietdichvu on Dichvu.madichvu=Chitietdichvu.madichvu \r\n\t\t\tinner join Hoadon on Hoadon.mahoadon=Chitietdichvu.mahoadon\t\r\n\t\t\tleft join Chitietthue on Hoadon.mahoadon=Chitietthue.mahoadon\r\n\t\t\tleft join Phong on Phong.maphong=Chitietthue.maphong", cn);
            SqlDataAdapter ad = new SqlDataAdapter(cmd);
            ad.Fill(ht);
            cn.Close();
            string[] x = new string[ht.Rows.Count];
            int[] y = new int[ht.Rows.Count];
            for (int i = 0; i < ht.Rows.Count; i++)
            {
                x[i] = ht.Rows[i][0].ToString();
                y[i] = Convert.ToInt32(ht.Rows[i][0]);
            }
            chart1.Series[0].Points.DataBindXY(x, y);
            chart1.Series[0].Points[0].Color = Color.Orange;
            chart1.Series[0].Points[1].Color = Color.Blue;
        }
    }
}
