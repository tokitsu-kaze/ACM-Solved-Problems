////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-28 12:40:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1587
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1404KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <limits.h>
int main()
{
	int n,m,a,min;
	while(~scanf("%d%d",&n,&m))
	{
		min=INT_MAX;
		while(n--)
		{
			scanf("%d",&a);
			if(a<min) min=a;
		}
		printf("%d\n",m/min);
	}
	return 0;
}