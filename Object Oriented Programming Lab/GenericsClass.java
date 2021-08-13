
class MyData <T> {
	T i;
	public void add(T i) {
		this.i = i;
	}
	
	public T get() {
		return i;
	}
}

public class GenericsClass {
	
	public static void main(String[] args) {
		MyData<Integer> obj1 = new MyData<Integer>(); 
		MyData<String> obj2 = new MyData<String>();
		obj1.add(5);
		obj2.add("ABC");
		System.out.println(obj1.get());
		System.out.println(obj2.get());
	}
}
