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
vector<int> mp[MAX];
ll v[MAX][3],dp[MAX][3];
void dfs(int x,int fa)
{
	int i,j;
	ll tmp;
	for(i=0;i<3;i++) dp[x][i]=v[x][i];
	for(auto to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		for(i=0;i<3;i++)
		{
			tmp=0;
			for(j=0;j<3;j++)
			{
				if(i==j) continue;
				tmp=max(tmp,dp[to][j]);
			}
			dp[x][i]+=tmp;
		}
	}
}
int main()
{
	int n,i,j,a,b;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		for(i=1;i<=n;i++)
		{
			for(j=0;j<3;j++)
			{
				scanf("%lld",&v[i][j]);
			}
		}
		dfs(1,-1);
		ll ans=0;
		for(i=0;i<3;i++) ans=max(ans,dp[1][i]);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
3
1 2
1 3
3 2 1
4 3 2
3 4 3
*/