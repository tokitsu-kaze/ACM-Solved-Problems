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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
ll dp[2020][2020];
int main()
{
	int t,n,m,i,j,k;
	ll ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		mem(dp,0);
		for(i=1;i<=n;i++) dp[1][i]=1;
		for(i=2;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				for(k=j;k<=n;k+=j)
				{
					dp[i][k]+=dp[i-1][j];
					dp[i][k]%=mod;
				}
			}
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			ans+=dp[m][i];
			ans%=mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}