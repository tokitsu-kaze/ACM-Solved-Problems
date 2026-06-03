#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=1e9+7;
int dp[31][31][1<<9];
int main()
{
	int n,m,k,i,j,l,s;
	scanf("%d%d%d",&n,&m,&k);
	memset(dp,0,sizeof dp);
	dp[1][0][0]=1;
	for(i=2;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			for(s=0;s<(1<<k);s++)
			{
				dp[i][j][s<<1]=(dp[i][j][s<<1]+dp[i-1][j][s])%mod;
			}
		}
		for(l=1;l<=k && i-l>=1;l++)
		{
			for(j=1;j<=m;j++)
			{
				for(s=0;s<(1<<(k+1));s++)
				{
					dp[i][j][s]=(dp[i][j][s]+dp[i][j-1][s^1^(1<<l)])%mod;
				}
			}
		}
	}
	printf("%d\n",dp[n][m][0]);
	return 0;
}
/*
dp[i][j][s]表示前i个点j条边，后k个点度数奇偶性状态为s的方案数。
每次新加一个点，让新的往旧的连，这样不会重复。
转移时要考虑这个点连0条边的情况。
注意转移顺序。
*/
