#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e7+10;
//x is a prime if prime[x]==x(x>=2)
const int V=2e7;
int p[MAX],tot,prime[MAX];
void init_prime()
{
	int i,j;
	tot=0;
	memset(prime,0,sizeof prime);
	prime[1]=1;
	for(i=2;i<=V;i++)
	{
		if(!prime[i]) prime[i]=p[tot++]=i;
		for(j=0;j<tot&&p[j]*i<=V;j++)
		{
			prime[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
}
int cnt[MAX];
ll dp[MAX];
int main()
{
	init_prime();
	int n,i,j,x;
	ll ans;
	scanf("%d",&n);
	memset(cnt,0,sizeof cnt);
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
		dp[x]+=x;
	}
	for(i=0;i<tot;i++)
	{
		for(j=V/p[i];j;j--) cnt[j]+=cnt[j*p[i]];
	}
	ans=0;
	for(i=V;i;i--)
	{
		for(j=0;j<tot&&p[j]*i<=V;j++) dp[i]=max(dp[i],dp[p[j]*i]+1LL*i*(cnt[i]-cnt[p[j]*i]));
		ans=max(ans,dp[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
