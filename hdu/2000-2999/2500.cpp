////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-01 15:39:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2500
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1424KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,m[101],i,j,h;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&m[i]);
		}
		for(i=0;i<n;i++)
		{
			for(j=3*m[i];j>0;j--)
			{
				for(h=m[i];h>0;h--)
				{
					printf("HDU");
				}
				printf("\n");
			}
		}
	}
	return 0;
}