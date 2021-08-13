class Test {
	void show() throws RuntimeException
    {
        System.out.println("1");
    }
}

public class Overriding extends Test{

	void show() throws RuntimeException
    {
        System.out.println("2");
    }
	
	public static void main(String[] args) {
		Test t = new Test();
		t.show();
		
		Overriding m = new Overriding();
		m.show();
		
	}

}
