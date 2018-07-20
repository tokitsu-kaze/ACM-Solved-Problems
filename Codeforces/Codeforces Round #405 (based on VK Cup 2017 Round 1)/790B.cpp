#include <bits/stdc++.h>
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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
ll n,k,ans,dp[MAX][6],sz[MAX];
vector<ll> mp[MAX];
void dfs(ll x,ll pre,ll h)
{
	ll i,j,r,to;
	dp[x][h%k]=1;
	sz[x]=1;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to==pre) continue;
		dfs(to,x,h+1);
		for(j=0;j<k;j++)
		{
			for(r=0;r<k;r++)
			{
				ll dis=(j+r-2*h)%k;
				ll temp=(k-dis)%k;
				ans+=temp*dp[x][j]*dp[to][r];
			}
		}
		for(j=0;j<k;j++)
		{
			dp[x][j]+=dp[to][j];
		}
		sz[x]+=sz[to];
		ans+=sz[to]*(n-sz[to]);
	}
}
int main()
{
	ll i,a,b;
	while(~scanf("%lld%lld",&n,&k))
	{
		mem(dp,0);
		mem(sz,0);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		ans=0;
		dfs(1,0,0);
		printf("%lld\n",ans/k);
	}
	return 0;
}