import java.util.Scanner;

public class SwitchCase {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a number : ");
		int n = sc.nextInt();
		sc.close();
		switch(n) {
			case 1 : System.out.println("One");
				break;
			case 2 : System.out.println("Two");
				break;
			case 3 : System.out.print("Three");
				break;
			default : System.out.print("Invalid Input");
				break;
		}

	}

}
