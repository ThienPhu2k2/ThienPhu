package QuanLyThuVien;

import java.util.List;

public abstract class Book {
	protected String maSo;
	protected String tieuDe;
	protected double gia;
	protected String theLoai;
	protected int nxb;
	protected List<Author> listAuthor;
	
	
	public Book() {
		super();
	}

	public Book(String maSo, String tieuDe, double gia, 
			String theLoai, int nxb, List<Author> listAuthor) {
		super();
		this.maSo = maSo;
		this.tieuDe = tieuDe;
		this.gia = gia;
		this.theLoai = theLoai;
		this.nxb = nxb;
		this.listAuthor = listAuthor;
	}

	public String getMaSo() {
		return maSo;
	}

	public void setMaSo(String maSo) {
		this.maSo = maSo;
	}

	public String getTieuDe() {
		return tieuDe;
	}

	public void setTieuDe(String tieuDe) {
		this.tieuDe = tieuDe;
	}

	public double getGia() {
		return gia;
	}

	public void setGia(double gia) {
		this.gia = gia;
	}

	public String getTheLoai() {
		return theLoai;
	}

	public void setTheLoai(String theLoai) {
		this.theLoai = theLoai;
	}

	public int getNxb() {
		return nxb;
	}

	public void setNxb(int nxb) {
		this.nxb = nxb;
	}
	
	public void addAuthor(Author author) {
		this.listAuthor.add(author);
	}
	
	public void addListAuthor() {
		this.listAuthor.addAll(listAuthor);
	}
	
	public List<Author> getListAuthor() {
		return listAuthor;
	}

	public void setListAuthor(List<Author> listAuthor) {
		this.listAuthor = listAuthor;
	}

	public String toString() {
		return "Mã số: " + maSo + ", Tiêu đề: " + tieuDe + ", $" + gia + ", Thể loại: " + theLoai
				+ ", Năm xuất bản: " + nxb;
	}
	
	// lay ra loai cua sach (trong nuoc, ngoai nuoc)
	// sach trong nuoc = true
	// sach ngoai nuoc = false
	public abstract boolean check();
	
	/* kiem tra sach co phai sach nuoc ngoai va co cung 
	   tac gia voi tac gia cho truoc */
	public abstract boolean kiemTraSach(String keyAuthor);
	
	// kiem tra 2 quyen sach co cung loai va cung tac gia hay khong
	public boolean sachCungLoai(Book book1, Book book2) {
		if(book1.check() && book2.check() || !book1.check() && !book2.check())
			return true;
		else
			return false;
	}
	
}
