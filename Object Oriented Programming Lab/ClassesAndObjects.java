
import java.util.Scanner;

class Area {
	private
	int length, breadth;
	public
	Area(int length, int breadth) {
		this.length = length;
		this.breadth = breadth;
	}

	void CalculateArea() {
		int area = length * breadth;
		System.out.println("The Area of Rectangle = " + (area) + " Units");
	}
}
public class ClassesAndObjects {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter Length: ");
		int l = sc.nextInt();
		System.out.print("Enter Breadth: ");
		int b = sc.nextInt();
		Area obj = new Area(l, b);
		obj.CalculateArea();
		sc.close();
	}

}
