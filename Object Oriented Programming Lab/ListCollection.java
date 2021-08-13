
import java.util.*;
public class ListCollection {

	public static void main(String[] args) {
		List<String> stringList = new ArrayList<>();
		stringList.add("One");
		stringList.add("Two");
		stringList.add("Three");
		stringList.add("Four");
		stringList.add("Five");
		System.out.println("String List Contents: " + stringList);
		
		List<Integer> intList = new ArrayList<>();
		intList.add(1);
		intList.add(2);
		intList.add(3);
		intList.add(4);
		intList.add(5);
		System.out.println("Integer List Contents: " + intList);
	}

}
