
public class ExceptionHandling1 {

	public static void main(String[] args) {
		// System.out.println("1");
		try {
			// System.out.println("2");
			int a = 100, b = 0;
			// System.out.println("3");
			int c = a/b;
			// System.out.println("4");
			System.out.println(c);
			// System.out.println("5");
		}
		catch(ArithmeticException e) {
			// System.out.println("6");
			// System.out.println(e);
			// System.out.println("7");
	
			// e.printStackTrace();
			// System.out.println(e.toString());
			System.out.println(e.getMessage());
		}
		// System.out.println("hello world");
    }
}
