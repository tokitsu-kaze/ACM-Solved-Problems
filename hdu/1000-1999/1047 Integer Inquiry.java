////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-12-01 20:23:05
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1047
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:9576KB
//////////////////System Comment End//////////////////
import java.math.*;
import java.util.*;

public class Main 
{
	public static void main (String[] args)
	{
		Scanner cin=new Scanner(System.in);
		BigInteger a,sum,temp;
		int n,i;
		while(cin.hasNext())
		{
			n=cin.nextInt();
			while(n-->0)
			{
				sum=new BigInteger("0");
				temp=new BigInteger("0");
				while(true)
				{
					a=cin.nextBigInteger();
					if(a.compareTo(temp)==0) break;
					sum=sum.add(a);
				}
				System.out.println(sum);
				if(n!=0) System.out.println();
			}
		}
	}
}