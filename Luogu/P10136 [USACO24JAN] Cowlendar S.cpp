#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
set<ll> s;
ll cal(ll x)
{
	set<ll> tmp;
	for(auto &it:s)
	{
		tmp.insert(it%x);
		if(tmp.size()>3) return 0;
	}
	return x;
}
int main()
{
	int n,i,j;
	ll ans,x,limt,g,sq;
	scanf("%d",&n);
	s.clear();
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		s.insert(x);
	}
	limt=*s.begin()/4;
	if(s.size()<=3)
	{
		printf("%lld\n",(1+limt)*limt/2);
		return 0;
	}
	g=0;
	i=0;
	set<ll> tmp;
	for(auto &it1:s)
	{
		j=0;
		for(auto &it2:s)
		{
			if(it1-it2) tmp.insert(abs(it1-it2));
			j++;
			if(j==4) break;
		}
		i++;
		if(i==4) break;
	}
	set<ll> res;
	res.insert(1);
	res.insert(2);
	res.insert(3);
	sq=sqrt(*tmp.rbegin()+1);
	for(i=1;i<=sq;i++)
	{
		for(auto &it:tmp)
		{
			if(it%i==0)
			{
				res.insert(i);
				res.insert(it/i);
			}
		}
	}
	ans=0;
	for(auto &it:res)
	{
		if(it>limt) continue;
		ans+=cal(it);
	}
	printf("%lld\n",ans);
	return 0;
}
