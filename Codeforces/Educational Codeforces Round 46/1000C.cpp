#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
#define VI vector<int>
#define VL vector<ll>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=2e5+10;
const ll mod=998244353;
ll ans[MAX];
int main()
{
	ll n,i,now,a,b,pre;
	while(~scanf("%lld",&n))
	{
		mem(ans,0);
		vector<PLL > res;
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld",&a,&b);
			res.pb(MP(a,-1));
			res.pb(MP(b,1));
		}
		sort(all(res));
		pre=-1;
		now=0;
		for(i=0;i<sz(res);i++)
		{
			if(res[i].se==-1)
			{
				if(pre!=-1) ans[now]+=res[i].fi-pre;
				pre=res[i].fi;
				now++;
			}
			else
			{
				if(pre<=res[i].fi)ans[now]+=res[i].fi-pre+1;
				pre=res[i].fi+1;
				now--;
			}
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",ans[i]," \n"[i==n]);
		}
	}
	return 0;
}