#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	ll x,y,l,r,i,j,t,ans;
	while(~scanf("%lld%lld%lld%lld",&x,&y,&l,&r))
	{
		vector<ll> a,b,res;
		t=1;
		a.pb(t);
		while(t<=r/x)
		{
			t*=x;
			a.pb(t);
		}
		t=1;
		b.pb(t);
		while(t<=r/y)
		{
			t*=y;
			b.pb(t);
		}
		for(i=0;i<sz(a);i++)
		{
			for(j=0;j<sz(b);j++)
			{
				if(a[i]+b[j]<=r) res.pb(a[i]+b[j]);
			}
		}
		sort(all(res));
		res.resize(unique(all(res))-res.begin());
		ans=0;
		for(i=0;i<sz(res);i++)
		{
			if(res[i]>=l)
			{
				ans=max(ans,res[i]-l);
				l=res[i]+1;
			}
		}
		ans=max(ans,r-l+1);
		printf("%lld\n",ans);
	}
	return 0;
}