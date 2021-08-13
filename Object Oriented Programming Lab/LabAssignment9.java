
import java.util.*;

class Bank {
	
	private String accno;
    private String name;
    private long balance;
    
    Scanner sc = new Scanner(System.in);
    
    //method to open an account
	void openAccount() {
        System.out.print("Enter Account No: ");
        accno = sc.next();
        System.out.print("Enter Name: ");
        name = sc.next();
        System.out.print("Enter Balance: ");
        balance = sc.nextLong();
    }
	
	//method to display account details
	void showAccount() {
        System.out.println(accno + "\t" + name + "\t" + balance);
    }
	
	//method to deposit money
    void deposit() {
        long amt;
        System.out.println("Enter Amount U Want to Deposit : ");
        amt = sc.nextLong();
        balance = balance + amt;
    }
    
    //method to withdraw money
    void withdrawal() {
        long amt;
        System.out.println("Enter Amount U Want to withdraw : ");
        amt = sc.nextLong();
        if (balance >= amt) {
            balance = balance - amt;
        } else {
            System.out.println("Less Balance..Transaction Failed..");
        }
    }

    //method to search an account number
    boolean search(String acn) {
        if (accno.equals(acn)) {
            showAccount();
            return (true);
        }
        return (false);
    }
}

public class LabAssignment9 {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int choice, size = 20, current = 0;
		Bank[] C = new Bank[size];
		
		do {
			System.out.println("Main Menu");
			System.out.println("1. Create Account");
            System.out.println("2. Display All");
            System.out.println("3. Search By Account");
            System.out.println("4. Deposit");
            System.out.println("5. Withdrawal");
            System.out.println("Press 0 to exit");
            choice = sc.nextInt();
			switch(choice) {
			case 0:
				System.out.println();
				System.out.println("\nExiting...");
				break;
			case 1:
				System.out.println();
				C[current] = new Bank();
	            C[current].openAccount();
	            current++;
	            break;
			case 2:
				System.out.println();
				System.out.println("AccNo" + "\t" + "Name" + "\t" + "Balance");
				for (int i = 0; i < current; i++) {
                    C[i].showAccount();
                }
                break;
			case 3:
				System.out.println();
				System.out.print("Enter Account No U Want to Search...: ");
                String acn = sc.next();
                boolean found = false;
                for (int i = 0; i < current; i++) {
                    found = C[i].search(acn);
                    if (found) {
                        break;
                    }
                }
                if (!found) {
                    System.out.println("Search Failed..Account Not Exist..");
                }
                break;
			case 4:
				System.out.println();
				System.out.print("Enter Account No : ");
                acn = sc.next();
                found = false;
                for (int i = 0; i < current; i++) {
                    found = C[i].search(acn);
                    if (found) {
                        C[i].deposit();
                        break;
                    }
                }
                if (!found) {
                    System.out.println("Search Failed..Account Not Exist..");
                }
                break;
			case 5:
				System.out.println();
				System.out.print("Enter Account No : ");
                acn = sc.next();
                found = false;
                for (int i = 0; i < current; i++) {
                    found = C[i].search(acn);
                    if (found) {
                        C[i].withdrawal();
                        break;
                    }
                }
                if (!found) {
                    System.out.println("Search Failed..Account Not Exist..");
                }
                break;
	        
			}
		}while(choice!=0);
		sc.close();
	}
}


/*
Main Menu
1. Create Account
2. Display All
3. Search By Account
4. Deposit
5. Withdrawal
Press 0 to exit
1

Enter Account No: 101
Enter Name: ABC
Enter Balance: 25000
Main Menu
1. Create Account
2. Display All
3. Search By Account
4. Deposit
5. Withdrawal
Press 0 to exit
1

Enter Account No: 102
Enter Name: DEF
Enter Balance: 30000
Main Menu
1. Create Account
2. Display All
3. Search By Account
4. Deposit
5. Withdrawal
Press 0 to exit
2

AccNo	Name	Balance
101	ABC	25000
102	DEF	30000
Main Menu
1. Create Account
2. Display All
3. Search By Account
4. Deposit
5. Withdrawal
Press 0 to exit
3

Enter Account No U Want to Search...: 102
102	DEF	30000
Main Menu
1. Create Account
2. Display All
3. Search By Account
4. Deposit
5. Withdrawal
Press 0 to exit
3

Enter Account No U Want to Search...: 105
Search Failed..Account Not Exist..
Main Menu
1. Create Account
2. Display All
3. Search By Account
4. Deposit
5. Withdrawal
Press 0 to exit
4

Enter Account No : 102
102	DEF	30000
Enter Amount U Want to Deposit : 
25000
Main Menu
1. Create Account
2. Display All
3. Search By Account
4. Deposit
5. Withdrawal
Press 0 to exit
4

Enter Account No : 105
Search Failed..Account Not Exist..
Main Menu
1. Create Account
2. Display All
3. Search By Account
4. Deposit
5. Withdrawal
Press 0 to exit
5

Enter Account No : 102
102	DEF	55000
Enter Amount U Want to withdraw : 
15000
Main Menu
1. Create Account
2. Display All
3. Search By Account
4. Deposit
5. Withdrawal
Press 0 to exit
4

Enter Account No : 102
102	DEF	40000
Enter Amount U Want to Deposit : 
15000
Main Menu
1. Create Account
2. Display All
3. Search By Account
4. Deposit
5. Withdrawal
Press 0 to exit
5

Enter Account No : 10
Search Failed..Account Not Exist..
Main Menu
1. Create Account
2. Display All
3. Search By Account
4. Deposit
5. Withdrawal
Press 0 to exit
5

Enter Account No : 102
102	DEF	55000
Enter Amount U Want to withdraw : 
15000
Main Menu
1. Create Account
2. Display All
3. Search By Account
4. Deposit
5. Withdrawal
Press 0 to exit
5

Enter Account No : 105
Search Failed..Account Not Exist..
Main Menu
1. Create Account
2. Display All
3. Search By Account
4. Deposit
5. Withdrawal
Press 0 to exit
0


Exiting...
*/