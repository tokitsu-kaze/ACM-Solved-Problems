package work;

import java.io.*;
import java.math.*;
import java.util.*;

public class Main
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in); 
		Plalindrome aa = new Plalindrome();
		String str = null; 
		System.out.println("请输入您想输入的字符串："); 
		str = s.next(); 
		System.out.println(aa.isHuiWen(str));
	}
}