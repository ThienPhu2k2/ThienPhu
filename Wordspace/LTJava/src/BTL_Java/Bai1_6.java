package BTL_Java;

import java.util.Scanner;

public class Bai1_6 {
	
	// Dem so ky tu thuong co trong mang
	public static int countKyTu(char[] c, int n) {
		int count = 0;
		for(int i = 0; i < n; i++) {
			if(c[i] < 'A' || c[i] > 'Z')
				count++;
		}
		return count;
	}
	
	// kiem tra ky tu cho truoc co trong mang hay khong 
	public static boolean check(char[] c, int n, char key) {
		if(key >= 'A' && key <= 'Z')
			key += 32;
		for(int i = 0; i < n; i++) {
			if(c[i] >= 'A' && c[i] <= 'Z')
				c[i] += 32;
			if(c[i] == key)
				return true;
		}	
		return false;
	}
	
	// lay ra nhung ky tu in hoa co trong mang
	public static char[] characterArray(char[] c, int n) {
		int count = 0;
		char[] arr = new char[n];
		for(int i = 0; i < n; i++) {
			if(c[i] >= 'A' && c[i] <= 'Z') {
				arr[count] = c[i];
				count++;
			}
		}
		return arr;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		char[] c = new char[n];
		for(int i = 0; i < n; i++) {
			c[i] = sc.next().charAt(0);
		}
		
		// Dem so ky tu thuong co trong mang
		System.out.println("So ky tu thuong = " + countKyTu(c, n));
		
		// lay ra nhung ky tu in hoa co trong mang
		System.out.println("Nhung ky tu in hoa trong mang:");
		char[] e = characterArray(c, n);
		for(int i = 0; i < e.length; i++) {
			System.out.print(e[i] + " ");
		}
		
		// kiem tra ky tu cho truoc co trong mang hay khong 
		System.out.println("\nNhap ky tu can kiem tra:");
		char key = sc.next().charAt(0);
		System.out.println(check(c, n, key));
		
		sc.close();
	}
}
