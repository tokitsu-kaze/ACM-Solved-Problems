////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-30 21:09:46
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1715
////Problem Title: 
////Run result: Accept
////Run time:405MS
////Run memory:13604KB
//////////////////System Comment End//////////////////
import java.math.BigInteger;
import java.util.Scanner;

public class Main 
{
	public static void main (String[] args)
	{
		Scanner cin=new Scanner(System.in);
		BigInteger f[];
		f=new BigInteger[1010];
		int i,t,n;
		f[1]=new BigInteger("1");
		f[2]=new BigInteger("1");
		for(i=3;i<=1000;i++)
		{
			f[i]=f[i-1].add(f[i-2]);
		}
		while(cin.hasNext())
		{
			t=cin.nextInt();
			while(t-->0)
			{
				n=cin.nextInt();
				System.out.println(f[n]);
			}
		}
	}
}