////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-28 21:33:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1995
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main ()  
{
	__int64 n,a,b;
    while(~scanf("%I64d",&n))
	{
		while(n--)
		{
			scanf("%d%d",&a,&b);
			printf("%I64d\n",1LL<<a-b);
		}
	}
    return 0;  
}