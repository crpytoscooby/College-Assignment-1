
import java.util.Scanner;
public class LabAssignment1 {
	float real, imaginary;
	LabAssignment1()
	{
		real = 0;
		imaginary = 0;
	}
	
	LabAssignment1(float real, float imaginary)
	{
		this.real = real;
		this.imaginary = imaginary;
	}
	
	void print()
	{
		if(imaginary>=0)
		{
			System.out.println(real + "+" + imaginary + "i");
		}
		else
		{
			System.out.println(real + "" + imaginary + "i");
		}
	}
	
	void Addition(LabAssignment1 o1, LabAssignment1 o2)	// Object as a Parameter
	{
		real = o1.real + o2.real;
		imaginary = o1.imaginary + o2.imaginary;
	}
	
	void Subtraction(LabAssignment1 o1, LabAssignment1 o2)// Object as a Parameter
	{
		real = o1.real - o2.real;
		imaginary = o1.imaginary - o2.imaginary;
	}
	
	void Multiplication(LabAssignment1 o1, LabAssignment1 o2)// Object as a Parameter
	{
		float a = o1.real*o2.real;
		float b = o1.real*o2.imaginary;
		float c = o1.imaginary*o2.real;
		float d = o1.imaginary*o2.imaginary;
		real = a - d;
		imaginary = b + c;
	}
	
	void Division(LabAssignment1 o1, LabAssignment1 o2)	// Object as a Parameter
	{
			float a = o1.real*o2.real;
			float b = o2.imaginary*o1.real;
			float c = o2.real*o1.imaginary;
			float d = o1.imaginary*o2.imaginary;
			float e = o2.real*o2.real;
			float f = o2.imaginary*o2.imaginary;
			real = (a+d)/(e+f);
			imaginary = (c-b)/(e+f);
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter Real and Imaginary Part of First Complex Number");
		int r1 = sc.nextInt(), i1 = sc.nextInt();
		System.out.println("Enter Real and Imaginary Part of Second Complex Number");
		int r2 = sc.nextInt(), i2 = sc.nextInt();
		LabAssignment1 obj1 = new LabAssignment1(r1,i1);
		LabAssignment1 obj2 = new LabAssignment1(r2,i2);
		LabAssignment1 obj3 = new LabAssignment1();
		System.out.println("Menu:-");
		System.out.println("1) Addition of two Complex Number");
		System.out.println("2) Subtract of two Complex Number");
		System.out.println("3) Multiplication of two Complex Number");
		System.out.println("4) Division of two Complex Number");
		System.out.println();
		System.out.print("Enter Your Choice:");
		int choice = sc.nextInt();
		sc.close();
		switch(choice) {
		case 1: 
			obj3.Addition(obj1, obj2);
			obj3.print();
			break;
		case 2:
			obj3.Subtraction(obj1, obj2);
			obj3.print();
			break;
		case 3: 
			obj3.Multiplication(obj1, obj2);
			obj3.print();
			break;
		case 4:
			if(obj2.real==0 || obj2.imaginary==0)
			{
				System.out.println("Real or Imaginary Number should not be Zero to perform this Operation !");
			}
			else
			{
				obj3.Division(obj1, obj2);
				obj3.print();
			}
			break;
		default: 
			System.out.println("Invalid Input");
			break;
		}
	}
}
