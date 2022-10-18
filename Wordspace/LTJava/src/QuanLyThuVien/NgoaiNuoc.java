package QuanLyThuVien;

import java.util.List;

public class NgoaiNuoc extends Book {
	private String country;

	public NgoaiNuoc(String maSo, String tieuDe, double gia, 
			String theLoai, int nxb, List<Author> listAuthor, String country) {
		super(maSo, tieuDe, gia, theLoai, nxb, listAuthor);
		this.country = country;
	}
	
	public String getCountry() {
		return country;
	}

	public void setCountry(String country) {
		this.country = country;
	}

	@Override
	public String toString() {
		return super.toString() + ", Quốc gia: " + country;
	}

	@Override
	public boolean kiemTraSach(String keyAuthor) {
		for(int i = 0; i < listAuthor.size(); i++) {
			if(listAuthor.get(i).getName() == keyAuthor)
				return true;
		}
		return false;
	}

	@Override
	public boolean check() {
		return false;
	}

}
