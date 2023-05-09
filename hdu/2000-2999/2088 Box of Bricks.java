////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-12-02 19:25:20
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 2088
////Problem Title: 
////Run result: Accept
////Run time:280MS
////Run memory:9924KB
//////////////////System Comment End//////////////////
import java.math.*;
import java.util.*;

public class Main 
{
	public static void main (String[] args)
	{
		Scanner cin=new Scanner(System.in);
		int n,i,a[],flag=0,sum,ans;
		a=new int[51];
		while(cin.hasNext())
		{
			n=cin.nextInt();
			if(n==0) break;
			if(flag==1) System.out.println();
			sum=ans=0;
			for(i=0;i<n;i++)
			{
				a[i]=cin.nextInt();
				sum+=a[i];
			}
			sum/=n;
			for(i=0;i<n;i++)
			{
				if(a[i]>sum) ans+=a[i]-sum;
			}
			System.out.println(ans);
			flag=1;
		}
	}
}