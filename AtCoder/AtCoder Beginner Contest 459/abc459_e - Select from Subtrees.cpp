#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
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
ll inv(ll x){return qpow(x,mod-2);}
int fac[MAX],invfac[MAX];
void init_comb(int n)
{
	assert(n<MAX);
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
	invfac[n]=inv(fac[n]);
	for(int i=n-1;~i;i--) invfac[i]=1ll*invfac[i+1]*(i+1)%mod;
}
vector<int> mp[MAX];
int c[MAX],d[MAX];
ll sz[MAX],ans;
ll C(ll n,ll m)
{
	if(m>n||m<0||n<0) return 0;
	ll res=invfac[m];
	while(m--)
	{
		res=res*(n%mod)%mod;
		n--;
	}
	return res;
}
void dfs(int x)
{
	sz[x]=c[x];
	for(auto &to:mp[x])
	{
		dfs(to);
		sz[x]+=sz[to];
	}
	ans=ans*C(sz[x],d[x])%mod;
	sz[x]-=d[x];
}
int main()
{
	init_comb(1e6);
	int n,i,fa;
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{
		scanf("%d",&fa);
		mp[fa].push_back(i);
	}
	for(i=1;i<=n;i++) scanf("%d",&c[i]);
	for(i=1;i<=n;i++) scanf("%d",&d[i]);
	ans=1;
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
