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
const int MAX=5e5+10;
const ll mod=998244353;
ll C[1010][1010];
void init(int n)
{
	int i,j;
	for(i=(C[0][0]=1);i<=n;i++)
	{
		for(j=(C[i][0]=1);j<=n;j++)
		{
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	} 
}
int main()
{
	int n,i,j,a[MAX];
	ll dp[1010];
	init(1000);
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		mem(dp,0);
		dp[n+1]=1;
		for(i=n;i;i--)
		{
			if(a[i]<=0) continue;
			for(j=n;j-a[i]>=i;j--)
			{
				(dp[i]+=dp[j+1]*C[j-i][a[i]]%mod)%=mod;
			}
		}
		for(i=2;i<=n;i++) (dp[1]+=dp[i])%=mod;
		printf("%lld\n",dp[1]);
	}
	return 0;
} 
