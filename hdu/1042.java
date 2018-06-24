////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-30 20:29:02
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1042
////Problem Title: 
////Run result: Accept
////Run time:764MS
////Run memory:14112KB
//////////////////System Comment End//////////////////
import java.math.BigInteger;
import java.util.Scanner;

public class Main 
{
	
	public static void main (String[] args)
	{
		BigInteger sum,temp;
		int n,i;
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext())
		{
			n=cin.nextInt();
			sum=new BigInteger("1");
			for(i=2;i<=n;i++)
			{
				temp=new BigInteger(i+"");
				sum=sum.multiply(temp);
			}
			System.out.println(sum.toString());
		}
	}

}