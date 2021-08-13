class A {
	public void display() {
		System.out.println("This is Class A");
	}
}

interface B {
	public static void display() {
		System.out.println("This is Class B");
	}
}

interface C {
	public static void display() {
		System.out.println("This is Class C");
	}
}

class D implements B, C {
	public void display() {
//		super.display();
		System.out.println("This is Class D");
	}
}
public class HybridInheritance {

	public static void main(String[] args) {
		D obj = new D();
		obj.display();
	}

}
