#include <bits/stdc++.h>
using namespace std;
int dp[105][55][55],mp[55][55];
int main()
{
	int n,m,i,j,k,tmp;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&mp[i][j]);
		}
	}
	memset(dp,0,sizeof dp);
	dp[0][1][1]=mp[1][1];
	for(k=1;k<=n+m-2;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				tmp=max({dp[k-1][i][j],
						 dp[k-1][i-1][j],
						 dp[k-1][i][j-1],
						 dp[k-1][i-1][j-1]});
				
				if(i==j)
				{
					if(k-i+2>=1)
					{
						dp[k][i][j]=tmp+mp[i][k-i+2];
					}
				}
				else
				{
					if(k-i+2>=1 && k-j+2>=1)
					{
						dp[k][i][j]=tmp+mp[i][k-i+2]+mp[j][k-j+2];
					}
				}
			}
		}
	}
	printf("%d\n",dp[n+m-2][n][n]);
	return 0;
}
