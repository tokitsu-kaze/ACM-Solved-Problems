////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-05 13:43:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1061
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int pow2(int a)
{
	int b,c;
	b=a;
	a=a%10;
	c=1;
	while(b>0)
	{
		if(b%2!=0)
		{
			c=c*a%10;
		}
		a=a*a%10;
		b=b/2;
	}
	return c;
}
int main()
{
	int n,i,a;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			printf("%d\n",pow2(a));
		}
	}
	return 0;
}