////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-03 20:36:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2032
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1432KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a[100][100],i,j,s;
	while(~scanf("%d",&n))
	{
		for(i=0;i<=n+2;i++)
		{
			a[i][0]=1;
			a[i][i]=1;
			for(j=0;j<i-1;j++)
			{
				a[i][j]=a[i-1][j-1]+a[i-1][j];
			}
		}
		for(i=0;i<n+2;i++)
		{
			for(j=0;j<i-1;j++)
			{
				if(j>0) printf(" ");
				printf("%d",a[i][j]);
			}
			if(i>1)
			{
				printf("\n");
			}
		}
		printf("\n");
	}
	return 0;
}