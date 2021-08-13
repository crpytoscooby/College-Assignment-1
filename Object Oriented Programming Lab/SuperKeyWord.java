
public class SuperKeyWord {
	public static void main(String[] args) {
		B obj = new B();
		obj.abc();
	}
}

class A {
	int i = 5;
	public void abc() {
		System.out.println("A abc");
	}
}

class B extends A {
	int i = 4;
	public void abc() {
		super.abc();
		System.out.println("B abc");
	}

//	public void show()
//	{
//		System.out.println(super.i);
//	}
}
/* public class SuperKeyWord {

	public static void main(String[] args) {
//		A obj = new A();
		B obj1 = new B();
		B obj2 = new B(5);
	}

}

class A {	// Super Class

	A() {
//		super();
		System.out.println("In const A");
	}

	A(int i) {
		System.out.println("In const A Par");
	}

}

class B extends A {	// Sub Class
	B() {
		System.out.println("In const B");
	}

	B(int i) {
		super(i);
		System.out.println("In const B Par");
	}
}*/