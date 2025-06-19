#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
ll qpow(ll a,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int cnt[MAX];
ll dp[MAX][2][2];
int main()
{
	int T,n,i,x,L,now;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		L=n+5;
		for(i=0;i<=L+3;i++) cnt[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			x++;
			if(x<=L) cnt[x]++;
		}
		for(i=0;i<=L;i++) memset(dp[i],0,sizeof dp[i]);
		dp[0][0][0]=1;
		ans=now=0;
		for(i=1;i<=L;i++)
		{
			now+=cnt[i];
			if(cnt[i]>0)
			{
				dp[i][1][0]=(dp[i-1][0][0]+dp[i-1][1][0])*(qpow(2,cnt[i])-1)%mod;
				dp[i][1][1]=(dp[i-1][0][1]+dp[i-1][1][1])*(qpow(2,cnt[i])-1)%mod;
			}
			dp[i][0][1]=(dp[i][0][1]+dp[i-1][0][0])%mod;
			dp[i][1][1]=(dp[i][1][1]+dp[i-1][1][0])%mod;
			ans=(ans+dp[i][1][1]*i%mod*qpow(2,n-now-cnt[i+1]))%mod;
			ans=(ans+dp[i][0][1]*i%mod*(qpow(2,n-now-cnt[i+1])-1))%mod;
//			printf("%d %lld %lld %lld\n",i,dp[i][1][0],dp[i][1][1],ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

