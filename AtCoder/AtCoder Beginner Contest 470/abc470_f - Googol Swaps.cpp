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
char s[MAX];
int vis[MAX],cnt[26];
void dfs(int x)
{
	if(vis[x]) return;
	vis[x]=1;
	cnt[s[x]-'a']++;
	for(auto &to:mp[x]) dfs(to);
}
int main()
{
	int n,m,i,j,a,b,tot,f;
	ll ans;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		vis[i]=0;
	}
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	init_comb(n);
	ans=1;
	f=0;
	for(i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		memset(cnt,0,sizeof cnt);
		dfs(i);
		tot=0;
		for(j=0;j<26;j++)
		{
			ans=ans*invfac[cnt[j]]%mod;
			tot+=cnt[j];
			if(cnt[j]>1) f=1;
		}
		ans=ans*fac[tot]%mod;
	}
	if(f==0) ans=ans*inv(2)%mod;
	printf("%lld\n",ans);
	return 0;
}
/*
算各自连通块的方案数再乘起来。
最后要求交换偶数次，我怎么完全不会处理这个东西。
好像其实就是，
如果所有连通块里都没有相同元素，交换奇数次和偶数次的排列一定互不相同，所以直接算总的然后/2；
如果存在某个连通块里有，那显然这两个相同元素可以随便换，就能解除整体的奇偶限制。
*/
