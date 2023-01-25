#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<string> VS;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
/********************************* std-head *********************************/
ll n;
ll f(ll x)
{
	return n/x+x-1;
}
int main()
{
	int T;
	ll L,R,sq,l,r,mid;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&n,&L,&R);
		vector<pair<ll,ll> > res;
		sq=sqrt(n+0.5);
		if(sq>=L&&sq<=R) res.pb(MP(f(sq),sq));
		if(sq+1>=L&&sq+1<=R) res.pb(MP(f(sq+1),sq+1));
		res.pb(MP(f(L),L));
		res.pb(MP(f(R),R));
		sort(all(res));
		
		l=L;
		r=res[0].se;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(f(mid)<=res[0].fi) r=mid;
			else l=mid+1;
		}
		printf("%lld\n",l);
	}
	return 0;
}


