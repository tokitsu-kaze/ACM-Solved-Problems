////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-21 22:01:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1060
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1424KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
    int n,t;
    double s;
    while(~scanf("%I64d",&t))
    {
		while(t--)
		{
			scanf("%d",&n);
			s=n*log10((double)n);
			s-=(long long)s;
			printf("%d\n",(int)pow(10,s));
		}
	}
    return 0;
}