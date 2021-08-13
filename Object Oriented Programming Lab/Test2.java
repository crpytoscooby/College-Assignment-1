
import java.util.Scanner;
class staff {
	protected String code, name;
	Scanner sc = new Scanner(System.in);
	public void getData() {
		System.out.print("Enter Name of Staff: ");
		name = sc.nextLine();
		System.out.print("Enter Code of Staff: ");
		code = sc.nextLine();
	} 
	
	public void displayData() {
		System.out.println("\nName of Staff: " + name);
		System.out.println("Code of Staff: " + code);
	}
}

class teacher extends staff {
	protected String subject, publication;
	Scanner sc = new Scanner(System.in);
	public void getTeacher() {
		System.out.print("Enter Subject: ");
		subject = sc.nextLine();
		System.out.print("Enter Publication: ");
		publication = sc.nextLine();
	}
	
	public void displayTeacher() {
		System.out.println("Subject: " + subject);
		System.out.println("Publication: " + publication);
	}
}

class typist extends staff {
	protected int speed;
	public void getSpeed() {
		System.out.print("Enter Speed: ");
		speed = sc.nextInt();
	}
	
	public void displaySpeed() {
		System.out.println("Speed: " + speed);
	}
}

class regular extends typist {
	
}

class casual extends typist {
	protected int wage;
	public void getWage() {
		System.out.print("Enter Daily Wages: ");
		wage = sc.nextInt();
	}
	public void displayWage() {
		System.out.println("Daily Wages: " + wage);
	}
}

class officer extends staff {
	protected String grade;
	public void getGrade() {
		System.out.print("Enter your Grade: ");
		grade = sc.nextLine();
	}
	public void displayGrade() {
		System.out.println("Grade: " + grade);
	}
}
public class Test2 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int choice;
		do {
			System.out.println("1) Teacher Details");
			System.out.println("2) Typist Details");
			System.out.println("3) Officer Details");
			System.out.println("Press 0 to exit");
			System.out.println("Enter Your Choice");
			choice = sc.nextInt();
			switch(choice) {
			case 1:
				teacher t = new teacher();
				t.getData();
				t.getTeacher();
				System.out.println("==========Teacher Details==========");
				t.displayData();
				t.displayTeacher();
				break;
			case 2:
				casual c = new casual();
				c.getData();
				c.getSpeed();
				c.getWage();
				System.out.println("==========Typist Details==========");
				c.displayData();
				c.displaySpeed();
				c.displayWage();
				break;
			case 3:
				officer o = new officer();
				o.getData();
				o.getGrade();
				System.out.println("==========Officer Details==========");
				o.displayData();
				o.displayGrade();
			default:
				break;
			}
			System.out.println("===================================");
		}while(choice!=0);		
		sc.close();
	}

}
