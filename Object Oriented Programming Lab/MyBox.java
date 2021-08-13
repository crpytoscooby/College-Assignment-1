
public class MyBox<T> {
	private T t;
	
	public void set(T t) {
		this.t = t;
	}
	
	public T get() {
		return t;
	}
	
	public static void main(String[] args) {
		MyBox<Integer> integerBox = new MyBox<Integer>();
		MyBox<String> stringBox = new MyBox<String>();
		
		integerBox.set(10);
		stringBox.set("Hello World");
		
		System.out.printf("Integer Value: %d\n\n", integerBox.get());
		System.out.printf("String Value: %s\n", stringBox.get());
	}

}
