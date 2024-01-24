#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
const ll mod=998244353;
struct Heavy_Light_Decomposition
{
	#define type int
	struct edge{int a,b;type v;};
	struct node{int to;type w;};
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
	int LCA(int x,int y)
	{
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			x=fa[top[x]];
	    }
	    if(dep[x]>dep[y]) swap(x,y);
	    return x;
	}
	//node
	vector<int> pos[MAX];
	int cal(int l,int r,int v)
	{
		return upper_bound(pos[v].begin(),pos[v].end(),r)
		      -lower_bound(pos[v].begin(),pos[v].end(),l);
	}
	void init_node(int *v)
	{
		for(int i=1;i<=n;i++) pos[v[i]].push_back(dfn[i]);
		for(int i=1;i<=n;i++) sort(pos[i].begin(),pos[i].end());
	}
	type ask_node(int x,int y,int col)
	{
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			if(cal(dfn[top[x]],dfn[x],col)) return 1;
			x=fa[top[x]];
	    }
	    if(dep[x]>dep[y]) swap(x,y);
	    if(cal(dfn[x],dfn[y],col)) return 1;
	    return 0;
	}
	#undef type
}hld;
/*
hld.init(n)
hld.add_edge(a,b,v=0);  a <-> b
hld.work(root);
*/
int col[MAX];
int main()
{
	int n,q,i,a,b,c;
	scanf("%d%d",&n,&q);
	hld.init(n);
	for(i=1;i<=n;i++) scanf("%d",&col[i]);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		hld.add_edge(a,b);
	}
	hld.work(1);
	hld.init_node(col);
	string res;
	while(q--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(hld.ask_node(a,b,c)) res+="1";
		else res+="0";
	}
	cout<<res<<"\n";
	return 0;
}
