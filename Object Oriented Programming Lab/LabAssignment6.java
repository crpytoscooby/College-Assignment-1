
import java.util.Scanner;
public class LabAssignment6 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int choice;
		do{
			System.out.println("1) Perform Addition Operation");
			System.out.println("2) Inset An element in an Array");
			System.out.println("Press 0 to exit");
			choice = sc.nextInt();
			switch(choice) {
				case 0:
					break;
				case 1:
					try {
						System.out.print("Enter first no: ");
//						int n1 = Integer.parseInt(sc.next());
						int n1 = sc.nextInt();
						System.out.print("Enter second no: ");
//						int n2 = Integer.parseInt(sc.next());
						int n2 = sc.nextInt();
						int result = n1/n2;
						System.out.println(result);
						System.out.println();
					}
					catch(ArithmeticException e) {
						System.out.println("Cannot divide a Number by Zero: " + e);
						System.out.println();
					}
					catch(NumberFormatException e) {
						System.out.println("Only integers are allowed!: " + e);
						System.out.println();
					}
					break;
				case 2:
					try {
						int array[] = new int[6];	// Initializing an array of size 6
						System.out.print("Enter Element: ");
						int data = sc.nextInt();
						System.out.print("Enter Element at index: ");
						int index = sc.nextInt();
						array[index] = data;
						System.out.println();
					}
					catch(ArrayIndexOutOfBoundsException e) {
						System.out.println("Array Limit Excided: " + e);
						System.out.println();
					}
					break;
				default:
					System.out.println("Invalid Input\n");
			}
		}while(choice != 0);
		sc.close();			
	}

}
