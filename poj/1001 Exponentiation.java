import java.math.*;
import java.util.*;

public class Main 
{
	public static void main (String[] args)
	{
		Scanner cin=new Scanner(System.in);
		BigDecimal a,ans;
		int i,n;
		while(cin.hasNext())
		{
			a=cin.nextBigDecimal();
			n=cin.nextInt();
			ans=a.pow(n).stripTrailingZeros();
			System.out.println(ans.toPlainString().replaceAll("^0", ""));
		}
	}
}