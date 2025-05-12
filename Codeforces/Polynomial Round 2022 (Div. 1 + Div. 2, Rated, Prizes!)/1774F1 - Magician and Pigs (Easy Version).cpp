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
map<ll,ll> mp;
ll multag,invmultag,hptag;
int main()
{
	int n,i,op,x;
	ll ans;
	mp.clear();
	multag=1;
	invmultag=inv(multag);
	hptag=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d",&x);
			(mp[x+hptag]+=invmultag)%=mod;
		}
		else if(op==2)
		{
			scanf("%d",&x);
			hptag+=x;
		}
		else
		{
			if(hptag)
			{
				if(hptag>2e5) continue;
				map<ll,ll> tmp=mp;
				for(auto &it:tmp)
				{
					if(it.first>hptag) (mp[it.first+hptag]+=it.second)%=mod;
					else mp.erase(it.first);
				}
				hptag*=2;
			}
			else
			{
				multag=multag*2%mod;
				invmultag=inv(multag);
			}
		}
	}
	ans=0;
	for(auto &it:mp)
	{
		if(it.first<=hptag) continue;
		ans=(ans+it.second*multag)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
