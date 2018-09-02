import java.math.*;
import java.util.*;

public class Main 
{
	public static void main (String[] args)
	{
		Scanner cin=new Scanner(System.in);
		int t;
		BigInteger a,b;
		while(cin.hasNext())
		{
			t=cin.nextInt();
			while(t-->0)
			{
				a=cin.nextBigInteger();
				b=cin.nextBigInteger();
				System.out.println(a.multiply(b));
			}
		}
	}
}