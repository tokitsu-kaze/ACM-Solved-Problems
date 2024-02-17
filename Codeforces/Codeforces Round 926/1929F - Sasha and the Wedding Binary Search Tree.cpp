#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=5e5+10;
const ll mod=998244353;
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
ll fac[MAX],invfac[MAX];
void init(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	invfac[n]=inv(fac[n]);
	for(int i=n-1;~i;i--) invfac[i]=invfac[i+1]*(i+1)%mod;
}
ll C(ll n,ll m)
{
	if(m>n||m<0||n<0) return 0;
	ll res=1;
	for(int i=1;i<=m;i++)
	{
		res=res*n%mod;
		n--;
	}
	return res*invfac[m]%mod;
}
int l[MAX],r[MAX],val[MAX];
int v[MAX],tot;
void dfs(int x)
{
	if(x==-1) return;
	dfs(l[x]);
	v[++tot]=val[x];
	dfs(r[x]);
}
int main()
{
	int t,n,k,i,j;
	ll ans;
	init(MAX-10);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d%d%d",&l[i],&r[i],&val[i]);
		tot=0;
		dfs(1);
		v[0]=1;
		v[++tot]=k;
		i=0;
		ans=1;
		while(i<tot)
		{
			j=i+1;
			while(j<tot&&v[j]==-1) j++;
			ans=ans*C((v[j]-v[i]+1)+(j-i-1)-1,j-i-1)%mod;
			i=j;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

