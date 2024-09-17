#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
struct ll_hash{size_t operator()(ll x)const{return x;}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	ll n,i,j,x,ans,cnt;
	while(~scanf("%lld",&n))
	{
		ans=0;
		vector<ll> v(n);
		while(n--)
		{
			scanf("%lld",&x);
			v.pb(x);
		}
		sort(all(v));
		v.resize(unique(all(v))-v.begin());
		for(i=62;i>=1;i--)
		{
			int pos=lower_bound(all(v),1LL<<i)-v.begin();
			for(j=pos;j<sz(v);j++)
			{
				ans++;
				v[j]>>=1;
			}
			inplace_merge(v.begin(),v.begin()+pos,v.end());
			v.resize(unique(all(v))-v.begin());
		}
		printf("%lld\n",ans);
	}
	return 0;
}
