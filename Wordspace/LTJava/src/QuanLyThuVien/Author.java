package QuanLyThuVien;

public class Author {
	private String name;
	private int yob;
	
	public Author() {
		super();
	}
	
	public Author(String name, int yob) {
		super();
		this.name = name;
		this.yob = yob;
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public int getYob() {
		return yob;
	}
	
	public void setYob(int yob) {
		this.yob = yob;
	}
	
	public String toString() {
		return "Tên tác giả: " + name + " Năm sinh: " + yob;
	}
}
