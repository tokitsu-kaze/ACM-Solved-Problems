#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Disjoint_Set_Union
{
	int pre[MAX],sz[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
			sz[i]=1;
		}
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int x,int y,bool dir=false)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(!dir && sz[x]>sz[y]) swap(x,y);
		pre[x]=y; // x -> y
		sz[y]+=sz[x];
		return 1;
	}
}dsu;
struct Heavy_Light_Decomposition
{
	#define type int
	struct edge{int a,b;type v;};
	vector<int> mp[MAX];
	vector<edge> e;
	int dep[MAX],fa[MAX],sz[MAX],son[MAX];
	int id[MAX],top[MAX],dfn[MAX],tot;
	int n,rt;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
		e.clear();
		e.push_back({0,0,0});
	}
	void add_edge(int a,int b,type v=0)
	{
		e.push_back({a,b,v});
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	void dfs1(int x,int pre,int h)
	{
		int i,to;
		dep[x]=h;
		fa[x]=pre;
		sz[x]=1;
		for(i=0;i<mp[x].size();i++)
		{
			to=mp[x][i];
			if(to==pre) continue;
			dfs1(to,x,h+1);
			sz[x]+=sz[to];
			if(son[x]==-1||sz[to]>sz[son[x]]) son[x]=to;
		}
	}
	void dfs2(int x,int tp)
	{
		int i,to;
		dfn[x]=++tot;
		id[dfn[x]]=x;
		top[x]=tp;
		if(son[x]==-1) return;
		dfs2(son[x],tp);
		for(i=0;i<mp[x].size();i++)
		{
			to=mp[x][i];
			if(to!=son[x]&&to!=fa[x]) dfs2(to,to);
		}
	}
	void work(int _rt)
	{
		rt=_rt;
		for(int i=0;i<=n;i++) son[i]=-1;
		tot=0;
		dfs1(rt,0,0);
		dfs2(rt,rt);
	}
	int lca(int x,int y)
	{
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			x=fa[top[x]];
		}
	    if(dep[x]>dep[y]) swap(x,y);
	    return x;
	}
	int find_yson_toward_x(int x,int y)
	{
		while(top[x]!=top[y])
		{
			if(fa[top[x]]==y) return top[x];
			x=fa[top[x]];
		}
	    return son[y];
	}
	#undef type
}hld;
/*
hld.init(n)
hld.add_edge(a,b,v=0);  a <-> b
hld.work(rt);
hld.lca(a,b);
*/
struct edge{int a,b;};
int tag[MAX];
char ans[MAX];
void dfs(int x,int fa)
{
	tag[x]+=tag[fa];
	for(auto &to:hld.mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
	}
}
int main()
{
	int n,m,i,a,b,c;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) tag[i]=0;
	hld.init(n);
	dsu.init(n);
	vector<edge> e;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		if(!dsu.merge(a,b)) e.push_back({a,b});
		else hld.add_edge(a,b);
	}
	hld.work(1);
	for(auto &it:e)
	{
		c=hld.lca(it.a,it.b);
		if(c==it.a || c==it.b)
		{
			if(c==it.b) swap(it.a,it.b);
			tag[1]++;
			tag[hld.find_yson_toward_x(it.b,c)]--;
			tag[it.b]++;
		}
		else
		{
			tag[it.a]++;
			tag[it.b]++;
		}
	}
	tag[0]=0;
	dfs(1,0);
	for(i=1;i<=n;i++)
	{
		if(tag[i]==e.size()) ans[i]='1';
		else ans[i]='0';
	}
	ans[n+1]='\0';
	puts(ans+1);
	return 0;
}
/*
首先mst是唯一的。先求出mst。

画画图会发现，如果有一条横叉边，即它们不是祖先后代关系，
那么从它们两个子树以外的地方走到它们就一定会走这条边。
因为你必须访问这个点的所有出边后才能访问另一个子树，
这样就必定会走哪条不应该走的边。

所以我们对每条边都计算哪些点是可以为起点，
当一个点都能为起点那就是可以。

因为我们根是随便选的，所以实现上会出现两种情况：
一种是横叉边，那直接标记子树即可；
另一种是返祖边，其中一个点是lca，求出那个点向另一个点的儿子z，
然后整棵树打标记，z减标记，另一个点再打标记。
*/
