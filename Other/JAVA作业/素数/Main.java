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
				if(isPrime(num)) System.out.println(num + "��������");
				else System.out.println(num + "����������");
			}
			catch (Exception e)
			{
				System.out.println("����������");
				cin=new Scanner(System.in);
			}
		}
	}
}

