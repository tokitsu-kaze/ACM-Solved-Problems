#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=2e9+1;
const int MAX=5e5+10;
int main()
{
	int n,i,x;
	ll ans;
	scanf("%d",&n);
	set<int> s;
	s.insert(0);
	s.insert(INF);
	ans=2LL*INF;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		auto nex=s.lower_bound(x);
		auto pre=nex;
		pre--;
		
		auto nexx=nex;
		nexx++;
		if(nexx!=s.end())
		{
			ans-=min(*nexx-*nex,*nex-*pre);
			ans+=min(*nexx-*nex,*nex-x);
		}
		else
		{
			ans-=*nex-*pre;
			ans+=*nex-x;
		}
			
		if(pre!=s.begin())
		{
			auto ppre=pre;
			ppre--;
			ans-=min(*pre-*ppre,*nex-*pre);
			ans+=min(*pre-*ppre,x-*pre);
		}
		else
		{
			ans-=*nex-*pre;
			ans+=x-*pre;
		}
		ans+=min(*nex-x,x-*pre);
		s.insert(x);
		
		auto en=s.end();
		en--;
		auto pen=en;
		pen--;
		printf("%lld\n",ans-(*en-*pen));
	}
	return 0;
}
