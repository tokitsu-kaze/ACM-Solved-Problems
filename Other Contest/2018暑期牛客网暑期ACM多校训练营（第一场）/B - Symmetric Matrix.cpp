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
const int MAX=1e5+10;
//const ll mod=1e9+7;
/****************************************  head  ****************************************/
ll mod;
ll dp[MAX];
int main()
{
	ll n,i;
	while(~scanf("%lld%lld",&n,&mod))
	{
		dp[1]=0;
		dp[2]=1;
		dp[3]=1;
		for(i=4;i<=n;i++)
		{
			dp[i]=(((i-1)*((dp[i-1]+dp[i-2])%mod)%mod-((i-1)*(i-2)/2)%mod*dp[i-3]%mod%mod)%mod+mod)%mod;
		}
		printf("%lld\n",dp[n]);
	}
	return 0;
}
// http://oeis.org/A002137