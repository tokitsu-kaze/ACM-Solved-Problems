////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-05-05 15:45:28
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6267
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:3984KB
//////////////////System Comment End//////////////////
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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=998244353;
ll inv[MAX];
void getinv(int n)
{
	inv[1]=1;
	for(int i=2;i<=n;i++) inv[i]=((mod-mod/i)*inv[mod%i])%mod;
}
ll a[MAX],dp[MAX];
int main()
{
	getinv(MAX-10);
	int t,n;
	ll ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		dp[n]=0;
		for(int i=n-1;~i;i--) dp[i]=(dp[i+1]+a[i])%mod;
		ans=0;
		for(int i=0;i<n;i++) ans=(ans+(a[i]+inv[i+1]*dp[i+1]%mod)%mod)%mod;
		ans=ans*inv[n]%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
