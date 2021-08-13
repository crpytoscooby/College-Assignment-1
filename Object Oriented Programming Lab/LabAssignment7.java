
import java.util.*;
public class LabAssignment7 {

	// this function is used to check the number is even or odd
	static <T> void checkEvenOdd(T[] intArray, int choice) {
		ArrayList<T> evenList = new ArrayList<T>();
		ArrayList<T> oddList = new ArrayList<T>();
		for(T element : intArray) {
			if(Integer.parseInt(element.toString()) % 2 == 0)
				evenList.add(element);
			else
				oddList.add(element);
		}
		
		if(choice == 1) {			
			System.out.print("Even numbers are: ");
			Iterator<T> itr = evenList.iterator();
			while(itr.hasNext())
				System.out.print(itr.next() + " ");			
		}
		
		else {
			System.out.print("Odd numbers are: ");
			Iterator<T> itr = oddList.iterator();
			while(itr.hasNext())
				System.out.print(itr.next() + " ");	
		}
	}
	
	// this function is used to find out prime numbers 
	static <T> boolean isPrime(T num, int choice) {
		int flag = 0, n;
		if(choice == 1)
			n = (Integer) num;
		else
			n = Integer.parseInt((String) num);
		for(int i = 2; i < n; i++) {
			if(n % i == 0) {
				flag = 1;
				break;
			}
		}
		
		if(flag == 0)
			return true;
		return false;
	}
	
	// this function is used to find whether the element is palindrome or not
	static <T> boolean isPalindrome(T num) {
		String n = num.toString();
		String rev = "";
		int length = n.length();
		for(int i = length-1; i >= 0; i--) {
			rev += n.charAt(i);
		}

		if(n.equals(rev))
			return true; 
		return false;
	}
	
	// this function is used to perform operation on integer data types
	static void integerOperation() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter no. of elements you want in array:");
	    int n = sc.nextInt();
	    
	    Integer[] intArray = new Integer[n];
	    System.out.print("Enter all the elements: ");
	    for(int i = 0; i < n; i++)
	    	intArray[i] = sc.nextInt();
		int choice;
		do {
			System.out.println("1) Check Even Numbers");
			System.out.println("2) Check Odd Numbers");
			System.out.println("3) Check Prime Numbers");
			System.out.println("4) Check Palindrome");
			System.out.println("Press 0 to exit");
			choice = sc.nextInt();
			switch(choice)
			{
				case 0:
					System.out.println("Exiting...\n\n");
					break;
				case 1:
					checkEvenOdd(intArray, choice);
					System.out.println("\n");
					break;
				case 2:
					checkEvenOdd(intArray, choice);
					System.out.println("\n");
					break;
				case 3:
					ArrayList<Integer> primeList = new ArrayList<Integer>();
					for(int element : intArray) {
						if(isPrime(element, 1))
							primeList.add(element);
					}
					Iterator<Integer> itrPrime = primeList.iterator();
					System.out.print("Prime Numbers are: ");
					while(itrPrime.hasNext())
						System.out.print(itrPrime.next() + " ");
					System.out.println("\n");
					break;
				case 4:
					ArrayList<Integer> paliList = new ArrayList<Integer>();
					for(int element : intArray) {
						if(isPalindrome(element))
							paliList.add(element);
					}
					Iterator<Integer> itrPali = paliList.iterator();
					System.out.print("Palindrome Numbers are: ");
					while(itrPali.hasNext())
						System.out.print(itrPali.next() + " ");
					System.out.println("\n");
					break;
				default:
					System.out.println("Invalid Input");
					System.out.println("\n");
					break;
			}
		}while(choice != 0);
	}
	
	// this function is used to perform operation on string data types
	static void stringOperation() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter no. of elements you want in array:");
	    int n = sc.nextInt();
	    
	    String[] stringArray = new String[n];
	    System.out.print("Enter all the elements: ");
	    for(int i = 0; i < n; i++)
	    	stringArray[i] = sc.next();

		int choice;
		do {
			System.out.println("1) Check Even Numbers");
			System.out.println("2) Check Odd Numbers");
			System.out.println("3) Check Prime Numbers");
			System.out.println("4) Check Palindrome");
			System.out.println("Press 0 to exit");
			choice = sc.nextInt();
			switch(choice)
			{
				case 0:
					System.out.println("Exiting...");
					System.out.println("\n");
					break;
				case 1:
					checkEvenOdd(stringArray, choice);
					System.out.println("\n");
					break;
				case 2:
					checkEvenOdd(stringArray, choice);
					System.out.println("\n");
					break;
				case 3:
					ArrayList<String> primeList = new ArrayList<String>();
					for(String element : stringArray) {
						if(isPrime(element, 2))
							primeList.add(element);
					}
					Iterator<String> itrPrime = primeList.iterator();
					System.out.print("Prime Numbers are: ");
					while(itrPrime.hasNext())
						System.out.print(itrPrime.next() + " ");
					System.out.println("\n");
					break;
				case 4:
					ArrayList<String> paliList = new ArrayList<String>();
					for(String element : stringArray) {
						if(isPalindrome(element))
							paliList.add(element);
					}
					Iterator<String> itrPali = paliList.iterator();
					System.out.print("Palindrome Numbers are: ");
					while(itrPali.hasNext())
						System.out.print(itrPali.next() + " ");
					System.out.println("\n");
					break;
				default:
					System.out.println("Invalid Input");
					System.out.println("\n");
					break;
			}
		}while(choice != 0);
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int choice;
		do {
			System.out.println("Enter your choice");
			System.out.println("1) Integers");
			System.out.println("2) String");
			System.out.println("Press 0 to exit");
			choice = sc.nextInt();
			switch(choice)
			{
				case 0:
					System.out.println("Exiting...");
					System.out.println();
					break;
				case 1:
					integerOperation();
					System.out.println();
					break;
				case 2:
					stringOperation();
					System.out.println();
					break;
				default:
					System.out.println("Invalid Input");
					System.out.println();
					break;
			}			
		}while(choice != 0);
		sc.close();
	}

}
/*
OUTPUT:
TEST CASE 1:
Enter your choice
1) Integers
2) String
Press 0 to exit
1
Enter no. of elements you want in array:9
Enter all the elements: 41 26 4 89 55 771 121 999 454
1) Check Even Numbers
2) Check Odd Numbers
3) Check Prime Numbers
4) Check Palindrome
Press 0 to exit
1
Even numbers are: 26 4 454 

1) Check Even Numbers
2) Check Odd Numbers
3) Check Prime Numbers
4) Check Palindrome
Press 0 to exit
2
Odd numbers are: 41 89 55 771 121 999 

1) Check Even Numbers
2) Check Odd Numbers
3) Check Prime Numbers
4) Check Palindrome
Press 0 to exit
3
Prime Numbers are: 41 89 

1) Check Even Numbers
2) Check Odd Numbers
3) Check Prime Numbers
4) Check Palindrome
Press 0 to exit
4
Palindrome Numbers are: 4 55 121 999 454 

1) Check Even Numbers
2) Check Odd Numbers
3) Check Prime Numbers
4) Check Palindrome
Press 0 to exit
0
Exiting...



Enter your choice
1) Integers
2) String
Press 0 to exit
0
Exiting...


Test Case 2:
Enter your choice
1) Integers
2) String
Press 0 to exit
2
Enter no. of elements you want in array:9
Enter all the elements: 41 26 4 89 55 771 121 999 454
1) Check Even Numbers
2) Check Odd Numbers
3) Check Prime Numbers
4) Check Palindrome
Press 0 to exit
1
Even numbers are: 26 4 454 

1) Check Even Numbers
2) Check Odd Numbers
3) Check Prime Numbers
4) Check Palindrome
Press 0 to exit
2
Odd numbers are: 41 89 55 771 121 999 

1) Check Even Numbers
2) Check Odd Numbers
3) Check Prime Numbers
4) Check Palindrome
Press 0 to exit
3
Prime Numbers are: 41 89 

1) Check Even Numbers
2) Check Odd Numbers
3) Check Prime Numbers
4) Check Palindrome
Press 0 to exit
4
Palindrome Numbers are: 4 55 121 999 454 

1) Check Even Numbers
2) Check Odd Numbers
3) Check Prime Numbers
4) Check Palindrome
Press 0 to exit
0
Exiting...



Enter your choice
1) Integers
2) String
Press 0 to exit
0
Exiting...


*/