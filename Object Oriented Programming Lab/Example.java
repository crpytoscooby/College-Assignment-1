
class myData <T> {

    T i;

    public void add(T i1) {
        i = i1;
    }

    public T getI() {
        return i;
    }
}

public class Example {

    public static void main(String[] args) {
        myData<Integer> m1 = new myData<>();
        myData<String> m2 = new myData<>();
        Integer k = 5;
        m1.add(k);
        m2.add("Pune");
        System.out.println("m1 = " + m1.getI());
        System.out.println("m2 = " + m2.getI());
    }
}