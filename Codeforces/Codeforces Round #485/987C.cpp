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
ll dp[3030][4],a[3030],b[3030];
int main()
{
	int n,i,j,k,tot;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(i=1;i<=n;i++) scanf("%lld",&b[i]);
		mem(dp,0x3f);
		for(i=1;i<=n;i++)
		{
			dp[i][1]=min(dp[i][1],b[i]);
			for(k=1;k<=3;k++)
			{
				for(j=1;j<i;j++)
				{
					if(a[i]>a[j]) dp[i][k]=min(dp[i][k],dp[j][k-1]+b[i]);
				}
			}
		}
		ll ans=LLINF;
		for(i=1;i<=n;i++)
		{
			ans=min(ans,dp[i][3]);
		}
		if(ans==LLINF) ans=-1;
		printf("%lld\n",ans);
	}
	return 0;
}