#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3000+10;
ll dp[MAX][MAX],mx[MAX][MAX],a[MAX];
int main()
{
	int n,k,i,j;
	ll ans;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	memset(dp,-0x3f,sizeof dp);
	memset(mx,-0x3f,sizeof mx);
	ans=-4e18;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			dp[i][j]=max(a[i],mx[max(0,min(i-1,j-k))][i])+a[j];
			mx[i][j]=max(mx[i-1][j],dp[i][j]);
			ans=max(ans,dp[i][j]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
/*
dp[i][j]表示上一个选i，当前选j。
转移做个前缀max优化。
*/
