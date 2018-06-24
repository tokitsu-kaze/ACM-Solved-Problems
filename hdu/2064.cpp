////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-28 21:07:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2064
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1400KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main ()  
{
    __int64 n,i,a[40];
    a[1]=2;
    for(i=2;i<=35;i++)
    {
		a[i]=3*a[i-1]+2;
	}
    while(~scanf("%I64d",&n))
	{
		printf("%I64d\n",a[n]);
	}
    return 0;  
}