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
const int MAX=1e5+10;
const ll mod=1e9+7;
/***************************************  head  **********************************************/
VI mp[MAX],res;
int fa[MAX],flag[MAX],rt,mx;
void dfs(int x,int pre,int h)
{
	fa[x]=pre;
	for(auto to:mp[x])
	{
		if(to==pre) continue;
		dfs(to,x,h+1);
	}
	if(h>mx)
	{
		mx=h;
		rt=x;
	}
}
void gao(int x,int pre)
{
	res.pb(x);
	flag[x]=1;
	for(auto to:mp[x])
	{
		if(to==pre) continue;
		if(flag[to]) continue;
		gao(to,x);
		res.pb(x);
	}
}
int main()
{
	int n,i,a,b;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++) mp[i].clear();
		res.clear();
		mem(flag,0);
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		rt=1;
		mx=-1;
		dfs(rt,-1,0);
		mx=-1;
		dfs(rt,-1,0);
		VI tmp;
		while(~rt)
		{
			tmp.pb(rt);
			flag[rt]=1;
			rt=fa[rt];
		}
		mx++;
		assert(sz(tmp)==mx);
		for(auto it:tmp) gao(it,-1);
		assert(sz(res)-1==(n-mx)*2-1+mx);
		printf("%d\n",sz(res)-1);
		for(i=0;i<sz(res);i++) printf("%d%c",res[i]," \n"[i==sz(res)-1]);
	}
	return 0;
}
