import java.util.Scanner;

class StudentsMI
{
	Scanner sc = new Scanner(System.in);
	int rollno;
	String name;
	public
		void test()
		{
			System.out.println("From Class Students");
		}
		void getdata()
		{
			System.out.print("Enter Name: ");
			name = sc.nextLine();
			System.out.print("Enter Roll No: ");
			rollno = sc.nextInt();
		}
	
		void display()
		{
			System.out.println("Name: " + name);
			System.out.println("Roll No: " + rollno);
		}
}

class MarksMI extends StudentsMI
{
	Scanner sc = new Scanner(System.in);
	int mark;
	public
		void test()
		{
			super.test();
			System.out.println("From Class Marks");
		}
		public void getdata()
		{
			super.getdata();
			System.out.print("Enter Total Mark: ");
			mark = sc.nextInt();
		}
		
		void display()
		{
			super.display();
			System.out.println("Total Mark: " + mark);
		}
}

class SportsMI extends MarksMI
{
	Scanner sc = new Scanner(System.in);
	String grade;
	public
	void getdata()
	{
		super.getdata();
		System.out.print("Enter Grade: ");
		grade = sc.next();
	}

	void display()
	{
		super.display();
		System.out.println("Grade: " + grade);
	}
}
public class MultilevelInheritance {
	public static void main(String[] args) {
		SportsMI obj = new SportsMI();
		obj.getdata();
		obj.display();
		obj.test();
	}

}
