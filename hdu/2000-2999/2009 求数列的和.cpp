////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-09-26 23:33:19
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2009
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1440KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
	int m,i;
	double s,n;
	while(~scanf("%lf%d",&n,&m))
	{
		s=0;
		for(i=1;i<=m;i++)
		{
			s=s+n;
			n=sqrt(n);
		}
		printf("%.2lf\n",s);
	}
	return 0;
} 