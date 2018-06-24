////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-01 16:10:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1090
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1484KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a[10000],b[10000],i;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
		}
		for(i=0;i<n;i++)
		{
			printf("%d\n",a[i]+b[i]);
		}
	}
	return 0;
}