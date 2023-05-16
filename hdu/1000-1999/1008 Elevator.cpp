////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-07 22:33:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1008
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1412KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
    int n,s,i,a,b;
    while(~scanf("%d",&n))
    {
		if(n==0) break;
		s=0;
		b=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(b<a)
			{
				for(;b<a;b++)
				{
					s=s+6;
				}
			}
			else if(b>a)
			{
				for(;b>a;b--)
				{
					s=s+4;
				}
			}
		}
		s=s+5*n;
		printf("%d\n",s);
    }
    return 0;
}