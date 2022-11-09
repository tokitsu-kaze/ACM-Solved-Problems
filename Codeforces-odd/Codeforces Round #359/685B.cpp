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
const int MAX=3e5+10;
const ll mod=1e9+7;
vector<int> mp[MAX];
int sz[MAX],ans[MAX],fa[MAX];
void dfs(int x)
{
	int i,to,flag=0;
	sz[x]=1;
	ans[x]=x;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		dfs(to);
		sz[x]+=sz[to];
		flag=1;
	}
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(sz[to]*2>sz[x]) ans[x]=ans[to];
	}
	while((sz[x]-sz[ans[x]])*2>sz[x]) ans[x]=fa[ans[x]];
}
int main()
{
	int n,q,i,x;
	while(~scanf("%d%d",&n,&q))
	{
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=2;i<=n;i++)
		{
			scanf("%d",&fa[i]);
			mp[fa[i]].pb(i);
		}
		dfs(1);
		while(q--)
		{
			scanf("%d",&x);
			printf("%d\n",ans[x]);
		}
	}
	return 0;
}