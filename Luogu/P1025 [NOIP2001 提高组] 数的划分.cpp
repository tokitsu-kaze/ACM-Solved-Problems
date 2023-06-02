#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[8][205][205];
int main()
{
	int n,k,i,j,x,y;
	ll ans;
	scanf("%d%d",&n,&k);
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++) dp[1][i][i]=1;
	for(i=2;i<=k;i++)
	{
		for(j=i;j<=n;j++)
		{
			for(x=1;x<=j;x++)
			{
				for(y=x;x+y<=j;y++)
				{
					dp[i][j][y]+=dp[i-1][j-y][x];
				}
			}
		}
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		ans+=dp[k][n][i];
//		printf("%d %d %d %d\n",k,n,i,dp[k][n][i]);
	}
	printf("%lld\n",ans);
	return 0;
}
