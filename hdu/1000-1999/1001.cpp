////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-09-23 20:55:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1001
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int n,i,s=0;
    while(scanf("%d",&n)!=EOF)
    {
		for(i=0;i<=n;i++)
		{
			s=s+i;
		}
		printf("%d\n\n",s);
		s=0;
	}
    return 0;
}