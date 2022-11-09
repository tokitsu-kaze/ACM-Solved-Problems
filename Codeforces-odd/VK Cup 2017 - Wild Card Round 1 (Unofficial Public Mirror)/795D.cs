/*
 * Author: tokitsukaze
 * Created: 2019/1/16 16:36
 */
using System;
using System.Linq;
using System.Collections;
using System.Threading;
class Problem05A
{
    static void Main()
    {
        var next=Console.ReadLine();
        while(!string.IsNullOrWhiteSpace(next))
        {
            var tmp=next.Split(' ').Select(int.Parse).ToArray();
        	var a=Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        	var b=Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        	int n,l,r,flag;
        	n=tmp[0];
        	l=tmp[1];
        	r=tmp[2];
        	flag=0;
        	for(int i=0;i<l-1;i++)
        	{
        		if(a[i]!=b[i]) flag=1;
        	}
        	for(int i=r;i<n;i++)
        	{
        		if(a[i]!=b[i]) flag=1;
        	}
        	ArrayList resa=new ArrayList();
        	ArrayList resb=new ArrayList();
        	for(int i=l-1;i<=r-1;i++)
        	{
        		resa.Add(a[i]);
        		resb.Add(b[i]);
        	}
        	resa.Sort();
        	resb.Sort();
        	if(resa.ToString()==resb.ToString());
        	else flag=1;
        	Console.WriteLine(flag==0?"TRUTH":"LIE");
            next=Console.ReadLine();
        }
    }
}

