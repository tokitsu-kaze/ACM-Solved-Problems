////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-17 21:30:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2084
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1480KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
int main()
{
	int n,m,i,j,a[101][101],dp[101][101];
    while(~scanf("%d",&n))
    {
        while(n--)
        {
			scanf("%d",&m);
			for(i=1;i<=m;i++)
			{
				for(j=1;j<=i;j++)
				{
					scanf("%d",&a[i][j]);
				}
			}
			for(i=1;i<=m;i++)
			{
				dp[m][i]=a[m][i];
			}
			for(i=m-1;i>=1;i--)
			{
				for(j=1;j<=i;j++)
				{
					dp[i][j]=max(dp[i+1][j]+a[i][j],dp[i+1][j+1]+a[i][j]);
				}
			}
			printf("%d\n",dp[1][1]);
		}
    }
    return 0;
}