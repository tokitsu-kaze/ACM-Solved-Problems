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
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
ll n,m;
bool check(ll x)
{
	if(x*(x+1)/2>=n-m) return 0;
	else return 1;
}
int main()
{
	ll l,r,mid;
	while(~scanf("%lld%lld",&n,&m))
	{
		if(n<=m)
		{
			printf("%lld\n",n);
			continue;
		}
		if(n==1)
		{
			puts("1");
			continue;
		}
		l=1;
		r=(ll)3e9;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(check(mid)) l=mid+1;
			else r=mid;
		}
		printf("%lld\n",l+m);
	}
	return 0;
}