////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-11-01 20:29:03
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5044
////Problem Title: 
////Run result: Accept
////Run time:4009MS
////Run memory:27488KB
//////////////////System Comment End//////////////////
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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
struct edge
{
	int a,b;
}e[MAX];
vector<int> mp[MAX];
int deep[MAX],fa[MAX],size[MAX],son[MAX];
int rnk[MAX],top[MAX],idx[MAX],tot;
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
		size[x]+=size[to];
		if(son[x]==-1||size[to]>size[son[x]]) son[x]=to;
	}
}
void dfs2(int x,int tp)
{
	int i,to;
	top[x]=tp;
	idx[x]=++tot;
	rnk[idx[x]]=x;
	if(son[x]==-1) return;
	dfs2(son[x],tp);
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(to!=son[x]&&to!=fa[x]) dfs2(to,to);
	}
}
ll ans[MAX][4];
void update(int l,int r,int val,int flag)
{
	ans[l][flag]+=(ll)val;
	ans[r+1][flag]-=(ll)val;
}
void modify1(int x,int y,int val)
{  
	while(top[x]!=top[y])
	{  
		if(deep[top[x]]<deep[top[y]]) swap(x,y);
		update(idx[top[x]],idx[x],val,1);
		x=fa[top[x]];
    }  
    if(deep[x]>deep[y]) swap(x,y);
    update(idx[x],idx[y],val,1);
}
void modify2(int x,int y,int val)
{  
	while(top[x]!=top[y])
	{  
		if(deep[top[x]]<deep[top[y]]) swap(x,y);
		update(idx[top[x]],idx[x],val,2);
		x=fa[top[x]];
    }  
    if(deep[x]>deep[y]) swap(x,y);
	if(x!=y) update(idx[x]+1,idx[y],val,2);
}
void work(int n)
{
	int i;
	mem(son,-1);
	tot=0;
	dfs1(1,0,1);
	dfs2(1,1);
	for(i=1;i<n;i++)
	{
		if(deep[e[i].a]<deep[e[i].b]) swap(e[i].a,e[i].b);
	}
}
ll res[MAX][3];
int main()
{
	int t,cas=1,a,b,c,n,q,i;
	char op[12];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		mem(ans,0);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
		}
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
			e[i]={a,b};
		}
		work(n);
		while(q--)
		{
			scanf("%s %d %d %d",op,&a,&b,&c);
			if(op[3]=='1') modify1(a,b,c);
			else modify2(a,b,c);
		}
		for(i=2;i<=n;i++)
		{
			ans[i][1]+=ans[i-1][1];
			ans[i][2]+=ans[i-1][2];
		}
		for(i=1;i<=n;i++)
		{
			res[i][1]=ans[idx[i]][1];
			if(i!=n) res[i][2]=ans[idx[e[i].a]][2];
		}
		printf("Case #%d:\n",cas++);
		printf("%lld",res[1][1]);
		for(i=2;i<=n;i++) printf(" %lld",res[i][1]);
		puts("");
		if(n>1) printf("%lld",res[1][2]);
		for(i=2;i<n;i++) printf(" %lld",res[i][2]);
		puts("");
	}
	return 0;
}
