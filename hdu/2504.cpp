////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-06 15:17:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2504
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define min(a,b)((a)>(b)?(b):(a))
int gcd(int a, int b)
{
	int c;
	for(c=min(a,b);c>1;c--)
	{
		if(a%c==0&&b%c==0) break;
	}
	return c;
}
int main()
{
	int n,a,b,i;
	while(~scanf("%d",&n))
	{
		while(n--)
		{
			scanf("%d%d",&a,&b);
			for(i=b+1;i<=a;i++)
			{
				if(i%b==0&&a%i!=0)
				{
					if(b==gcd(a,i)) break;
				}
			}
			if(i>=a)
			{
				for(i=i+1;;i++)
				{
					if(i%b==0)
					{
						if(b==gcd(a,i)) break;
					}
				}
			}
			printf("%d\n",i);
		}
	}
	return 0;
}