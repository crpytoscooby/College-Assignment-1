
public class Delete {

    static int a;

    static {
        a = 4;
        System.out.println("inside static block");
        System.out.println("a = " + a);
    }

    Delete() {
        System.out.println("Inside constructor");
        a = 10;
    }

    public static void func() {
        a = a + 1;
        System.out.println("inside func()");
        System.out.println("a = " + a);
    }

    public static void main(String[] args) {
        Delete obj = new Delete();
        obj.func();
        func();
    }
}
