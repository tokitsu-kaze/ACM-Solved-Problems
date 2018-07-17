#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
const int MAX=2e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
ll a[MAX];
int main()
{
	int n,i;
	ll ans,bit;
	while(~scanf("%d",&n))
	{
		bit=0;
		map<ll,int> mp;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			bit+=a[i];
			mp[bit]=i;
		}
		ans=bit=0;
		for(i=n;i;i--)
		{
			bit+=a[i];
			if(mp.count(bit))
			{
				if(mp[bit]<i)
				{
					ans=max(ans,bit);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}