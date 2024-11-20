#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct Dinic
{
	#define type int
	const type inf=INF;
	static const int N=1805;
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
	#undef type
}dc; 
/*
O(n^2*m)
bipartite graph: O(m*sqrt(n))

dc.init(n);
dc.add_edge(a,b,cap); a,b: 1~n
*/
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int id[33][33],mp[33][33];
int main()
{
	int n,m,i,j,k,S,T,tot,x,y;
	scanf("%d%d",&n,&m);
	tot=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			tot+=2;
			id[i][j]=tot;
			scanf("%d",&mp[i][j]);
		}
	}
	S=tot+1;
	T=S+1;
	dc.init(T);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]>0) dc.add_edge(id[i][j]-1,id[i][j],mp[i][j]);
			else if(mp[i][j]==0)
			{
				dc.add_edge(S,id[i][j]-1,INF);
				dc.add_edge(id[i][j]-1,id[i][j],INF);
			}
			for(k=0;k<4;k++)
			{
				x=i+dir[k][0];
				y=j+dir[k][1];
				if(x<1||x>n||y<1||y>m) dc.add_edge(id[i][j],T,INF);
				else if(mp[x][y]!=-1) dc.add_edge(id[i][j],id[x][y]-1,INF);
			}
		}
	}
	printf("%d\n",dc.max_flow(S,T));
	return 0;
}
