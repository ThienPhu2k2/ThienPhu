import java.util.Date;
import java.util.List;

public class GVCH extends GV{
	private double heSoLuong;
	private int namCT;
	
	public GVCH() {
		
	}
	
	public GVCH(String maGV, String hoTen, int soNamCT, int namSinh, String trinhDo, List<MH> dsMH, double heSoLuong, int namCT) {
		super(maGV, hoTen, soNamCT, namSinh, trinhDo, dsMH);
		this.heSoLuong = heSoLuong;
		this.namCT = namCT;
	}

	public GVCH(double heSoLuong, int namCT) {
		this.heSoLuong = heSoLuong;
		this.namCT = namCT;
	}
	
	public double getHeSoLuong() {
		return heSoLuong;
	}
	
	public int getNamCT() {
		return namCT;
	}
	
	public void setHeSoLuong(double heSoLuong) {
		this.heSoLuong = heSoLuong;
	}
	
	public void setNamCT(int namCT) {
		this.namCT = namCT;
	}

	@Override
	public boolean CH_50() {
		Date curr = new Date(System.currentTimeMillis());
		if(curr.getYear() - namSinh > 50)
			return true;
		return false;
	}

	@Override
	public boolean laGVTG() {
		return false;
	}

	@Override
	public void display() {
		System.out.println(maGV + hoTen + " " + soNamCT + " " + namSinh + " " + trinhDo + " " + heSoLuong + " " + namCT);
		
	}
	
}
