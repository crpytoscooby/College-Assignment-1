/*
class Publication
	getTitle()
	setTitle()
	setPrice()
	getPrice()
	sell
	
class Book -> Publication
	getAuthor()
	setAuthor()
	getOrderCopy()
	setOrgerCopy()
	
	
class Magazine -> Publication
	getIssue()
	setIssue()
	
*/
import java.util.Scanner;
abstract class Publication {

	protected String title;
	protected int price, copies;
	
	abstract void saleCopy();
	abstract void setPrice();
}

class Book extends Publication {
	protected String author;
	Scanner sc = new Scanner(System.in);
	
	public void saleCopy() {
		System.out.print("\n==================================================");
		System.out.print("\nBook Name: " + title);
		System.out.print("\nAuthor Name: " + author);
		System.out.print("\nPrice per Book: " + price);
		System.out.print("\nCopies Ordered: " + copies);
		System.out.print("\nTotal Sales: " + copies*price + " Rs");
		System.out.print("\n==================================================\n");
	}
	
	public void orderCopies() {
		System.out.print("Enter the Quantity: ");
		copies = sc.nextInt();
	}
	
	public void setPrice() {
		System.out.print("Enter the Name of the Book: ");
		title = sc.nextLine();
		System.out.print("Enter the Author: ");
		author = sc.nextLine();
		System.out.print("Enter the price of the Book: ");
		price = sc.nextInt();
	}
}

class Magazine extends Publication {
	protected String author, currIssue;
	Scanner sc = new Scanner(System.in);
	public void saleCopy() {
		System.out.print("\n==================================================");
		System.out.print("\nMagazine Name: " + title);
		System.out.print("\nPrice per Magazine: " + price);
		System.out.print("\nCopies Ordered: " + copies);
		System.out.print("\nTotal Sales: " + copies*price + " Rs");
		System.out.print("\n==================================================\n");
	}
	
	public void orderQty() {
		System.out.print("Enter the Quantity: ");
		copies = sc.nextInt();
	}
	
	public void currentIssue() {
		System.out.print("Current Issue of Magazine is " + currIssue);
	}
	
	public void receivedIssue() {
		System.out.print("You will Receive " + currIssue + " Magazine soon.");
	}
	
	public void setPrice() {
		System.out.print("\nEnter the Name of the Magazine: ");
		title = sc.nextLine();
		System.out.print("Enter the Issue: ");
		currIssue = sc.nextLine();
		System.out.print("Enter the price of the Magazine: ");
		price = sc.nextInt();
	}
}
public class LabAssignment2 {

	public static void main(String[] args) {
			Book b = new Book();
			b.setPrice();
			b.orderCopies();
			b.saleCopy();
			
			Magazine m = new Magazine();
			m.setPrice();
			m.orderQty();
			m.receivedIssue();
			m.saleCopy();
	}
}
/*
Enter the Name of the Book: Concepts of Physics
Enter the Author: H.C. Verma
Enter the price of the Book: 346
Enter the Quantity: 8

==================================================
Book Name: Concepts of Physics
Author Name: H.C. Verma
Price per Book: 346
Copies Ordered: 8
Total Sales: 2768 Rs
==================================================

Enter the Name of the Magazine: Overdrive
Enter the Issue: November 2020
Enter the price of the Magazine: 230
Enter the Quantity: 10
You will Receive November 2020 Magazine soon.
==================================================
Magazine Name: Overdrive
Price per Magazine: 230
Copies Ordered: 10
Total Sales: 2300 Rs
==================================================

*/
