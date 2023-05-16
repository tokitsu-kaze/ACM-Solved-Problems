////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-04 23:36:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1108
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define min(a,b)((a)>(b)?(b):(a))
int main()
{
	int a,b,i;
	while(~scanf("%d%d",&a,&b))
	{
		for(i=min(a,b);i>0;i--)
		{
			if(a%i==0&&b%i==0) break;
		}
		printf("%d\n",a/i*b);
	}
	return 0;
}