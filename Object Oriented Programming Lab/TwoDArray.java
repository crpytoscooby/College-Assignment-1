
import java.util.Scanner;
public class TwoDArray {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x[][] = new int[2][2];
		System.out.println("Assigning the nos. to array");;
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 2; j++) {
				x[i][j] = sc.nextInt();
			}
		}
		
		System.out.println("displaying the nos. to array");
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 2; j++) {
				System.out.print(x[i][j] + " ");
			}
			System.out.println();
		}
	}

}
