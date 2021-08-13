
public class StaticDataMember {
	static int count = 0;

	StaticDataMember() {
		count++;
	}

	void display() {
		System.out.println("Value of Count = " + count);
	}

	public static void main(String[] args) {
		StaticDataMember obj1 = new StaticDataMember();
		obj1.display();
		StaticDataMember obj2 = new StaticDataMember();
		obj2.display();
		StaticDataMember obj3 = new StaticDataMember();
		obj2.display();
	}

}

