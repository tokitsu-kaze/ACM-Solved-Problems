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
int deep[MAX],fa[MAX],size[MAX],son[MAX];
int top[MAX],tot;
int cnt[MAX];
vector<int> res;
void dfs1(int x,int pre,int h)  
{
	int i,to;
	deep[x]=h;
	fa[x]=pre;
	size[x]=1;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to==pre) continue;
		dfs1(to,x,h+1);
		if(son[x]==-1||size[to]>size[son[x]]) son[x]=to;
	}
	if(son[x]!=-1) size[x]+=size[son[x]];
}
void dfs2(int x,int tp)
{
	int i,to;
	top[x]=tp;
	cnt[tp]++;
	if(son[x]==-1);
	else dfs2(son[x],tp);
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to!=son[x]&&to!=fa[x]) dfs2(to,to);
	}
	if(x==tp) res.pb(cnt[x]);
}
int be,maxx;
void dfs(int x,int fa,int h)
{
	deep[x]=h;
	int i,to;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to==fa) continue;
		dfs(to,x,h+1);
	}
	if(deep[x]>maxx)
	{
		maxx=deep[x];
		be=x;
	}
}
void work(int rt) 
{
	int i;
	mem(son,-1);
	tot=0;
	dfs1(rt,0,0);
	dfs2(rt,rt);
}
int main()
{
	int n,i,j,a,b,ans;
	while(~scanf("%d",&n))
	{
		mem(cnt,0);
		for(i=1;i<=n;i++) mp[i].clear();
		res.clear();
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		maxx=-1;
		dfs(1,0,1);
		work(be);
		sort(all(res));
		ans=0;
		printf("1");
		for(i=sz(res)-1;~i;i--)
		{
			ans+=res[i];
			printf(" %d",ans);
		}
		for(i=sz(res)+2;i<=n;i++) printf(" %d",ans);
		puts("");
	}
	return 0;
}