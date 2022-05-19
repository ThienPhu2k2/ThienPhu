import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

public class BM {
	private String tenBM;
	private List<GV> dsGV;
	
	public BM() {
		dsGV = new ArrayList<GV>();
	}
	
	public BM(String tenBM, List<GV> dsGV) {
		this.tenBM = tenBM;
		this.dsGV = dsGV;
	}
	
	public String getTenBM() {
		return tenBM;
	}
	
	public void setTenBM(String tenBM) {
		this.tenBM = tenBM;
	}
	
	//Tong so giang vien co huu cua bo mon co nam sinh truoc 1990
	public int GVCH_1990() {
		int count = 0;
		for(int i = 0; i < dsGV.size(); i++) {
			if(dsGV.get(i).namSinh < 1990)
				count++;
		}
		return count;
	}
	
	//Giang vien co huu lon tuoi nhat
	public GV maxTuoiGVCH() {
		int minYear = dsGV.get(0).namSinh;
		int index = 0;
		for(int i = 1; i < dsGV.size(); i++) {
			if(dsGV.get(i).namSinh < minYear) {
				minYear = dsGV.get(i).namSinh;
				index = i;
			}
		}
		return dsGV.get(index);
	}
	
	
	//Tim giang vien cong tac o bo mon
	public List<GV> TimTheoTen() {
		String hoTen;
		List<GV> t = new ArrayList<GV>();
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap ho ten can tim: ");
		hoTen = sc.next();
		for(int i = 0; i < dsGV.size(); i++) {
			if(dsGV.get(i).hoTen == hoTen) {
				t.add(dsGV.get(i));
			}
		}
		return t;
	}
	
	//Lay ra danh sach giang vien thinh giang tu nam sinh
	public List<GV> TimTheoNS() {
		int namSinh;
		List<GV> t = new ArrayList<GV>();
		Scanner sc = new Scanner(System.in);
		System.out.println("Nhap nam can tim: ");
		namSinh = sc.nextInt();
		for(int i = 0; i < dsGV.size(); i++) {
			if(dsGV.get(i).laGVTG()) {
				if(dsGV.get(i).namSinh == namSinh) {
					t.add(dsGV.get(i));
				}
			}
		}
		return t;
	}
	//sap xep cac giang vien tang dan theo ho ten
	public void sortByYear() {
		Collections.sort(dsGV, new Comparator<GV>() {
			public int compare(GV a, GV b) {
				return b.getNamSinh() - a.getNamSinh();
			}
			});
		}
	
	//sap xep cac giang vien giam dan theo nam sinh
	public void sortByName() {
		Collections.sort(dsGV, new Comparator<GV>() {
			public int compare(GV a, GV b) {
				return a.getHoTen().compareTo(b.getHoTen());
			}
		});
		}
	//thong ke so luong giang vien cua bo mon theo nam sinh
	public Map<Integer, Integer> thongKeNamSinh(){
		Map<Integer, Integer> list = new HashMap<>();
		for(GV i : dsGV) {
			if( !list.containsKey(i.getNamSinh()) ) {
				list.put(i.getNamSinh(), 1);
			}
			else list.put(i.getNamSinh(), list.get(i.getNamSinh()) + 1);
		}
		return list;
	}
}
