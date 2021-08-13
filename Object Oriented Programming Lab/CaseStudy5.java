
import java.util.*;
public class CaseStudy5 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);		
		try {
			System.out.println("Enter number of elements you want to insert: ");
			int n = sc.nextInt();
			List<Integer> stringList = new ArrayList<Integer>();
			for(int i = 0; i < n; i++) {
				System.out.println("Enter Data: ");
				int element = sc.nextInt();
				stringList.add(element);
			}
			System.out.println(stringList);
		}
		catch(InputMismatchException e) {
			System.out.println("Only Integer Data is Allowed");
		}
		finally {
			sc.close();			
		}
	}

}
