import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public abstract class GV {
	protected String maGV, hoTen, trinhDo;
	protected int soNamCT;
	protected int namSinh;
	protected List<MH> dsMH;
	                     
	public GV() {
		dsMH = new ArrayList<MH>();
	}
	
	public GV(String maGV, String hoTen, int soNamCT, int namSinh, String trinhDo, List<MH> dsMH) {
		this.maGV = maGV;
		this.hoTen = hoTen;
		this.soNamCT = soNamCT;
		this.namSinh = namSinh;
		this.trinhDo = trinhDo;
		this.dsMH = dsMH;
	}
	
	public String getHoTen() {
		return hoTen;
	}
	
	public void setHoTen(String hoTen) {
		this.hoTen = hoTen;
	}
	
	public String getMaGV() {
		return maGV;
	}
	
	public void setMaGV(String maGV) {
		this.maGV = maGV;
	}
	
	public int getSoNamCT() {
		return soNamCT;
	}
	
	public void setSoNamCT(int soNamCT) {
		this.soNamCT = soNamCT;
	}
	
	public int getNamSinh() {
		return namSinh;
	}
	
	public void setNamSinh(int namSinh) {
		this.namSinh = namSinh;
	}
	
	public abstract void display();
	
	//Them mot Mon Hoc vao danh sach cac mon hoc
	public void addMH(List<MH> dsMH) {
		Scanner sc = new Scanner(System.in);
		String ten;
		int tc;
		System.out.print("Nhap ten MH: ");
		ten = sc.next();
		System.out.print("Nhap so TC: ");
		tc = sc.nextInt();
		MH a = new MH(ten, tc);
		dsMH.add(a);
	}
	//Kiem tra GVCH tren 50 tuoi
	public abstract boolean CH_50();   
	
	//Kiem tra co la Giang Vien Thinh Giang hay khong
	public abstract boolean laGVTG();
	
	//Kiem tra hai giang vien cung loai va nam cong tac
		public boolean GiangVienCungLoai(GV a) {
			if(this.laGVTG() && a.laGVTG() || !this.laGVTG() && !a.laGVTG()){
				if(this.soNamCT == a.soNamCT)
					return true;
				else return false;
			}
			return false;
		}
}