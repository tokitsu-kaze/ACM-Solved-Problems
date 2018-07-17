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
const int MAX=1e6+10;
const ll mod=998244353;
/****************************************  head  ****************************************/
ll dp[MAX],a[MAX];
int main()
{
	ll n,i,ans,tmp;
	while(~scanf("%lld",&n))
	{
		ans=0;
		dp[1]=1;
		tmp=1;
		for(i=2;i<=n;i++)
		{
			dp[i]=(dp[i-1]*2%mod+tmp)%mod;
			(tmp*=2)%=mod;
		}
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(i=1;i<=n;i++) (ans+=dp[i]*a[n-i+1]%mod)%=mod;
		printf("%lld\n",ans);
	}
	return 0;
}
