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
const double eps=1e-4;
const int MAX=2e5+10;
const ll mod=1e9+7;
struct node
{
	ll v,cost;
	friend bool operator<(node a,node b)
	{
		if(a.cost==b.cost) return a.v<b.v;
		return a.cost<b.cost;
	}
}a[MAX],b[MAX];
map<ll,ll> mp;
map<ll,ll> ::iterator it;
int main()
{
	ll k,n,m,i,x,s,ans;
	while(~scanf("%lld%lld%lld",&k,&n,&m))
	{
		scanf("%lld%lld",&x,&s);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i].v);
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i].cost);
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld",&b[i].v);
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld",&b[i].cost);
		}
		mp.clear();
		sort(a,a+n);
		mp[a[0].cost]=a[0].v;
		for(i=1;i<n;i++)
		{
			mp[a[i].cost]=min(a[i].v,mp[a[i-1].cost]);
		}
		ans=x*k;
		for(i=0;i<m;i++)
		{
			if(b[i].cost>s) continue;
			if(b[i].v>=k)
			{
				ans=0;
				break;
			}
			ans=min(ans,x*(k-b[i].v));
			it=mp.upper_bound(s-b[i].cost);
			if(it==mp.begin()) continue;
			it--;
			ans=min(ans,(it->se)*(k-b[i].v));
		}
		it=mp.upper_bound(s);
		if(it==mp.begin());
		else
		{
			it--;
			ans=min(ans,(it->se)*k);
		}
		printf("%lld\n",ans);
	}
	return 0;
}