package work;

import java.math.*;
import java.io.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class Main 
{
	public static boolean isPrime(int a)
	{
        if(a<2) return false;
        for(int i=2;i<=Math.sqrt(a);i++)
        {
        	if(a%i==0) return false;
        }  
        return true;
    }  
	public static void main(String[] args)
	{
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext())
		{
			try
			{
				int num=cin.nextInt();
				if(isPrime(num)) System.out.println(num + "是素数！");
				else System.out.println(num + "不是素数！");
			}
			catch (Exception e)
			{
				System.out.println("请输入整数");
				cin=new Scanner(System.in);
			}
		}
	}
}

