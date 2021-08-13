import java.util.Scanner;

class StudentsSI
{
	Scanner sc = new Scanner(System.in);
	int rollno;
	String name;
	public
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

class MarksSI extends StudentsSI
{
	Scanner sc = new Scanner(System.in);
	int mark;
	public
		void getdata()
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
public class SingleInheritance {

	public static void main(String[] args) {
		MarksSI obj = new MarksSI();
		obj.getdata();
		obj.display();
	}

}
