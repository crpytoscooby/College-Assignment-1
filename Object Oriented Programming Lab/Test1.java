import java.util.Scanner;
public class Test1 {
	
	public int factorial(int n) {
		if(n == 1 || n == 0)
			return 1;
		else
			return n*factorial(n-1);
	}

	public static void main(String[] args) {
		Test1 obj = new Test1();
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the Number you want to find the Factorial: ");
		int n = sc.nextInt();
		System.out.print("Factoial of " + n + " is " + obj.factorial(n));
		sc.close();
	}

}
