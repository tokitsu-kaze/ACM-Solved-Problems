////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-06 13:22:24
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1023
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:10408KB
//////////////////System Comment End//////////////////
import java.math.*;
import java.util.*;

public class Main 
{
	public static void main (String[] args)
	{
		Scanner cin=new Scanner(System.in);
		BigInteger f[],sum;
		int i,j,n;
		f=new BigInteger[101];
		f[0]=new BigInteger("1");
		for(i=1;i<=100;i++)
		{
			sum=new BigInteger("0");
			for(j=0;j<i;j++)
			{
				sum=sum.add(f[j].multiply(f[i-j-1]));
			}
			f[i]=sum;
		}
		while(cin.hasNext())
		{
			n=cin.nextInt();
			System.out.println(f[n]);
		}
	}
}