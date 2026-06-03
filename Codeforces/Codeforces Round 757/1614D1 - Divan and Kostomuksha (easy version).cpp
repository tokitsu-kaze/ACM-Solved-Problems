#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e6+10;
int cnt[MAX],now[MAX];
ll dp[MAX];
int main()
{
	int n,i,j,x,s;
	ll ans;
	scanf("%d",&n);
	memset(cnt,0,sizeof cnt);
	memset(now,0,sizeof now);
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
		now[x]++;
		dp[x]+=x;
	}
	ans=0;
	for(i=MAX-10;i;i--)
	{
		s=0;
		for(j=i;j<=MAX-10;j+=i) s+=cnt[j];
		for(j=i;j<=MAX-10;j+=i) dp[i]=max(dp[i],dp[j]+1LL*i*(s-now[j]));
		now[i]=s;
		ans=max(ans,dp[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
