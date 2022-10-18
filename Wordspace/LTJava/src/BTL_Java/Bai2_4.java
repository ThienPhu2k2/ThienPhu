package BTL_Java;

public class Bai2_4 {
	
	// phan tu lon thu 2 o hang/cot dau tien
	public static void print2largest(int[][] arr) {
		int firstMax, secondMax;
		
		if(arr[0][0] > arr[0][1]) {
			firstMax = arr[0][0];
			secondMax = arr[0][1];
		}
		else {
			firstMax = arr[0][1];
			secondMax = arr[0][0];
		}
		
		for(int i = 0; i < arr[0].length; i++) {
			if(arr[0][i] >= firstMax) {
				secondMax = firstMax;
				firstMax = arr[0][i];
			} else if(arr[0][i] > secondMax)
				secondMax = arr[0][i];
		}
		for(int j = 0; j < arr.length; j++) {
			if(arr[j][0] > firstMax) {
				secondMax = firstMax;
				firstMax = arr[j][0];
			} else if(arr[j][0] > secondMax)
				secondMax = arr[j][0];
		}
		System.out.println("phan tu lon thu 2: " + secondMax);
	}
	
	// phan tu nhỏ nhat o bien
	public static void printMin(int[][] arr) {
		int min = arr[0][0];
		
		for(int i = 0; i < arr[0].length; i++) {
			if(min > arr[0][i])
				min = arr[0][i];
			else if(min > arr[arr.length - 1][i])
				min = arr[arr.length - 1][i];
		}
		
		for(int j = 0; j < arr.length; j++) {
			if(arr[j][0] < min)
				min = arr[j][0];
			else if(arr[j][arr.length - 1] < min)
				min = arr[j][arr.length - 1];
		}
		System.out.println("phan tu bien nho nhat = " + min);
	}
	
	// thay the phan tu bi thieu
	public static void changeElement(int[][] arr) {
		int max = arr[0][0];
		for(int i = 0; i < arr.length; i++) {
			if(max < arr[i][i])
				max = arr[i][i];
		}
		for(int i = 0; i < arr.length; i++) {
			if(arr[i][i] == -1)
				arr[i][i] = max;
		}
		
		for(int i = 0; i < arr.length; i++) {
			for(int j = 0; j < arr.length; j++) {
				System.out.print(arr[i][j] + " ");
			}
			System.out.println("");
		}
	}
	
	public static void main(String[] args) {
		int[][] arr =  {{-1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		for(int i = 0; i < arr.length; i++) {
			for(int j = 0; j < arr.length; j++) {
				System.out.print(arr[i][j] + " ");
			}
			System.out.println("");
		}
		
		// phan tu lon thu 2 o hang/cot dau tien
		print2largest(arr);
		
		// phan tu lon nhat o bien
		printMin(arr);
		
		// thay the phan tu bi thieu
		changeElement(arr);
	}
}
