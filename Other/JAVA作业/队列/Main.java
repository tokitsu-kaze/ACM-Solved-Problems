package work;

import java.io.*;
import java.math.*;
import java.util.*;


public class Main
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		Queue MyQueue =new Queue(10);
		for(int i=0;i<10;i++) MyQueue.AddQ(i);
		for(int i=0;i<10;i++) System.out.println(MyQueue.DeleteQ());
	}
}