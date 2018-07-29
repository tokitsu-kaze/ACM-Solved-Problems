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
const int MAX=4e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
ll dp[MAX][3][4],v[MAX];
VI mp[MAX];
void dfs(int x,int fa)
{
	int i,j,k;
	dp[x][1][0]=v[x];
	for(auto to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		for(k=2;~k;k--)
		{
			for(i=k;~i;i--)
			{
				j=k-i; 
				dp[x][2][k]=max(dp[x][2][k],dp[x][1][i]+dp[to][1][j]);
				dp[x][2][k]=max(dp[x][2][k],dp[x][2][i]+dp[to][0][j]);
			}
		}
		for(k=2;~k;k--)
		{
			for(i=k;~i;i--)
			{
				j=k-i;
				dp[x][1][k]=max(dp[x][1][k],dp[x][1][i]+dp[to][0][j]);
				dp[x][1][k]=max(dp[x][1][k],dp[x][0][i]+dp[to][1][j]+v[x]);
			}
		}
		for(k=3;~k;k--)
		{
			for(i=k;~i;i--)
			{
				j=k-i;
				dp[x][0][k]=max(dp[x][0][k],dp[x][0][i]+dp[to][0][j]);
				if(j) dp[x][0][k]=max(dp[x][0][k],dp[x][0][i]+dp[to][2][j-1]);
				if(j) dp[x][0][k]=max(dp[x][0][k],dp[x][0][i]+dp[to][1][j-1]);
			}
		}
	}
	for(k=1;k<=3;k++)
	{
		dp[x][0][k]=max(dp[x][0][k],dp[x][1][k-1]);
		dp[x][0][k]=max(dp[x][0][k],dp[x][2][k-1]);
	}
}
int main()
{
	int n,i,j,a,b;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			mem(dp[i],0);
			scanf("%lld",&v[i]);
		}
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		dfs(1,-1);
		printf("%lld\n",dp[1][0][3]);
	}
	return 0;
}