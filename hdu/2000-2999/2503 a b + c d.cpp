////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-06 14:39:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2503
////Problem Title: 
////Run result: Accept
////Run time:686MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define min(a,b)((a)>(b)?(b):(a))
int main()
{
	int n,a,b,c,d,e,f,i;
	while(~scanf("%d",&n))
	{
		while(n--)
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			if(b==d)
			{
				f=b;
				e=a+c;
			}
			else
			{
				f=b*d;
				e=a*d+b*c;
			}
			for(i=2;i<=min(e,f);i++)
			{
				if(e%i==0&&f%i==0)
				{
					e=e/i;
					f=f/i;
					i--;
				}
			}
			printf("%d %d\n",e,f);
		}
	}
	return 0;
}