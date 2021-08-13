import java.util.Scanner;
public class Temp {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int i=0;i<t;i++)
		{
        	int a = in.nextInt();
        	int b = in.nextInt();
        	int n = in.nextInt();
        	long s = 0;
        	int result=1;
        	s=a+(b*result);
        	for(int k = 1; k <= n; k++)
        	{
        		result=1;
        		System.out.print(s+" ");
        		int temp=k;
        		while(temp!=0)
        		{
        			result=result*2;
        			temp--;
        		}
        		s=s+(b*result);
        	}
        	System.out.println();
		}
        in.close();


	}

}
