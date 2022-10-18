package QuanLyThuVien;

import java.util.ArrayList;

public class Main {
	public static void main(String[] args) {
		ArrayList<Author> author = new ArrayList<Author>();
		Author author1 = new Author("Tran Thien Phu", 2002);
		Author author2 = new Author("Nguyen Du", 1975);
		Author author3 = new Author("Huy Can", 1972);
		author.add(author1);
		author.add(author2);
		author.add(author3);
		
		ArrayList<Book> book = new ArrayList<Book>();
		Book book1 = new TrongNuoc("TTP001", "Family", 20.000, "Anime", 2000, author);
		Book book2 = new NgoaiNuoc("TTP002", "War", 45.000, "Anime", 1985, author, "Itali");
		Book book3 = new TrongNuoc("TTP003", "Romantic", 60.000, "Anime", 2020, author);
		book.add(book1);
		book.add(book2);
		book.add(book3);
		
		Library LB = new Library("Biên Hòa", "122 Đặng Đức Thuật", book);
		GUI myGui = new GUI(LB);
	}
}
