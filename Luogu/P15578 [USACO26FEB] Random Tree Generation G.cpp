#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=1e9+7;
struct Combinatorics
{
	vector<int> inv_e,fac,invfac;
	int last_n;
	Combinatorics(){last_n=0;init(1);}
	void init(int n)
	{
		if(n<=last_n) return;
		inv_e.resize(n+1);
		fac.resize(n+1);
		invfac.resize(n+1);
		if(last_n==0)
		{
			inv_e[1]=1;
			fac[0]=fac[1]=1;
			invfac[0]=invfac[1]=1;
			last_n=1;
		}
		for(int i=last_n+1;i<=n;i++)
		{
			inv_e[i]=1LL*(mod-mod/i)*inv_e[mod%i]%mod;
			fac[i]=1LL*fac[i-1]*i%mod;
			invfac[i]=1LL*invfac[i-1]*inv_e[i]%mod;
		}
		last_n=n;
	}
	ll qpow(ll a,ll b)
	{
		ll res=1;
		a=(a%mod+mod)%mod;
		while(b>0)
		{
			if(b&1) res=res*a%mod;
			a=a*a%mod;
			b>>=1;
		}
		return res;
	}
	ll inv(ll x)
	{
		assert(x>=1);
		if(x<=last_n) return inv_e[x];
		else return qpow(x%mod,mod-2);
	}
	ll C(int n,int m)
	{
		if(m>n||m<0||n<0) return 0;
		return 1LL*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
	}
	ll A(int n,int m)
	{
		if(m>n||m<0||n<0) return 0;
		return 1LL*fac[n]*invfac[n-m]%mod;
	}
}comb;
vector<int> mp[MAX];
int sz[MAX];
ll now,fz;
void dfs0(int x,int fa)
{
	sz[x]=1;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs0(to,x);
		sz[x]+=sz[to];
	}
	now=now*comb.inv(sz[x])%mod;
}
void dfs(int x,int fa)
{
	fz=(fz+now)%mod;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		now=now*sz[x]%mod;
		now=now*sz[to]%mod;
		sz[x]-=sz[to];
		sz[to]+=sz[x];
		now=now*comb.inv(sz[x])%mod;
		now=now*comb.inv(sz[to])%mod;
		
		dfs(to,x);
		
		now=now*sz[x]%mod;
		now=now*sz[to]%mod;
		sz[to]-=sz[x];
		sz[x]+=sz[to];
		now=now*comb.inv(sz[x])%mod;
		now=now*comb.inv(sz[to])%mod;
	}
}
int main()
{
	comb.init(2e5);
	int T,n,i,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		now=comb.fac[n];
		dfs0(1,0);
		fz=0;
		dfs(1,0);
		printf("%lld\n",fz*comb.invfac[n]%mod*comb.invfac[n-1]%mod);
	}
	return 0;
}
/*
总方案数是 n!*(n-1)!，转化为生成给定树的合法方案。
发现其实就是在求，固定根之后，树的拓扑序。
树的定根形态，限制了拓扑序的合法性；
合法拓扑序，就对应第一步生成顺序；
不同拓扑序，就对应不同标号。
然后换根dp即可。
*/
