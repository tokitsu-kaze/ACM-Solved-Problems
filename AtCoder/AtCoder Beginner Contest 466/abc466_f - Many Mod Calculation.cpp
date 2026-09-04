#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i;
	ll x,ans,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld",&n,&x);
		map<ll,ll> mp;
		mp[x]=1;
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&x);
			auto it=mp.lower_bound(x);
			for(;it!=mp.end();it=mp.erase(it))
			{
				a=(*it).first;
				b=(*it).second;
				ans+=(a/x)*b;
				mp[x-1]+=(a/x)*b;
				a%=x;
				if(a) mp[a]+=b;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
