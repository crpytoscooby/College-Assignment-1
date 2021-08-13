
import java.util.*;
class Employee {
	private
	int emp_id, leaves;
	String name;
	float basic, salary;
	public
	void getData() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter Employee Name: ");
		name = sc.next();
		System.out.print("Enter Employee ID: ");
		emp_id = sc.nextInt();
		System.out.print("Enter Basic salary: ");
		basic = sc.nextFloat();
		System.out.print("Enter Total No. of leaves: ");
		leaves = sc.nextInt();
//		sc.close();
	}

	void salary() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter DA: ");
		float da1 = sc.nextFloat();
		System.out.print("Enter HRA: ");
		float hra1 = sc.nextFloat();
		float da = (da1 * basic) / 100f;
		float hra = (hra1 * basic) / 100;
		salary = basic + da + hra;
//		sc.close();
	}

	public void displayData() {
		System.out.println("\n****EMPLOYEE DETAILS****");
		System.out.println("Employee Name: " + name);
		System.out.println("Employee Id: " + emp_id);
		System.out.println("No. of Leaves: " + leaves);
		System.out.println("Basic Salary: " + basic);
		System.out.println("Final Salary: " + salary);
	}
}

public class EmployeeSalary {

	public static void main(String[] args) {
		Employee obj = new Employee();
		obj.getData();
		obj.salary();
		obj.displayData();
	}
}

