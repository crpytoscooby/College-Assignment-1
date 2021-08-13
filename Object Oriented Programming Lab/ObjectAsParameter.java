
class Obj1 {
	public int length, breadth;
	Obj1(int length, int breadth) {
		this.length = length;
		this.breadth = breadth;
	}
	
	void rectangleArea(Obj1 o) {
		int area;
		area = o.length * o.breadth;
		System.out.println("The area of rectangle = " + area);
	}
}

public class ObjectAsParameter {

	public static void main(String[] args) {
		Obj1 o1 = new Obj1(4, 5);
		Obj1 o2 = new Obj1(20, 50);
		o1.rectangleArea(o2);
	}

}
