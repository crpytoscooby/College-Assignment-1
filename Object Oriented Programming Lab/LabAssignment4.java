
import java.util.Scanner;
abstract class Shape {
	protected double a;
	protected double b;
	abstract void getData();
	abstract double compute_area();
}

class Rectangle extends Shape {
	Scanner sc = new Scanner(System.in);
	
	void setLength(double length) {
		a = length;
	}
	
	double getLength() {
		return a;
	}
	
	void setBreadth(double breadth) {
		b = breadth;
	}
	
	double getBreadth() {
		return b;
	}
	
	void getData() {
		System.out.print("Enter Value of Length: ");
		double length = sc.nextDouble();
		setLength(length);
		System.out.print("Enter Value of Height: ");
		double breadth = sc.nextDouble();
		setBreadth(breadth);	
	}
	
	double compute_area() {
		return getLength() * getBreadth();
	}
}

class Triangle extends Shape {
	
	Scanner sc = new Scanner(System.in);
	
	void setBase(double base) {
		a = base;
	}
	
	double getBase() {
		return a;
	}
	
	void setHeight(double height) {
		b = height;
	}
	
	double getHeight() {
		return b;
	}
	
	void getData() {
		System.out.print("Enter Value of Base: ");
		double base = sc.nextDouble();
		setBase(base);
		System.out.print("Enter Value of Height: ");
		double height = sc.nextDouble();
		setHeight(height);
	}
	
	double compute_area() {
		return (getBase() * getHeight())/2;
	}
}

public class LabAssignment4 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int choice;
		do
		{
			System.out.println("Program to Calculate Area");
			System.out.println("1) Calculate Area of Rectangle");
			System.out.println("2) Calculate Area of Triangle");
			System.out.print("Enter Your Choice: ");
			choice = sc.nextInt();
			switch(choice) {
			case 1:
				Shape r = new Rectangle();
				r.getData();
				System.out.println("Area of Rectangle = " + r.compute_area());
				break;
			case 2:
				Shape t = new Triangle();
				t.getData();
				System.out.println("Area of Triangle = " + t.compute_area());
				break;
			default:
				System.out.println("Invalid input");
				break;
			}
			System.out.println("Do you want to continue? (Y = 1/n = 0)");
			choice = sc.nextInt();
		}while(choice == 1);
		sc.close();
	}

}

