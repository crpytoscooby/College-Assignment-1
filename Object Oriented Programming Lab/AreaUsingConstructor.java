
import java.util.Scanner;
public class AreaUsingConstructor {

	int length, breadth;
	AreaUsingConstructor() {
		length = 0;
		breadth = 0;
		System.out.println("Default");
	}

	AreaUsingConstructor(int length, int breadth) {
		this.length = length;
		this.breadth = breadth;
	}

	void Area() {
		int area = length * breadth;
		System.out.println("Area = " + area);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter Length: ");
		int l = sc.nextInt();
		System.out.print("Enter Breadth: ");
		int b = sc.nextInt();
		AreaUsingConstructor obj = new AreaUsingConstructor();
		AreaUsingConstructor obj1 = new AreaUsingConstructor(l, b);
		obj1.Area();
		sc.close();
	}

}
