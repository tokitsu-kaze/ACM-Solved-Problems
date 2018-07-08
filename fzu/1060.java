import java.math.*;
import java.util.*;

public class Main 
{
	public static void main (String[] args)
	{
		Scanner cin=new Scanner(System.in);
		BigInteger f[];
		int i,n;
		f=new BigInteger[10010];
		f[1]=new BigInteger("1");
		f[2]=new BigInteger("1");
		for(i=3;i<=10000;i++)
		{
			f[i]=f[i-1].add(f[i-2]);
		}
		while(cin.hasNext())
		{
			n=cin.nextInt();
			System.out.println(f[n]);
		}
	}
}