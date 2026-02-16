#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<ll> mp[MAX],dp[MAX];
int p[MAX];
int n,m;
int ck(ll x)
{
	int i,j;
	if(x+mp[1][1]<p[1]) return 0;
	for(i=0;i<=n;i++) dp[i]=vector<ll>(m+1,-LLINF);
	dp[1][1]=x+mp[1][1]-p[1];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(i==1 && j==1) continue;
			if(dp[i-1][j]>=0) dp[i][j]=max(dp[i][j],dp[i-1][j]);
			if(dp[i][j-1]>=0) dp[i][j]=max(dp[i][j],dp[i][j-1]);
			dp[i][j]=dp[i][j]+mp[i][j]-p[i+j-1];
		}
	}
	return dp[n][m]>=0;
}
int main()
{
	int i,j;
	ll l,r,mid;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		mp[i]=vector<ll>(m+1);
		for(j=1;j<=m;j++) scanf("%lld",&mp[i][j]);
	}
	for(i=1;i<=n+m-1;i++) scanf("%d",&p[i]);
	l=0;
	r=2e14;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid)) r=mid;
		else l=mid+1;
	}
	printf("%lld\n",l);
	return 0;
}
