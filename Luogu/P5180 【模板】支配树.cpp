#include <bits/stdc++.h>
using namespace std;
const int MAX=2e5+10;
struct Dominator_Tree
{
	int n,tot,dfn[MAX],best[MAX],semi[MAX],idom[MAX],id[MAX],fa[MAX];
	vector<int> nex[MAX],pre[MAX],tmp[MAX],son[MAX];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++)
		{
			nex[i].clear();
			pre[i].clear();
			tmp[i].clear();
			son[i].clear();
			dfn[i]=0; 
			idom[i]=semi[i]=best[i]=fa[i]=i;
		}
	}
	void add_edge(int x,int y)
	{
		nex[x].push_back(y);
		pre[y].push_back(x);
	}
	int ckmin(int x,int y){return dfn[semi[x]]<dfn[semi[y]]?x:y;}
	int getfa(int k)
	{
		if(k==fa[k]) return k;
		int ret=getfa(fa[k]);
		best[k]=ckmin(best[fa[k]],best[k]);
		return fa[k]=ret;
	}
	void dfs(int x)
	{
		dfn[x]=++tot;
		id[tot]=x;
		for(auto &to:nex[x])
		{
			if(dfn[to]) continue;
			dfs(to);
			son[x].push_back(to);
		}
	}
	void tarjan(vector<int> *mp)
	{
		int i,j,k;
		for(i=tot;i;i--)
		{
			k=id[i];
			for(auto &to:pre[k])
			{
				if(!dfn[to]) continue;
				if(dfn[to]<dfn[k])
				{
					if(dfn[to]<dfn[semi[k]]) semi[k]=to;
				}
				else
				{
					getfa(to);
					semi[k]=semi[ckmin(best[to],k)];
				}
			}
			if(k!=semi[k]) tmp[semi[k]].push_back(k);
			for(auto &to:tmp[k])
			{
				getfa(to);
				if(semi[best[to]]==k) idom[to]=k;
				else idom[to]=best[to];
			}
			for(auto &to:son[k]) fa[to]=k;
		}
		for(i=2;i<=tot;i++)
		{
			k=id[i];
			if(idom[k]!=semi[k]) idom[k]=idom[idom[k]];
			if (k!=idom[k])
			{
				mp[idom[k]].push_back(k);  //add edge
				
			}
		}
	}
	void work(int rt,vector<int> *mp)
	{
		for(int i=0;i<=n;i++) mp[i].clear();
		tot=0;
		dfs(rt);
		tarjan(mp);
	}
}dt;
/*
dt.init(n);
dt.add_edge(a,b);  // DAG
dt.work(rt,mp);
*/
vector<int> mp[MAX];
int sz[MAX];
void dfs(int x)
{
	sz[x]=1;
	for(auto &to:mp[x])
	{
		dfs(to);
		sz[x]+=sz[to];
	}
}
int main()
{
	int n,m,i,a,b;
	scanf("%d%d",&n,&m);
	dt.init(n);
	while(m--)
	{
		scanf("%d%d",&a,&b);
		dt.add_edge(a,b);
	}
	dt.work(1,mp);
	dfs(1);
	for(i=1;i<=n;i++) printf("%d%c",sz[i]," \n"[i==n]);
	return 0;
}

