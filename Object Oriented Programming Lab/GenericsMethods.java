
public class GenericsMethods {
	
	public <E> void printArray(E []s) {
		for(E elements : s) {
			System.out.print(elements + " ");
		}
//		for(int i = 0; i < s.length; i++) {
//			System.out.print(s[i] + " ");
//		}
		System.out.println();
	}
	
	public static void main(String[] args) {
		GenericsMethods obj = new GenericsMethods();
		String numb1[] = new String[] {"One", "Two", "Three", "Four"};
		Integer numb2[] = new Integer[] {1, 2, 3, 4};
		
		obj.printArray(numb1);
		obj.printArray(numb2);
	}
}
