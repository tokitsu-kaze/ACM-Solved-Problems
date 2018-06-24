////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-30 20:39:41
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1250
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:19048KB
//////////////////System Comment End//////////////////
import java.math.BigInteger;
import java.util.Scanner;

public class Main 
{
	public static void main (String[] args)
	{
		BigInteger f[];
		int i,n;
		f=new BigInteger[10010];
		f[1]=new BigInteger("1");
		f[2]=new BigInteger("1");
		f[3]=new BigInteger("1");
		f[4]=new BigInteger("1");
		for(i=5;i<=10000;i++)
		{
			f[i]=f[i-1].add(f[i-2].add(f[i-3].add(f[i-4])));
		}
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext())
		{
			n=cin.nextInt();
			System.out.println(f[n]);
		}
	}

}