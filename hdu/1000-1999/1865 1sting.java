////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-30 20:53:18
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1865
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:16608KB
//////////////////System Comment End//////////////////
import java.math.BigInteger;
import java.util.Scanner;

public class Main 
{
	public static void main (String[] args)
	{
		BigInteger f[];
		int i,n,t;
		String c;
		f=new BigInteger[10010];
		f[1]=new BigInteger("1");
		f[2]=new BigInteger("2");
		for(i=3;i<=10000;i++)
		{
			f[i]=f[i-1].add(f[i-2]);
		}
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext())
		{
			t=cin.nextInt();
			while(t-->0)
			{
				c=cin.next();
				n=c.length();
				System.out.println(f[n]);
			}
		}
	}
}
