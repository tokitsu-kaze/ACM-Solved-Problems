////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-27 18:12:19
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1753
////Problem Title: 
////Run result: Accept
////Run time:249MS
////Run memory:9920KB
//////////////////System Comment End//////////////////
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Main 
{
	public static void main (String[] args)
	{
		BigDecimal a,b,ans;
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext())
		{
			a=cin.nextBigDecimal();
			b=cin.nextBigDecimal();
			ans=a.add(b);
			ans=ans.stripTrailingZeros();
			System.out.println(ans.toPlainString());
		}
	}
}