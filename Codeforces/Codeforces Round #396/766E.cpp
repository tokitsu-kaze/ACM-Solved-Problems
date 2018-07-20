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
int v[MAX];
vector<int> mp[MAX];
ll ans,dp[MAX][2];
void dfs(int x,int fa,int val)
{
	int i,to,t;
	ll res=0;
	t=((v[x]>>val)&1);
	dp[x][t]=1;
	dp[x][t^1]=0;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to==fa) continue;
		dfs(to,x,val);
		res+=dp[x][0]*dp[to][1]+dp[x][1]*dp[to][0];
		dp[x][t]+=dp[to][0];
		dp[x][t^1]+=dp[to][1]; 
	}
	ans+=res<<val;
}
int main()
{
	int n,i,a,b,maxx;
	while(~scanf("%d",&n))
	{
		maxx=0;
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			mp[i].clear();
			maxx=max(maxx,v[i]);
			ans+=v[i];
		}
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		for(i=0;(1<<i)<=maxx;i++)
		{
			dfs(1,0,i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}