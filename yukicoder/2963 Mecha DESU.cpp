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
int cnt[MAX],res[MAX];
int main()
{
	int n,m,k,i,j,x;
	ll fz,fm;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++) cnt[i]=res[i]=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j+=i) res[j]+=cnt[i];
	}
	fz=0;
	fm=qpow(m,k);
	for(i=1;i<=n;i++)
	{
		fz=(fz+fm-qpow(m-res[i],k)+mod)%mod;
	}
	printf("%lld\n",fz*inv(fm)%mod);
	return 0;
}

