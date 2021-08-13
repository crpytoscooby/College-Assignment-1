
import java.util.Scanner;
class Employee {
	protected
	String hasEmp_name, Address, Mail_id;
	int Emp_id;
	String Mobile_no;
	public
	Scanner sc = new Scanner(System.in);
	void getData() {
		int flag = 0;
		System.out.print("Enter Employee Name: ");
		hasEmp_name = sc.nextLine();
		System.out.print("Enter Employee ID: ");
		Emp_id = sc.nextInt();
		sc.nextLine();
		System.out.print("Enter Employee Address: ");
		Address = sc.nextLine();

		do {	// checking of mail id ends with "@gmail.com"
			System.out.print("Enter Employee Mail ID: ");
			Mail_id = sc.nextLine();
			if (Mail_id.endsWith("@gmail.com")) {
				flag = 0;
			} else {
				System.out.println("Invalid Email ID");
				flag = 1;
			}
		} while (flag != 0);

		do {	// checking the number is valid or not when user inputs +91 or without it
			System.out.print("Enter Employee Mobile Number: ");
			Mobile_no = sc.next();
			if (Mobile_no.length() == 10 || (Mobile_no.length() == 13 && Mobile_no.startsWith("+91"))) {
				flag = 0;
			} else {
				System.out.println("Invalid Mobile Number");
				flag = 1;
			}
		} while (flag != 0);
	}
}

class Programmer extends Employee {
	protected
	int leaves;
	float basicPay, da, hra, pf, scf, gross, netSalary;
	public
	Scanner sc = new Scanner(System.in);

	void Salary() {
		System.out.print("Enter Number of Leaves: ");
		leaves = sc.nextInt();
		System.out.print("Enter Basic Salary: ");
		basicPay = sc.nextFloat();
		da = basicPay * 0.97f;
		hra = basicPay * 0.10f;
		pf = basicPay * 0.12f;
		scf = basicPay * 0.001f;
		gross = basicPay + da + hra + pf + scf;
		netSalary = gross - (leaves * 500);
	}

	void paySlip() {
		System.out.print("\nEmployee Details");
		System.out.print("\n============================================================");
		System.out.print("\nEmplyee Name: " + hasEmp_name);
		System.out.print("\nEnter Employee ID: " + Emp_id);
		System.out.print("\nEnter Employee Address: " + Address);
		System.out.print("\nEnter Employee Mail ID: " + Mail_id);
		System.out.print("\n============================================================");
		System.out.print("\nPaySlip");
		System.out.print("\n============================================================");
		System.out.print("\nBasic Pay       " + basicPay);
		System.out.print("\nDA              " + da);
		System.out.print("\nHRA             " + hra);
		System.out.print("\nGross Salary    " + gross);
		System.out.print("\nDeduction       " + leaves * 500f);
		System.out.print("\nNet Salary      " + netSalary);
		System.out.print("\n============================================================");
	}
}

class TeamLeader extends Employee {
	protected
	int leaves;
	float basicPay, da, hra, pf, scf, gross, netSalary;
	public
	Scanner sc = new Scanner(System.in);

	void Salary() {
		System.out.print("Enter Number of Leaves: ");
		leaves = sc.nextInt();
		System.out.print("Enter Basic Salary: ");
		basicPay = sc.nextFloat();
		da = basicPay * 0.97f;
		hra = basicPay * 0.10f;
		pf = basicPay * 0.12f;
		scf = basicPay * 0.001f;
		gross = basicPay + da + hra + pf + scf;
		netSalary = gross - (leaves * 500);
	}

	void paySlip() {
		System.out.print("\nEmployee Details");
		System.out.print("\n============================================================");
		System.out.print("\nEmplyee Name: " + hasEmp_name);
		System.out.print("\nEnter Employee ID: " + Emp_id);
		System.out.print("\nEnter Employee Address: " + Address);
		System.out.print("\nEnter Employee Mail ID: " + Mail_id);
		System.out.print("\n============================================================");
		System.out.print("\nPaySlip");
		System.out.print("\n============================================================");
		System.out.print("\nBasic Pay       " + basicPay);
		System.out.print("\nDA              " + da);
		System.out.print("\nHRA             " + hra);
		System.out.print("\nGross Salary    " + gross);
		System.out.print("\nDeduction       " + leaves * 500f);
		System.out.print("\nNet Salary      " + netSalary);
		System.out.print("\n============================================================");
	}
}


class AssistantProjectManager extends Employee {
	protected
	int leaves;
	float basicPay, da, hra, pf, scf, gross, netSalary;
	public
	Scanner sc = new Scanner(System.in);

	void Salary() {
		System.out.print("Enter Number of Leaves: ");
		leaves = sc.nextInt();
		System.out.print("Enter Basic Salary: ");
		basicPay = sc.nextFloat();
		da = basicPay * 0.97f;
		hra = basicPay * 0.10f;
		pf = basicPay * 0.12f;
		scf = basicPay * 0.001f;
		gross = basicPay + da + hra + pf + scf;
		netSalary = gross - (leaves * 500);
	}

	void paySlip() {
		System.out.print("\nEmployee Details");
		System.out.print("\n============================================================");
		System.out.print("\nEmplyee Name: " + hasEmp_name);
		System.out.print("\nEnter Employee ID: " + Emp_id);
		System.out.print("\nEnter Employee Address: " + Address);
		System.out.print("\nEnter Employee Mail ID: " + Mail_id);
		System.out.print("\n============================================================");
		System.out.print("\nPaySlip");
		System.out.print("\n============================================================");
		System.out.print("\nBasic Pay       " + basicPay);
		System.out.print("\nDA              " + da);
		System.out.print("\nHRA             " + hra);
		System.out.print("\nGross Salary    " + gross);
		System.out.print("\nDeduction       " + leaves * 500f);
		System.out.print("\nNet Salary      " + netSalary);
		System.out.print("\n============================================================");
	}
}

class ProjectManager extends Employee {
	protected
	int leaves;
	float basicPay, da, hra, pf, scf, gross, netSalary;
	public
	Scanner sc = new Scanner(System.in);

	void Salary() {
		System.out.print("Enter Number of Leaves: ");
		leaves = sc.nextInt();
		System.out.print("Enter Basic Salary: ");
		basicPay = sc.nextFloat();
		da = basicPay * 0.97f;
		hra = basicPay * 0.10f;
		pf = basicPay * 0.12f;
		scf = basicPay * 0.001f;
		gross = basicPay + da + hra + pf + scf;
		netSalary = gross - (leaves * 500);
	}

	void paySlip() {
		System.out.print("\nEmployee Details");
		System.out.print("\n============================================================");
		System.out.print("\nEmplyee Name: " + hasEmp_name);
		System.out.print("\nEnter Employee ID: " + Emp_id);
		System.out.print("\nEnter Employee Address: " + Address);
		System.out.print("\nEnter Employee Mail ID: " + Mail_id);
		System.out.print("\n============================================================");
		System.out.print("\nPaySlip");
		System.out.print("\n============================================================");
		System.out.print("\nBasic Pay       " + basicPay);
		System.out.print("\nDA              " + da);
		System.out.print("\nHRA             " + hra);
		System.out.print("\nGross Salary    " + gross);
		System.out.print("\nDeduction       " + leaves * 500f);
		System.out.print("\nNet Salary      " + netSalary);
		System.out.print("\n============================================================");
	}
}

public class LabAssignment3 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int exit;
		do {
			System.out.println("Select Your Designation");
			System.out.println("1. Programmer");
			System.out.println("2. Team Leader");
			System.out.println("3. Assistant Project Manager");
			System.out.println("4. Project Manager");
			System.out.print("Enter your Choice: ");
			int choice = sc.nextInt();
			switch (choice) {
			case 1:	Programmer obj1 = new Programmer();
				obj1.getData();
				obj1.Salary();
				obj1.paySlip();
				break;
			case 2: TeamLeader obj2 = new TeamLeader();
				obj2.getData();
				obj2.Salary();
				obj2.paySlip();
				break;
			case 3: AssistantProjectManager obj3 = new AssistantProjectManager();
				obj3.getData();
				obj3.Salary();
				obj3.paySlip();
				break;
			case 4: ProjectManager obj4 = new ProjectManager();
				obj4.getData();
				obj4.Salary();
				obj4.paySlip();
				break;
			default:
				System.out.println("Invalid Input");
			}
			System.out.print("\nDo you want to continue ? (Y=1/n=0) ");
			exit = sc.nextInt();
		} while (exit == 1);
		sc.close();
	}

}

