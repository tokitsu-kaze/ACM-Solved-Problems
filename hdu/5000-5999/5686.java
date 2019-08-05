////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-04 14:07:41
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 5686
////Problem Title: 
////Run result: Accept
////Run time:327MS
////Run memory:9992KB
//////////////////System Comment End//////////////////
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Main 
{
	public static void main (String[] args)
	{
		int n,i;
		BigInteger[] f=new BigInteger[222];
		Scanner cin=new Scanner(System.in);
		f[0]=new BigInteger("0");
		f[1]=new BigInteger("1");
		f[2]=new BigInteger("2");
		for(i=3;i<=200;i++)
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