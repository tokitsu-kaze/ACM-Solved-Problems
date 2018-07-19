#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-10;
const int MAX=5e4+10;
const ll mod=1e9+7;
vector<pair<ll,ll> >a,b;
int main()
{
	ll n,s,i,w,v1,v2,ans,x,y,ta,tb;
	while(~scanf("%lld%lld",&n,&s))
	{
		x=y=ans=0;
		a.clear();
		b.clear();
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld%lld",&w,&v1,&v2);
			if(v1>v2)
			{
				a.pb(MP(v1-v2,w));
				x+=w;
				ans+=w*v1;
			}
			else
			{
				b.pb(MP(v2-v1,w));
				y+=w;
				ans+=w*v2;
			}
		}
		x%=s;
		y%=s;
		if(x+y>s)
		{
			printf("%lld\n",ans);
			continue;
		}
		sort(all(a));
		sort(all(b));
		ta=tb=0;
		for(i=0;i<sz(a)&&x;i++)
		{
			ta+=a[i].fi*min(a[i].se,x);
			x-=min(a[i].se,x);
		}
		for(i=0;i<sz(b)&&y;i++)
		{
			tb+=b[i].fi*min(b[i].se,y);
			y-=min(b[i].se,y);
		}
		ans-=min(ta,tb);
		printf("%lld\n",ans);
	}
	return 0;
}