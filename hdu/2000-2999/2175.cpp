////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-28 22:14:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2175
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1404KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int m,n;
	while(~scanf("%d%d",&n,&m))
	{
		if(n==0&&m==0) break;
		n=1;
		while(m%2==0)
		{
			m>>=1;
			n++;
		}
		printf("%d\n",n);
	}
	return 0;
}