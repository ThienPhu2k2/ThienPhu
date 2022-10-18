package QuanLyThuVien;

import java.util.List;

public class TrongNuoc extends Book {
	
	public TrongNuoc(String maSo, String tieuDe, double gia, 
			String theLoai, int nxb, List<Author> listAuthor) {
		super(maSo, tieuDe, gia, theLoai, nxb, listAuthor);
	}

	@Override
	public String toString() {
		return super.toString();
	}

	@Override
	public boolean kiemTraSach(String keyAuthor) {
		return false;
	}

	@Override
	public boolean check() {
		return true;
	}

}
