////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-24 17:52:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1249
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1404KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a,s,i;
	while(~scanf("%d",&n))
	{
		while(n--)
		{
			s=2;
			scanf("%d",&a);
			for(i=2;i<=a;i++)
			{
				s+=6*(i-1);
			}
			printf("%d\n",s);
		}
	}
}