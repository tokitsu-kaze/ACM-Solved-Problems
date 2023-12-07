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
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=3e5+10;
const ll mod=1e9+7;
struct node
{
	ll pos,v,end;
	friend bool operator <(node a,node b)
	{
		if(a.pos==b.pos) return a.end<b.end;
		return a.pos<b.pos;
	}
}a[MAX];
multiset<ll> s;
multiset<ll> ::iterator it;
int main()
{
	ll n,m,i,ans;
	while(~scanf("%lld%lld",&n,&m))
	{
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld",&a[i].pos,&a[i].v);
			a[i].end=a[i].pos+a[i].v;
		}
		sort(a,a+n);
		s.clear();
		s.insert(LLINF);
		ans=0;
		for(i=0;i<n;i++)
		{
			it=s.lower_bound(a[i].pos-m);
			if(*it>a[i].pos) ans++;
			else s.erase(it);
			s.insert(a[i].end);
		}
		printf("%lld\n",n-ans);
	}
	return 0;
}