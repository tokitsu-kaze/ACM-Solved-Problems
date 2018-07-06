package work;


public class Plalindrome
{
	private String str;
	public static boolean isHuiWen(String str)
	{
		StringBuilder b = new StringBuilder(str);
		String c = b.reverse().toString();
		if(c==str) return true;
		else return false;
	}
}
