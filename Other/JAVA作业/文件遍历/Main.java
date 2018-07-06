package work;

import java.io.*;
import java.math.*;
import java.util.*;


public class Main 
{
    public static void dfs(File file)
    {  
    	for(File f : file.listFiles())
    	{
    		if(f.isFile()) System.out.println(f.getName());  
    		else dfs(f);
    	}  
    }  
    public static void main(String[] args)
    {
        File f = new File("C:\\Users\\tokit\\Desktop\\ACM");
        dfs(f);
    }
}
