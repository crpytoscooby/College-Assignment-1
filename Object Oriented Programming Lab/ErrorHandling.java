
import java.io.FileInputStream;
public class ErrorHandling {

	public static void main(String[] args) {

		try {
			FileInputStream file = new FileInputStream("your_file_location");
		} catch (Exception e) {
			System.out.println(e);
		}

		try {
			int a = 100, b = 0;
			int c = a / b;
			System.out.println(c);
		} catch (Exception e) {
			System.out.println("Cannot divide a number by 0");
		}
	}

}
