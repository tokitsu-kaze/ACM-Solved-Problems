////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-28 21:22:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2077
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1404KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main ()  
{
    long long n,m,i,a[25];
    a[0]=0;
    a[1]=2;
    for(i=2;i<=20;i++)
    {
		a[i]=3*a[i-1]+2;
	}
    while(~scanf("%lld",&n))
	{
		while(n--)
		{
			scanf("%lld",&m);
			printf("%lld\n",a[m-1]+2);
		}
	}
    return 0;  
}
