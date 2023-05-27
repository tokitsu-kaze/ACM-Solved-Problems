#include <bits/stdc++.h>
using namespace std;
int dp[16][16][16];
int main()
{
	int n,k,len,l,r,i,j,v,x;
	scanf("%d%d",&n,&k);
	memset(dp,-1,sizeof dp);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		dp[i][i][0]=x;
	}
	for(len=2;len<=n;len++)
	{
		for(l=1;l+len-1<=n;l++)
		{
			r=l+len-1;
			for(j=0;j<=k;j++)
			{
				for(v=0;v<=j;v++)
				{
					for(i=l+1;i<=r;i++)
					{
						if(dp[l][i-1][v]!=-1 && dp[i][r][j-v]!=-1)
						{
							dp[l][r][j]=max(dp[l][r][j],dp[l][i-1][v]+dp[i][r][j-v]);
						}
						if(v>0 && dp[l][i-1][v-1]!=-1 && dp[i][r][j-v]!=-1)
						{
							dp[l][r][j]=max(dp[l][r][j],dp[l][i-1][v-1]*dp[i][r][j-v]);
						}
					}
				}
			}
		}
	}
	printf("%d\n",dp[1][n][k]);
	return 0;
}
