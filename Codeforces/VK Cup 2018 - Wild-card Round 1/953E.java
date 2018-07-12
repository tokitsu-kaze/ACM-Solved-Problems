import java.io.*;
import java.math.*;
import java.util.*;

public class Main 
{
	public static void main (String[] args)
	{
		Scanner cin=new Scanner(System.in);
		int top,i,x,n;
		int[] s=new int[200010];
		while(cin.hasNext())
		{
			top=0;
			n=cin.nextInt();
			for(i=1;i<=n;i++)
			{
				x=cin.nextInt();
				s[top++]=x;
				while(top>1&&s[top-1]==s[top-2])
				{
					top--;
					s[top-1]++;
				}
			}
			System.out.printf("%d\n", top);
			StringWriter str=new StringWriter(2000010);
	        for (i=0;i<top;i++) {
	            if (i>0) str.append(' ');
	            str.write(""+s[i]);
	        }
	        System.out.println(str.toString());
		}
	}
}