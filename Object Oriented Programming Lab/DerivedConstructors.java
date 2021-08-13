
class Base {
	int num1;
	Base(int x) {
		num1 = x;
		System.out.println("This is Base Class Constructor having value " + num1);
	}
}

class Derived extends Base{
	int num2;
	Derived(int y) {
		super(y);
		num1 = y;
		System.out.println("This is Derived Class Constructor having value " + num2);
	}
}
public class DerivedConstructors {

	public static void main(String[] args) {
		Derived obj = new Derived(10);
	}

}
