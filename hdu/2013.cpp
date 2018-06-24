////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-09-28 21:03:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2013
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,s;
	while(~scanf("%d",&n))
	{
		s=1;
		for(n=n-1;n>0;n--)
		{
			s=(s+1)*2;
		}
		printf("%d\n",s);
	}
	return 0;
}