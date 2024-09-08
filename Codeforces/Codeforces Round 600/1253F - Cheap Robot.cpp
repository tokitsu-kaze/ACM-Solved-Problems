#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct LCA
{
	#define type ll
	static const int N=MAX;
	static const int LOGN=log2(N)+3;
	static const type inf=LLINF;
	struct node{int to;type w;};
	struct info_node{int fa;type mx;}info[N][LOGN];
	int dep[N],limt,bin[LOGN],n;
	type dis[N];
	bool vis[N];
	vector<node> mp[N];
	void init(int _n)
	{
		int i;
		n=_n;
		for(i=0;i<=n;i++) mp[i].clear();
		for(limt=1;(1<<(limt-1))<n;limt++);
		for(i=bin[0]=1;i<=limt;i++) bin[i]=(bin[i-1]<<1);
	}
	void add_edge(int a,int b,type w=1){mp[a].push_back({b,w});}
	void dfs(int x,int pre)
	{
		int i,tmp;
		vis[x]=1;
		for(i=1;bin[i]<=dep[x];i++)
		{
			tmp=info[x][i-1].fa;
			info[x][i].fa=info[tmp][i-1].fa;
			info[x][i].mx=max(info[tmp][i-1].mx,info[x][i-1].mx);
		}
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(to==pre) continue;
			dis[to]=dis[x]+it.w;
			dep[to]=dep[x]+1;
			info[to][0]={x,it.w};
			dfs(to,x);
		}
	}
	void work(int rt=-1)
	{
		int i,j;
		for(i=0;i<=n;i++)
		{
			dep[i]=dis[i]=vis[i]=0;
			for(j=0;j<=limt;j++)
			{
				info[i][j]={0,0};
			}
		}
		if(rt==-1)
		{
			for(i=1;i<=n;i++)
			{
				if(vis[i]) continue;
				dfs(i,-1);
			}
		}
		else dfs(rt,-1);
	}
	info_node go_info(int x,int d)
	{
		info_node res={x,0};
		for(int i=0;i<=limt&&d;i++)
		{
			if(bin[i]&d)
			{
				d^=bin[i];
				res.mx=max(res.mx,info[x][i].mx);
				x=info[x][i].fa;
			}
		}
		res.fa=x;
		return res;
	}
	info_node lca_info(int x,int y)
	{
		if(dep[x]<dep[y]) swap(x,y);
		info_node res=go_info(x,dep[x]-dep[y]);
		x=res.fa;
		if(x==y) return res;
		for(int i=limt;~i;i--)
		{
			if(info[x][i].fa!=info[y][i].fa)
			{
				res.mx=max({res.mx,info[x][i].mx,info[y][i].mx});
				x=info[x][i].fa;
				y=info[y][i].fa;
			}
		}
		res.fa=info[x][0].fa;
		res.mx=max({res.mx,info[x][0].mx,info[y][0].mx});
		return res;
	}
	int go(int x,int d){return go_info(x,d).fa;}
	int lca(int x,int y){return lca_info(x,y).fa;}
	int get_len(int a,int b){return dep[a]+dep[b]-2*dep[lca(a,b)];}
	type get_path_max(int x,int y){return lca_info(x,y).mx;}
	type get_dis(int a,int b){return dis[a]+dis[b]-2*dis[lca(a,b)];}
	#undef type
}lca;
/*
O(nlogn)-O(logn)
 
lca.init(n);
lca.add_edge(a,b,w); // a->b
lca.work(rt);
*/
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
struct Dijkstra
{
	#define type ll
	const type inf=LLINF;
	struct node
	{
		int id;
		type v;
		friend bool operator <(node a,node b){return a.v>b.v;}
	};
	static const int N=MAX;
	vector<node> mp[N];
	type dis[N];
	int n,vis[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type v){mp[x].push_back({y,v});}
	void work(int s)
	{
		int i,to;
		type w;
		priority_queue<node> q;
		for(i=0;i<=n;i++)
		{
			dis[i]=inf;
			vis[i]=0;
		}
		dis[s]=0;
		q.push({s,type(0)});
		while(!q.empty())
		{
			node t=q.top();
			q.pop();
			if(vis[t.id]) continue;
			vis[t.id]=1;// this node has already been extended
			for(auto &it:mp[t.id])
			{
				to=it.id;
				w=it.v;
				if(dis[to]>dis[t.id]+w)
				{
					dis[to]=dis[t.id]+w;
					if(!vis[to]) q.push({to,dis[to]});
				}
			}
		}
	}
	#undef type
}dij;
struct edge{int x,y;ll w;};
int main()
{
	int n,m,k,i,a,b,c,q,s,x,y;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	s=n+1;
	dij.init(n+1);
	vector<edge> e;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		e.push_back({a,b,c});
		dij.add_edge(a,b,c);
		dij.add_edge(b,a,c);
	}
	for(i=1;i<=k;i++)
	{
		dij.add_edge(s,i,0);
		dij.add_edge(i,s,0);
	}
	dij.work(s);
	for(auto &it:e) it.w+=dij.dis[it.x]+dij.dis[it.y];
	sort(e.begin(),e.end(),[](edge a,edge b){
		return a.w<b.w;
	});
	dsu.init(n+1);
	lca.init(n+1);
	for(auto &it:e)
	{
		if(dsu.find(it.x)==dsu.find(it.y)) continue;
		lca.add_edge(it.x,it.y,it.w);
		lca.add_edge(it.y,it.x,it.w);
		dsu.merge(it.x,it.y);
	}
	lca.work(1);
	while(q--)
	{
		scanf("%d%d",&x,&y);
		printf("%lld\n",lca.get_path_max(x,y));
	}
	return 0;
}
