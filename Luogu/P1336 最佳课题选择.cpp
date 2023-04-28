#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[22][202];
ll cal(ll a,ll b)
{
	ll res=1;
	for(int i=1;i<=b;i++) res*=a;
	return res;
}
int main()
{
	int n,m,i,j,k,a,b;
	scanf("%d%d",&n,&m);
	memset(dp,0x3f,sizeof dp);
	dp[0][0]=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		for(j=0;j<=n;j++)
		{
			dp[i][j]=dp[i-1][j];
			for(k=1;k<=j;k++)
			{
				dp[i][j]=min(dp[i][j],dp[i-1][j-k]+a*cal(k,b));
			}
		}
	}
	printf("%lld\n",dp[m][n]);
	return 0;
}
