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
const int MAX=3e5+10;
const ll mod=1e9+7;
ll sz[MAX];
vector<int> mp[MAX];
void dfs(int x,int fa)
{
	sz[x]=1;
	for(auto to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		sz[x]+=sz[to];
	}
}
int main()
{
	int n,i,a,b,x,y;
	while(~scanf("%d%d%d",&n,&x,&y))
	{
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		ll ans=1LL*n*(n-1);
		dfs(x,-1);
		ll xx=sz[y];
		dfs(y,-1);
		ll yy=sz[x];
		ans-=xx*yy;
		printf("%lld\n",ans);
	}
	return 0;
}