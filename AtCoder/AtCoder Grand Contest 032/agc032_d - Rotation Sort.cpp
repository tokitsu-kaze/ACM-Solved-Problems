#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int p[MAX];
ll dp[MAX][MAX];
int main()
{
	int n,i,j,a,b;
	ll ans;
	scanf("%d%d%d",&n,&a,&b);
	for(i=1;i<=n;i++) scanf("%d",&p[i]);
	memset(dp,0x3f,sizeof dp);
	dp[1][1]=0;
	dp[1][0]=a;
	for(i=2;i<=n;i++)
	{
		dp[i][0]=dp[i-1][0]+a;
		dp[i][i]=dp[i-1][0];
		for(j=1;j<i;j++)
		{
			if(p[i]>p[j])
			{
				dp[i][i]=min(dp[i][i],dp[i-1][j]);
				dp[i][j]=min(dp[i][j],dp[i-1][j]+a);
			}
			else dp[i][j]=min(dp[i][j],dp[i-1][j]+b);
		}
	}
	ans=LLINF;
	for(i=0;i<=n;i++) ans=min(ans,dp[n][i]);
	printf("%lld\n",ans);
	return 0;
}
/*
hint1：动来动去的题，考虑不动的东西。
hint2：先考虑a=b的情况。
发现如果a=b，它就是求一下LIS。
dp[i][j]表示前 i 个数，LIS 的最后一个数为 j 的答案。
如果 pi<pj，pi 只能左移；
如果 pi>pj，pi 可以不动或者右移。
如果 pi>pj 并且又是要动的，说明在 pi 的右边存在不动的数 pk，满足 pj<pk<pi。
所以此时 pi 要往右移。
如果不存在的话，pi 不动是最优的。
*/
