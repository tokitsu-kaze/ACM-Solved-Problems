////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-05 10:09:10
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2050
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1448KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,m,i,j;
	int a[10100];
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			a[1]=2;
			scanf("%d",&m);
			for(j=2;j<=m;j++)
			{
				a[j]=a[j-1]+4*(j-1)+1;
			}
			printf("%d\n",a[m]);
		}
	}
	return 0;
}