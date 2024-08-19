#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll qpow(ll a,ll b,ll p)
{
	ll res=1;
	while(b>0)
	{
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
ll inv(ll x,ll p){return qpow(x,p-2,p);}
ll s[1010],d[1010],invs[1010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T,i,n,q,ans,cnt0;
	ll p,a,x,now,tmp;
	cin>>T;
	while(T--)
	{
		cin>>p>>a>>n>>q;
		unordered_map<ll,ll> mp;
		now=1;
		mp[now]=0;
		for(i=1;i<=200000;i++)
		{
			now=now*a%p;
			if(mp.count(now)) break;
			mp[now]=i;
		}
		cnt0=0;
		for(i=1;i<=n;i++)
		{
			cin>>s[i]>>d[i];
			if(s[i]) invs[i]=inv(s[i],p);
			else cnt0++;
		}
		while(q--)
		{
			cin>>x;
			if(x==0)
			{
				cout<<cnt0<<"\n";
				continue;
			}
			ans=0;
			for(i=1;i<=n;i++)
			{
				if(s[i]==0) continue;
				tmp=x*invs[i]%p;
				if(mp.count(tmp) && mp[tmp]<=d[i]) ans++;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
