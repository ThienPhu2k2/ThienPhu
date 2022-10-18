package QuanLyThuVien;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

public class Library {
	private String nameLb;
	private String Address;
	private List<Book> listBook;
	
	public Library() {
		super();
	}
	
	public Library(String nameLb, String address, List<Book> listBook) {
		super();
		this.nameLb = nameLb;
		Address = address;
		this.listBook = listBook;
	}

	public String getNameLb() {
		return nameLb;
	}
	
	public void setNameLb(String nameLb) {
		this.nameLb = nameLb;
	}
	
	public String getAddress() {
		return Address;
	}
	
	public void setAddress(String address) {
		Address = address;
	}
	
	public void addBook(Book book) {
		this.listBook.add(book);
	}
	
	public void addListBook() {
		this.listBook.addAll(listBook);
	}
	
	public List<Book> getListBook() {
		return listBook;
	}
	
	public void setListBook(List<Book> listBook) {
		this.listBook = listBook;
	}
	
	// tong so sach trong nuoc va co nam xuat ban = 2011
	public int sachTN_2011() {
		int count = 0;
		for(int i = 0; i < listBook.size(); i++) {
			if(listBook.get(i).check() && listBook.get(i).nxb == 2011)
				count++;
		}
		return count;
	}
	
	// quyen sach nuoc ngoai co nhieu tac gia nhat
	public Book maxBook() {
		int max = listBook.get(0).listAuthor.size();
		int index = 0;
		for(int i = 0; i < listBook.size(); i++) {
			if(listBook.get(i).listAuthor.size() > max) {
				max = listBook.get(i).listAuthor.size();
				index = i;
			}
		}
		return listBook.get(index);
	}
	
	// tim quyen sach co ten cho truoc
	public Book findByName(String keyBook) {
		int index = 0;
		for(int i = 0; i < listBook.size(); i++) {
			if(listBook.get(i).tieuDe == keyBook)
				index = i;
		}
		return listBook.get(index);
	}
	
	// danh sach cac quyen sach co ten tac gia va the loai cho truoc
	public void findListBook(String author, String theloai) {
		List<Book> book = new ArrayList<Book>();
		for(int i = 0; i < listBook.size(); i++) {
			if(listBook.get(i).theLoai == theloai) {
				for(int j = 0; j < listBook.get(i).listAuthor.size(); j++) {
					if(listBook.get(i).listAuthor.get(j).getName() == author) {
						book.add(listBook.get(i));
					}
				}
			}
		}
		if(book.size() != 0) {
			System.out.println("Danh sach cac quyen sach: ");
			for(int i = 0; i < book.size(); i++) {
				System.out.println(book.get(i).toString());
			}
		} else 
			System.out.println("Khong tim thay quyen sach nao...");
	}
	
	// sap xep cac quyen sach tang dan theo tieu de
	public void sortByTieuDe() {
		Collections.sort(listBook, new Comparator<Book>() {
			public int compare(Book b1, Book b2) {
				return b1.getTieuDe().compareTo(b2.getTieuDe());
			}
		});
	}
	
	//sap xep cac quyen sach giam dan theo nam xuat ban
	public void sortByNxb() {
		Collections.sort(listBook, new Comparator<Book>() {
			public int compare(Book b1, Book b2) {
				return b1.getNxb() - b2.getNxb();
			}
		});
	}
	
	// thong ke so luong sach cua chi nhanh thu vien theo nam xuat ban
	private void addElement(Map<Integer, Integer> map, int element) {
		if (map.containsKey(element)) {
            int count = map.get(element) + 1;
            map.put(element, count);
        } else {
            map.put(element, 1);
        }
	}

	public void thongKe() {
		Map<Integer, Integer> map = new TreeMap<Integer, Integer>();
		for(int i = 0; i < listBook.size(); i++) {
			addElement(map, listBook.get(i).nxb);
		}
		
		for(Integer key : map.keySet()) {
			System.out.printf("%d: %d.\n", key, map.get(key));
		}
	}
}





