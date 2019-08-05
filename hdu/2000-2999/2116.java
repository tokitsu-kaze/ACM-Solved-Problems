////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-02 19:34:09
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 2116
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:9540KB
//////////////////System Comment End//////////////////
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Main 
{
	public static void main (String[] args)
	{
		int k;
		BigInteger a,b,tl,tr,t;
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext())
		{
			k=cin.nextInt();
			k--;
			a=cin.nextBigInteger();
			b=cin.nextBigInteger();
			t=new BigInteger("0");
			tl=new BigInteger("2");
			tr=new BigInteger("2");
			tl=t.subtract((tl.pow(k)));
			t=new BigInteger("1");
			tr=tr.pow(k).subtract(t);
			t=a.add(b);
	//		System.out.println(tl);
	//		System.out.println(tr);
	//		System.out.println(t);
			if(t.compareTo(tl)>=0&&t.compareTo(tr)<=0)
				System.out.println("WaHaHa");
			else System.out.println("Yes");
		}
	}
}