
public class GenericClass<T> {
	private T item;
	public void setData(T item) {
		this.item = item;
	}
	
	public T getData() {
		return item;
	}
	
	public static void main(String[] args) {
		GenericClass<Boolean> obj1 = new GenericClass<>();
		obj1.setData(true);
		System.out.println(obj1.getData());
		
		GenericClass<Integer> obj2 = new GenericClass<>();
		obj2.setData(3);
		System.out.println(obj2.getData());
		
		GenericClass<Float> obj3 = new GenericClass<>();
		obj3.setData(3.142f);
		System.out.println(obj3.getData());
		
		GenericClass<Character> obj4 = new GenericClass<>();
		obj4.setData('f');
		System.out.println(obj4.getData());
		
		GenericClass<String> obj5 = new GenericClass<>();
		obj5.setData("Hello World!");
		System.out.println(obj5.getData());
		
	}
}
