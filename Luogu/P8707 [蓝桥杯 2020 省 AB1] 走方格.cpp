#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,m,i,j;
	ll dp[33][33];
	scanf("%d%d",&n,&m);
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(i%2==0&&j%2==0) continue;
			if(i==1&&j==1) dp[i][j]=1;
			else dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	printf("%lld\n",dp[n][m]);
	return 0;
}
