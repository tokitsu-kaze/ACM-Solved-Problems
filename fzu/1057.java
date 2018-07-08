import java.math.*;
import java.util.*;

public class Main 
{
	public static void main (String[] args)
	{
		Scanner cin=new Scanner(System.in);
		int a,b,i,ans;
		while(cin.hasNext())
		{
			a=cin.nextInt();
			b=cin.nextInt();
			ans=1;
			if(a==0&&b==0) break;
			for(i=1;i<=b;i++)
			{
				ans=ans*a%9;
			}
			if(ans==0) ans=9;
			System.out.println(ans);
		}
	}
}