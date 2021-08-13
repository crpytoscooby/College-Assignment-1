
import java.util.Scanner;
public class Java_2_ArrayOfObjects {
	private
		String name, designation;
		int id, leaves;
	public
	Scanner sc = new Scanner(System.in);
		void getData()
		{
			System.out.print("Enter Employee Name: ");
			name = sc.nextLine();
			System.out.print("ENter Employee ID: ");
			id = sc.nextInt();
			sc.nextLine();
			System.out.print("Enter Designation of Employee: ");
			designation = sc.nextLine();
			System.out.print("Enter No. of Leaves: ");
			leaves = sc.nextInt();
		}
		
		void display()
		{
			System.out.println("\n****EMPLOYEE DETAILS****");
			System.out.println("Employee Name: " + name);
			System.out.println("Employee ID: " + id);
			System.out.println("Employee Designation: " + designation);
			System.out.println("No of Leaves: " + leaves +"\n");
		}
		
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter Number of Employee: ");
		int n = sc.nextInt();
		Java_2_ArrayOfObjects[] obj = new Java_2_ArrayOfObjects[n];
		for(int i = 0; i < n; i++)
		{
			obj[i] = new Java_2_ArrayOfObjects();
			obj[i].getData();
			obj[i].display();
		}
		sc.close();
	}

}
