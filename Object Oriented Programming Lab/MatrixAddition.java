import java.util.Scanner;
public class MatrixAddition {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int arr1[][] = new int[3][3];
		int arr2[][] = new int[3][3];
		int sum[][] = new int[3][3];
		System.out.println("Enter Elements of first Matrix of 3X3");
		for(int i=0; i<3; i++)
		{
			for(int j=0;j<3;j++)
			{
				arr1[i][j] = sc.nextInt();
			}
		}
		System.out.println("First Matrix");
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				System.out.print(arr1[i][j] + "\t");
			}
			System.out.println();
		}
		
		System.out.println("Enter Elements of second Matrix of 3X3");
		for(int i=0; i<3; i++)
		{
			for(int j=0;j<3;j++)
			{
				arr2[i][j] = sc.nextInt();
			}
		}
		System.out.println("Second Matrix");
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				System.out.print(arr2[i][j] + "\t");
			}
			System.out.println();
		}
		
		for(int i=0; i<3; i++)
		{
			for(int j=0;j<3;j++)
			{
				sum[i][j] = arr1[i][j] + arr2[i][j];
			}
		}
		System.out.println("Addition of Matrix First and Second");
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				System.out.print(sum[i][j] + "\t");
			}
			System.out.println();
		}
		sc.close();
	}
}
