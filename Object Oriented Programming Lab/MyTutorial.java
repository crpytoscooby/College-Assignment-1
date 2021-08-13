
class Box {

    int width;
    int height;

    Box(int width, int height) {
        this.width = width;
        this.height = height;
    }

    Box(Box b) {
        this.width = b.width;
        this.height = b.height;
    }

    boolean isEqual(Box b) {
        if (this.width == b.width && this.height == b.height)
            return true;
        else
            return false;
    }
}

public class MyTutorial {

    public static void main(String[] args) {
        Box b1 = new Box(10, 20);
        Box b2 = new Box(10, 20);
        Box b3 = new Box(b1);

        if (b1.isEqual(b2))
            System.out.println("Both b1 and b2 are equal");
        else
            System.out.println("Both b1 and b2 are not equal");

        System.out.println("There was an idea to bring together a group of remarkable people so when they needed us we could fight up the battles");
    }
}
