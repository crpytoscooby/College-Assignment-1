
public class DynamicInitialization {
	int a, b;
	DynamicInitialization(int a, int b)
	{
		this.a = a;
		this.b = b;
	}
	
	void display()
	{
		System.out.println("The value of a is " + a + " and the value of b is " + b);
	}

	public static void main(String[] args) {
		DynamicInitialization obj1 = new DynamicInitialization(1, 2);
		DynamicInitialization obj2 = new DynamicInitialization(12, 27);
		DynamicInitialization obj3 = new DynamicInitialization(48, 95);
		obj1.display();
		obj2.display();
		obj3.display();
	}
}
