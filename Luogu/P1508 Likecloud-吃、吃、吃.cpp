#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
ll mp[205][205],dp[205][205];
int main()
{
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&mp[i][j]);
		}
	}
	memset(dp[0],0,sizeof dp[0]);
	dp[0][0]=dp[0][m+1]=-LLINF;
	for(i=1;i<=n;i++)
	{
		dp[i][0]=dp[i][m+1]=-LLINF;
		for(j=1;j<=m;j++)
		{
			dp[i][j]=max({dp[i-1][j-1],
						  dp[i-1][j],
						  dp[i-1][j+1]})+mp[i][j];
		}
	}
	printf("%lld\n",max({dp[n][(m+1)/2],
					   dp[n][(m+1)/2-1],
					   dp[n][(m+1)/2+1]}));
	return 0;
}
