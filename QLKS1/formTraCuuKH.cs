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
using OfficeOpenXml;
using LicenseContext = OfficeOpenXml.LicenseContext;
using OfficeOpenXml.Style;
using System.IO;

namespace QLKS1
{
    public partial class formTraCuuKH : Form
    {
        public formTraCuuKH()
        {
            InitializeComponent();
        }

        private string idnv;
        SqlConnection con;
        public formTraCuuKH(string idnv)
        {
            InitializeComponent();
            this.idnv = idnv;
        }

        public void Hienthi()
        {
            string sqlSelect = "SELECT * FROM Khachhang";
            SqlCommand cmd = new SqlCommand(sqlSelect, con);
            SqlDataReader dr = cmd.ExecuteReader();
            DataTable dt = new DataTable();
            dt.Load(dr);
            dgvKhachhang.DataSource = dt;
        }

        private void txtCCCD_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!Char.IsDigit(e.KeyChar) && !Char.IsControl(e.KeyChar))
                e.Handled = true;
        }

        private void btnThoat_Click(object sender, EventArgs e)
        {
            this.Hide();
            new formLeTan(idnv).ShowDialog();
            this.Close();
        }

        private void formTraCuuKH_Load(object sender, EventArgs e)
        {
            con = new SqlConnection(@"Data Source=DESKTOP-VO4Q3H8\PHU;Initial Catalog=QLKS;Integrated Security=True");
            con.Open();
            SqlCommand cmd = new SqlCommand("select hoten from Khachhang", con);
            SqlDataReader readerdr = cmd.ExecuteReader();
            while (readerdr.Read())
            {
                cmbKH.Items.Add(readerdr.GetValue(0).ToString());
            }
            readerdr.Close();
            cmd.Dispose();
            Hienthi();
        }
        private void formTraCuuKH_FormClosing(object sender, FormClosingEventArgs e)
        {
            con.Close();
        }

        private void btnTraCuu_Click(object sender, EventArgs e)
        {
            if(cmbKH.SelectedItem == null)
            {
                MessageBox.Show("Không tồn tại khách hàng này !", "Thông báo");
            }
        }
        private void button1_Click(object sender, EventArgs e)
        {
            Hienthi();
        }

        private void cmbKH_SelectedIndexChanged(object sender, EventArgs e)
        {
            string sqlTracuu = "SELECT * FROM Khachhang WHERE hoten = @hoten";
            SqlCommand cmd = new SqlCommand(sqlTracuu, con);
            cmd.Parameters.AddWithValue("hoten", cmbKH.Text);
            cmd.ExecuteNonQuery();
            SqlDataReader dr = cmd.ExecuteReader();
            DataTable dt = new DataTable();
            dt.Load(dr);
            dgvKhachhang.DataSource = dt;
            if(dgvKhachhang.Rows.Count != 0 && cmbKH.SelectedItem != null)
            { 
                txtCCCD.Text = dgvKhachhang.Rows[0].Cells[5].Value.ToString();
            }
        }

        private void btnXuat_Click(object sender, EventArgs e)
        {
            string sqlSelect = "SELECT * FROM Khachhang";
            SqlCommand cmd = new SqlCommand(sqlSelect, con);
            SqlDataReader dr = cmd.ExecuteReader();
            DataTable dt = new DataTable();
            dt.Load(dr);
            string filePath = "";
            fileExcel = new SaveFileDialog();
            fileExcel.Filter = "Excel | *.xlsx | Excel 2003 | *.xls";
            if (fileExcel.ShowDialog() == DialogResult.OK)
            {
                filePath = fileExcel.FileName;
            }
            if (string.IsNullOrEmpty(filePath))
            {
                MessageBox.Show("Đường dẫn không hợp lệ");
                return;
            }
            ExcelPackage.LicenseContext = LicenseContext.NonCommercial;
            using (ExcelPackage p = new ExcelPackage())
            {
                // đặt tên người tạo file
                p.Workbook.Properties.Author = "Phu";

                // đặt tiêu đề cho file
                p.Workbook.Properties.Title = "Unknows";

                //Tạo một sheet để làm việc trên đó
                p.Workbook.Worksheets.Add("Nhân Viên Sheet");

                // lấy sheet vừa add ra để thao tác
                ExcelWorksheet ws = p.Workbook.Worksheets[0];

                // đặt tên cho sheet
                ws.Name = "Nhân viên sheet";
                // fontsize mặc định cho cả sheet
                ws.Cells.Style.Font.Size = 11;
                // font family mặc định cho cả sheet
                ws.Cells.Style.Font.Name = "Calibri";
                // Tạo danh sách các column header
                string[] arrColumnHeader = { "Mã khách hàng", "Họ tên", "Giới tính", "Ngày sinh", "Địa chỉ", "CCCD", "SĐT" };
                // lấy ra số lượng cột cần dùng dựa vào số lượng header
                var countColHeader = arrColumnHeader.Count();

                // merge các column lại từ column 1 đến số column header
                // gán giá trị cho cell vừa merge là danh sach nhan vien khach san
                ws.Cells[1, 1].Value = "Danh Sách Khách Hàng";
                ws.Cells[1, 1].Style.Font.Size = 16;
                ws.Cells[1, 1].Style.Border.Top.Style =
                    ws.Cells[1, 1].Style.Border.Bottom.Style
                   = ws.Cells[1, 1].Style.Border.Right.Style
                  = ws.Cells[1, 1].Style.Border.Left.Style = ws.Cells[1, 1].Style.Border.Top.Style = ExcelBorderStyle.None;
                ws.Cells[1, 1, 1, countColHeader].Merge = true;
                // in đậm
                ws.Cells[1, 1, 1, countColHeader].Style.Font.Bold = true;
                // căn giữa
                ws.Cells[1, 1, 1, countColHeader].Style.HorizontalAlignment = ExcelHorizontalAlignment.Center;

                int colIndex = 1;
                int rowIndex = 2;
                for (int i = 1; i <= countColHeader; i++)
                {
                    ws.Column(i).Style.Border.Top.Style
                                    = ws.Column(i).Style.Border.Bottom.Style
                                    = ws.Column(i).Style.Border.Left.Style
                                    = ws.Column(i).Style.Border.Right.Style
                                    = ExcelBorderStyle.Thin;
                }
                //tạo các header từ column header đã tạo từ bên trên
                foreach (var item in arrColumnHeader)
                {
                    var cell = ws.Cells[rowIndex, colIndex];
                    //set màu thành gray
                    var fill = cell.Style.Fill;
                    fill.PatternType = ExcelFillStyle.Solid;
                    fill.BackgroundColor.SetColor(System.Drawing.Color.LightBlue);
                    cell.Style.HorizontalAlignment = ExcelHorizontalAlignment.Center;
                    //căn chỉnh các border
                    var border = cell.Style.Border;
                    border.Bottom.Style =
                        border.Top.Style =
                        border.Left.Style =
                        border.Right.Style = ExcelBorderStyle.Thin;

                    //gán giá trị
                    cell.Value = item;
                    colIndex++;
                }
                ws.Column(1).Width = 13.30;
                ws.Column(2).Width = 19;
                ws.Column(6).Width = 14;
                ws.Column(4).Width = 23;
                ws.Column(7).Width = 12;
                DataRow[] result = dt.Select();
                foreach (DataRow row in result)
                {
                    colIndex = 1;

                    // rowIndex tương ứng từng dòng dữ liệu
                    rowIndex++;

                    //gán giá trị cho từng cell                      
                    ws.Cells[rowIndex, colIndex++].Value = row[0];
                    ws.Cells[rowIndex, colIndex++].Value = row[1].ToString();
                    ws.Cells[rowIndex, colIndex++].Value = row[2];
                    ws.Cells[rowIndex, colIndex++].Value = row[3].ToString();
                    ws.Cells[rowIndex, colIndex++].Value = row[4];
                    ws.Cells[rowIndex, colIndex++].Value = row[5];
                    ws.Cells[rowIndex, colIndex++].Value = row[6];


                }
                //Lưu file lại
                Byte[] bin = p.GetAsByteArray();
                File.WriteAllBytes(filePath, bin);
            }
            MessageBox.Show("Xuất Excel thành công!", "Thông báo");
        }
    }
}
