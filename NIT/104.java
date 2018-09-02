import java.util.*;
import java.math.*;
import java.io.*;



public class Main
{
	static void isPalindrome(String s)
	{
		String tmp=new StringBuffer(s).reverse().toString();
		if(s.equals(tmp)) System.out.printf("Yes\n");
		else System.out.printf("No\n");
	}
    public static void main(String[] args)
    {
    	Scanner cin=new Scanner(System.in);
    	String s;
    	while(cin.hasNext())
    	{
    		s=cin.nextLine();
        	isPalindrome(s);
    	}
    }
}