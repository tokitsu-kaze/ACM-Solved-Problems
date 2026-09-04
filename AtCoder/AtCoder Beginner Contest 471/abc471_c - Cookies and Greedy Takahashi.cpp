#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,i,x;
	ll ans;
	scanf("%d",&n);
	set<ll> s;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		s.insert(x);
	}
	s.insert(-LLINF);
	s.insert(LLINF);
	ans=0;
	x=0;
	for(i=1;i<=n;i++)
	{
		auto nex=s.upper_bound(x);
		auto pre=nex;
		pre--;
		if(x-*pre<=*nex-x)
		{
			ans+=x-*pre;
			x=*pre;
			s.erase(pre);
		}
		else
		{
			ans+=*nex-x;
			x=*nex;
			s.erase(nex);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
