#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define len(x) (int) x.length()
#define all(x) x.begin(),x.end()
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
int main()
{
	ll n,i,x,ans,pre;
	while(~scanf("%lld",&n))
	{
		map<ll,int> mp;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&x);
			mp[x]++;
			while(mp[x]%2==0)
			{
				mp.erase(x);
				mp[++x]++;
			}
		}
		ans=0;
		pre=-1;
		for(auto it:mp)
		{
			ans+=it.fi-pre-1;
			pre=it.fi;
		}
		printf("%lld\n",ans);
	}
	return 0;
}