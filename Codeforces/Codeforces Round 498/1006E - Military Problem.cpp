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
const int MAX=2e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
int sz[MAX],v[MAX],dfn[MAX],tot;
VI mp[MAX];
void dfs(int x,int fa)
{
	dfn[x]=++tot;
	v[tot]=x;
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
	int n,q,i,a,b;
	while(~scanf("%d%d",&n,&q))
	{
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=2;i<=n;i++)
		{
			scanf("%d",&a);
			mp[a].pb(i);
		}
		tot=0;
		dfs(1,-1);
		while(q--)
		{
			scanf("%d%d",&a,&b);
			if(sz[a]<b)
			{
				puts("-1");
				continue;
			}
			printf("%d\n",v[dfn[a]+b-1]);
		}
	}
	return 0;
}