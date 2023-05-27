////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-06 17:58:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2114
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1416KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,s;
	while(~scanf("%d",&n))
	{
		n=n%10000;
		s=((n*(n+1)/2%10000)*(n*(n+1)/2%10000))%10000;
		printf("%04d\n",s);
	}
	return 0;
}