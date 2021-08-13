
public class ExceptionHandling2 {

	public static void main(String[] args) {
		try
		{
			int a = 100, b = 2, c;
			c = a/b;
			System.out.println(c);
		}
//		catch(ArithmeticException e)
//		{
//			System.out.println("Exception: " + e);
//		}
		finally
		{
			System.out.println("i am in finally block");
		}
		System.out.println("hello");
	}

}
