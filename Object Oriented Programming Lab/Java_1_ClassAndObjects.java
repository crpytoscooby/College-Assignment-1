
import java.util.Scanner;
public class Java_1_ClassAndObjects {
	private
	int emp_id, leaves;
	float salary;
	String emp_name, emp_designation;

	public void getData() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter Employee Name: ");
		emp_name = sc.next();
		System.out.print("Enter Employee ID: ");
		emp_id = sc.nextInt();
		sc.nextLine();
		System.out.print("Enter Employee Designation: ");
		emp_designation = sc.nextLine();
	}

	public void getLeaves() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter Number of Leaves: ");
		leaves = sc.nextInt();
	}

	public void getSalary() {
		Scanner sc = new Scanner(System.in);
		float basic, da1, hra1;
		System.out.print("Enter Basic Salary: ");
		basic = sc.nextFloat();
		System.out.print("Enter DA: ");
		da1 = sc.nextFloat();
		System.out.print("Enter HRA: ");
		hra1 = sc.nextFloat();
		float da = (da1 * basic) / 100f;
		float hra = (hra1 * basic) / 100;
		salary = basic + da + hra;
	}

	public void display() {
		System.out.println("\n****EMPLOYEE DETAILS****");
		System.out.println("Employee Name: " + emp_name);
		System.out.println("Employee ID: " + emp_id);
		System.out.println("Employee Leaves: " + leaves);
		System.out.println("Total Salary of Employee: " + salary + " Rs");
	}

	public static void main(String[] args) {
		Java_1_ClassAndObjects obj = new Java_1_ClassAndObjects();
		obj.getData();
		obj.getLeaves();
		obj.getSalary();
		obj.display();
	}
}
