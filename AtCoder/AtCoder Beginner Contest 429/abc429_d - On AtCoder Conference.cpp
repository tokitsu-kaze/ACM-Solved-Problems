#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int main()
{
	int n,i;
	ll m,ans,x,tmp,c;
	scanf("%d%lld%lld",&n,&m,&c);
	map<ll,ll> mp;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		if(x==0) x=m;
		mp[x]++;
	}
	vector<ll> pos,cnt;
	pos.push_back(0);
	cnt.push_back(0);
	for(auto &it:mp)
	{
		pos.push_back(it.first);
		cnt.push_back(it.second);
	}
	for(auto &it:mp)
	{
		pos.push_back(it.first+m);
		cnt.push_back(it.second);
	}
	for(auto &it:mp)
	{
		pos.push_back(it.first+2*m);
		cnt.push_back(it.second);
	}
	for(i=1;i<cnt.size();i++) cnt[i]+=cnt[i-1];
	ans=0;
	for(i=1;i<pos.size();i++)
	{
		tmp=(*lower_bound(cnt.begin(),cnt.end(),cnt[i-1]+c))-cnt[i-1];
		ans+=(pos[i]-pos[i-1])*tmp;
		if(pos[i]>=m)
		{
			ans-=(pos[i]-m)*tmp;
			break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
