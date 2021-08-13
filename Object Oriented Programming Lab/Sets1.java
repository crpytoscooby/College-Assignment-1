
import java.util.*;
public class Sets1 {

	public static void main(String[] args) {
		
		Set<String> obj = new HashSet<String>();
		obj.add("One");
		obj.add("Two");
		obj.add("Three");
		obj.add("Four");
		obj.add("Five");
		obj.add("Two");
//		obj.add(new Integer(5));		this line will show an error
		System.out.println(obj);
		
		
		// searching for an element in a set
		if(obj.contains("Five")) {
			System.out.println("Found");
		}
		else {
			System.out.println("Not Found");
		}
		
		// union of the sets
		Set<Integer> s1 = new HashSet<>(Arrays.asList(1, 3, 5, 7, 9));
		Set<Integer> s2 = new HashSet<>(Arrays.asList(2, 4, 6 ,8));
		System.out.println(s1);
		s1.addAll(s2);
		System.out.println(s1);
	}	

}
