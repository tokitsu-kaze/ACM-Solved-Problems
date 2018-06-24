////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-02-11 23:26:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2643
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1768KB
//////////////////System Comment End//////////////////
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
const double eps=1e-4;
const int MAX=2e5+10;
const ll mod=20090126;
ll dp[111][111];
void init()
{
	ll i,j;
	mem(dp,0);
	dp[1][1]=1;
	for(i=2;i<=100;i++)
	{
		for(j=1;j<=i;j++)
		{
			dp[i][j]=(dp[i-1][j-1]+j*dp[i-1][j])%mod;
		}
	}
}
int main()
{
	ll n,ans,i,t,temp;
	init();
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		ans=0;
		temp=1;
		for(i=1;i<=n;i++)
		{
			temp=(temp*i)%mod;
			ans=(ans+dp[n][i]*temp%mod)%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}