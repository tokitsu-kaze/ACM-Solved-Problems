////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-20 22:27:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1032
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1404KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,i,count,max,n;
    while(~scanf("%d%d",&a,&b))
    {
		max=0;
		printf("%d %d ",a,b);
		if(a>b) swap(a,b);
		for(i=a;i<=b;i++)
		{
			count=1;
			n=i;
			while(n!=1)
			{
				if(n%2!=0) n=3*n+1;
				else n/=2;
				count++;
			}
			if(count>max) max=count;
		}
		printf("%d\n",max);
    }
    return 0;
}
