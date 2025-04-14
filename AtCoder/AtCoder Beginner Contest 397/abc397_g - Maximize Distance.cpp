#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
struct Dinic
{
	#define type int
	const type inf=INF;
	static const int N=1005;
	struct node
	{
		int from,to;
		type cap,flow;
		node(int u,int v,type c,type f):from(u),to(v),cap(c),flow(f){}
	};
	int n,s,t;
	vector<node> edge;
	vector<int> mp[N];
	int vis[N],dist[N],id[N];
	void init(int _n)
	{
		n=_n;
		edge.clear();
		for(int i=0;i<=n;i++)
		{
			mp[i].clear();
			id[i]=dist[i]=vis[i]=0;
		}
	}
	void add_edge(int from,int to,type cap)
	{
		edge.push_back(node(from,to,cap,0));
		edge.push_back(node(to,from,0,0));
		int m=edge.size();
		mp[from].push_back(m-2);
		mp[to].push_back(m-1);
	}
	bool bfs()
	{
		int i,x;
		memset(vis,0,sizeof vis);
		queue<int>q;
		q.push(s);
		dist[s]=0;
		vis[s]=1;
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			for(i=0;i<mp[x].size();i++)
			{
				node &e=edge[mp[x][i]];
				if(!vis[e.to]&&e.cap>e.flow)
				{
					vis[e.to]=1;
					dist[e.to]=dist[x]+1;
					q.push(e.to);
				}
			}
		}
		return vis[t];
	}
	type dfs(int x,type a)
	{
		if(x==t||!a) return a;
		type flow=0,f;
		for(int &i=id[x];i<mp[x].size();i++)
		{
			node &e=edge[mp[x][i]];
			if(dist[x]+1==dist[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0)
			{
				e.flow+=f;
				edge[mp[x][i]^1].flow-=f;
				flow+=f;
				a-=f;
				if(!a) break;
			}
		}
		return flow;
	}
	type max_flow(int _s,int _t)
	{
		s=_s;
		t=_t;
		type res=0;
		while(bfs())
		{
			for(int i=0;i<=n;i++) id[i]=0;
			res+=dfs(s,inf);
		}
		return res;
	}
	type min_cut(int s,int t){return max_flow(s,t);}
	#undef type
}dc; 
/*
O(n^2*m)
bipartite graph: O(m*sqrt(n))

dc.init(n);
dc.add_edge(a,b,cap); a,b: 1~n
*/
struct edge{int x,y;};
int n,k,id[33][33];
vector<edge> e;
int ck(int d)
{
	int s,t,i,j,tot;
	tot=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=d;j++) id[i][j]=++tot;
	}
	s=tot+1;
	t=s+1;
	dc.init(t);
	for(i=1;i<=n;i++)
	{
		for(j=2;j<=d;j++) dc.add_edge(id[i][j-1],id[i][j],dc.inf);
	}
	for(auto &it:e)
	{
		for(j=1;j<=d;j++)
		{
			dc.add_edge(id[it.x][j],id[it.y][j],1);
			if(j<d) dc.add_edge(id[it.x][j],id[it.y][j+1],dc.inf);
		}
	}
	dc.add_edge(s,id[1][1],dc.inf);
	dc.add_edge(id[n][d],t,dc.inf);
	return dc.min_cut(s,t)<=k;
}
int main()
{
	int m,i,a,b,l,r,mid;
	scanf("%d%d%d",&n,&m,&k);
	e.clear();
	while(m--)
	{
		scanf("%d%d",&a,&b);
		e.push_back({a,b});
	}
	l=0;
	r=n-1;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid+1)) l=mid+1;
		else r=mid;
	}
	printf("%d\n",l);
	return 0;
}
