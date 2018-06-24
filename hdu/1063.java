////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-12-03 09:58:40
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1063
////Problem Title: 
////Run result: Accept
////Run time:608MS
////Run memory:14372KB
//////////////////System Comment End//////////////////
import java.math.*;
import java.util.*;

public class Main 
{
	public static void main (String[] args)
	{
		Scanner cin=new Scanner(System.in);
		BigDecimal a,ans;
		int n;
		while(cin.hasNext())
		{
			a=cin.nextBigDecimal();
			n=cin.nextInt();
			ans=a.pow(n).stripTrailingZeros();
			System.out.println(ans.toPlainString().replaceAll("^0", ""));
		}
	}
}
