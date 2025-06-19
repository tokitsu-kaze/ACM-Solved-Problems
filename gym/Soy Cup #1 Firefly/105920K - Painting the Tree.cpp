#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
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
	int col[MAX];
	set<pair<int,int>> s;
	void init_node()
	{
		s.clear();
		for(int i=1;i<=n;i++) s.insert({dfn[i],i});
	}
	void upd(int l,int r,int c)
	{
//		cout<<l<<" "<<r<<" "<<c<<endl;
		auto it=s.lower_bound({l,-1});
		vector<pair<int,int>> del;
		for(;it!=s.end();it++)
		{
			if((*it).first>r) break;
			del.push_back(*it);
			col[(*it).second]=c;
		}
		for(auto &it:del)
		{
			s.erase(it);
//			cout<<it.first<<" "<<it.second<<endl;
		}
	}
	void upd_node(int x,int y,type v)
	{
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			upd(dfn[top[x]],dfn[x],v);
			x=fa[top[x]];
		}
	    if(dep[x]>dep[y]) swap(x,y);
	    upd(dfn[x],dfn[y],v);
	}
	void change_root(int x){rt=x;}
	void upd_subtree(int x,type v)
	{
		if(x==rt) upd(1,n,v);
		else if(dfn[rt]>=dfn[x]&&dfn[rt]<=dfn[x]+sz[x]-1)
		{
			x=find_yson_toward_x(rt,x);
			upd(1,dfn[x]-1,v);
			upd(dfn[x]+sz[x],n,v);
		}
		else upd(dfn[x],dfn[x]+sz[x]-1,v);
	}
	#undef type
}hld;
struct query{int op,x,y,c;}qst[MAX];
int main()
{
	int T,n,m,i,a,b,op,x,y,c;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		hld.init(n);
		for(i=1;i<=n;i++) scanf("%d",&hld.col[i]);
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			hld.add_edge(a,b);
		}
		hld.work(1);
		hld.init_node();
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d%d",&op,&x,&y,&c);
			qst[i]={op,x,y,c};
		}
		for(i=m;i;i--)
		{
			if(qst[i].op==1) hld.upd_node(qst[i].x,qst[i].y,qst[i].c);
			else
			{
				hld.change_root(qst[i].y);
				hld.upd_subtree(qst[i].x,qst[i].c);
			}
		}
		for(i=1;i<=n;i++) printf("%d%c",hld.col[i]," \n"[i==n]);
	}
	return 0;
}
