#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
	ll t;
	scanf("%d%d%d",&n,&m,&k);
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
	scanf("%d",&q);
	i=0;
	while(q--)
	{
		scanf("%d%d%lld",&x,&y,&t);
		while(i<e.size() && e[i].w<=t)
		{
			dsu.merge(e[i].x,e[i].y);
			i++;
		}
		if(dsu.find(x)==dsu.find(y)) puts("Yes");
		else puts("No");
	}
	return 0;
}
