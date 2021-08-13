
public class StaticMemberFunction {
	
	public static void Function()
	{
		System.out.println("This is a Static Method Function");
	}
	
	static
	{
		System.out.println("This is a Static Block");
	}
	public static void main(String[] args) {
		Function();	// calling function without creating an object
	}

}
