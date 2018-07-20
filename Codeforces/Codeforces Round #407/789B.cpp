#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	ll b,q,l,m,i,x,ans;
	while(~scanf("%lld%lld%lld%lld",&b,&q,&l,&m))
	{
		map<ll,ll> mp;
		for(i=0;i<m;i++)
		{
			scanf("%lld",&x);
			mp[x]=1;
		}
		if(q==0)
		{
			if(!mp[0]&&abs(b)<=l) puts("inf");
			else if(!mp[b]&&abs(b)<=l) puts("1");
			else puts("0");
			continue;
		}
		if(b==0)
		{
			if(!mp[0]) puts("inf");
			else puts("0");
			continue;
		}
		ans=0;
		if(q==-1&&!mp[-b]&&abs(b)<=l) ans++;
		while(abs(b)<=l)
		{
			if(!mp[b]) ans++;
			if(q==-1||q==1) break;
			b*=q;
		}
		if((q==-1||q==1)&&ans) puts("inf");
		else printf("%lld\n",ans);
	}
	return 0;
}