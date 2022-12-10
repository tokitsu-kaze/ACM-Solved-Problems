/*
 * Author: tokitsukaze
 * Created: 2018/9/26 21:01
 */
using System;
using System.Linq;
class Program
{
    static void Main()
    {
        var next=Console.ReadLine();
        while(!string.IsNullOrWhiteSpace(next))
        {
        	int pre,precnt,cnt,ok;
        	int n=Convert.ToInt32(next);
        	var a=Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        	precnt=pre=-1;
        	cnt=0;
        	ok=1;
        	for(int i=0;i<n;i++)
        	{
        		if(a[i]!=pre)
        		{
        			if(cnt>0)
        			{
        				if(precnt!=-1&&precnt!=cnt) ok=0;
        				precnt=cnt;
        				cnt=1;
        			}
        			else cnt++;
        		}
        		else cnt++;
        		pre=a[i];
        	}
        	if(precnt!=-1&&precnt!=cnt) ok=0;
        	Console.WriteLine(ok==1?"YES":"NO");
        	
            next=Console.ReadLine();
        }
    }
}

