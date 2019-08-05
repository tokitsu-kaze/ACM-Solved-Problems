////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-28 21:40:35
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1996
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1424KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main ()  
{
	__int64 n,m;
    while(~scanf("%I64d",&n))
	{
		while(n--)
		{
			scanf("%I64d",&m);
			printf("%.0lf\n",pow(3,m));
		}
	}
    return 0;  
}