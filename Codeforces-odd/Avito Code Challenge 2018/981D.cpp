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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int n,k,dp[55][55];
ll a[55];
int check(ll x)
{
	mem(dp,0);
	int i,j,l;
	dp[0][0]=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<k;j++)
		{
			if(!dp[i][j]) continue;
			for(l=i+1;l<=n;l++)
			{
				if(((a[l]-a[i])&x)==x) dp[l][j+1]=1;
			}
		}
	}
	return dp[n][k];
}
int main()
{
	ll i,j,ans;
	while(~scanf("%d%d",&n,&k))
	{
		a[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			a[i]+=a[i-1];
		}
		ans=0;
		for(i=1LL<<62;i;i>>=1)
		{
			if(check(ans|i)) ans|=i;
		}
		printf("%lld\n",ans);
	}
	return 0;
}