
import java.util.Scanner;
public class PrimeNumber {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a Number");
		int n = sc.nextInt();
		sc.close();
		int flag = 0;
		
		if(n == 0 || n == 1)
		{
			System.out.print(n + " is not Prime Number");
			flag = 1;
		}
		else
		{
			for(int i = 2; i <= n/2; i++)
			{
				if(n%i == 0)
				{
					System.out.print(n + " is not Prime Number");
					flag = 1;
					break;
				}
			}
		}
		if(flag == 0)
		{
			System.out.print(n + " is Prime Number");
		}
	}

}
