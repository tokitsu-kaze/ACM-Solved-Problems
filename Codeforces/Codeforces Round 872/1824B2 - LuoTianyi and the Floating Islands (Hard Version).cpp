#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=1e9+7;
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
ll C(int n,int m)
{
	if(m>n||m<0||n<0) return 0;
	return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
ll A(int n,int m)
{
	if(m>n||m<0||n<0) return 0;
	return 1ll*fac[n]*invfac[n-m]%mod;
}
vector<int> mp[MAX];
int sz[MAX],n,k;
ll ans;
void dfs(int x,int fa)
{
	sz[x]=1;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		sz[x]+=sz[to];
		ans=(ans+C(sz[to],k/2)*C(n-sz[to],k/2))%mod;
	}
}
int main()
{
	init_comb(MAX-10);
	int i,a,b;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	ans=0;
	dfs(1,0);
	if(k&1) puts("1");
	else printf("%lld\n",(ans*inv(C(n,k))+1)%mod);
	return 0;
}
/*
先考虑k<=3的easy版本。
考虑奇数情况，好点只能是k个点中的1个，发现答案为1；
考虑偶数情况，把增量列式子，
发现对于一条边，一定是一边选k/2，另一边也选k/2，
把好点转化成好边的期望，最终每条边都会多贡献一个点，所以点期望=边期望+1。
感觉有点像中位数。
*/
