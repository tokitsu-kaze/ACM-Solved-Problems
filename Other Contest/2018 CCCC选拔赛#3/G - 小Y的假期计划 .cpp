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
int dp[MAX][3],v[MAX];
int main()
{
	int n,i,j;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++) scanf("%d",&v[i]);
		mem(dp,0x3f);
		mem(dp[0],0);
		for(i=1;i<=n;i++)
		{
			for(j=0;j<3;j++)
			{
				dp[i][0]=min(dp[i][0],dp[i-1][j]+1);
			}
			if(v[i]==1||v[i]==3)
			{
				dp[i][1]=min(dp[i][1],dp[i-1][0]);
				dp[i][1]=min(dp[i][1],dp[i-1][2]);
			}
			if(v[i]==2||v[i]==3)
			{
				dp[i][2]=min(dp[i][2],dp[i-1][0]);
				dp[i][2]=min(dp[i][2],dp[i-1][1]);
			}
		}
		int ans=INF;
		for(j=0;j<3;j++)
		{
			ans=min(ans,dp[n][j]);
		}
		printf("%d\n",ans);
	}
	return 0;
}