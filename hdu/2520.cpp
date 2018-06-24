////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-06 15:55:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2520
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a;
	while(~scanf("%d",&n))
	{
		while(n--)
		{
			scanf("%d",&a);
			printf("%d\n",(a%10000)*(a%10000)%10000);
		}
	}
	return 0;
}