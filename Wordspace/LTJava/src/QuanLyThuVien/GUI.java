package QuanLyThuVien;

import java.awt.Component;
import java.util.ArrayList;

import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

public class GUI {
	JFrame f = new JFrame("DANH SÁCH SÁCH TRONG THƯ VIỆN");
	private Component table;

	public GUI(Library lb) {
		super();

		String colunm[] = { "MÃ SỐ", "TIÊU ĐỀ", "GIÁ", "THỂ LOẠI", "NĂM XUẤT BẢN", "TÁC GIẢ"};

		DefaultTableModel model = new DefaultTableModel(colunm, 0);
		JTable table = new JTable(model);
		table.setBounds(30, 40, 200, 300);
		for (int i = 0; i < lb.getListBook().size(); i++) {
					String row[] = {lb.getListBook().get(i).getMaSo(),
							lb.getListBook().get(i).getTieuDe(),
							String.valueOf(lb.getListBook().get(i).getGia()),
							lb.getListBook().get(i).getTheLoai(),
							String.valueOf(lb.getListBook().get(i).getNxb()),
							String.valueOf(lb.getListBook().get(i).getListAuthor()),
					};
					model.addRow(row);

			}
		JScrollPane book = new JScrollPane(table);
		f.add(book);
		f.setSize(1000, 500);
		f.setVisible(true);

	}
}
