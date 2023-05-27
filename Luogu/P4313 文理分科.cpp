#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int INF=0x3f3f3f3f;
struct Dinic
{
	#define type int
	#define inf INF
	static const int N=3e4+10;
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
		edge.pb(node(from,to,cap,0));
		edge.pb(node(to,from,0,0));
		int m=edge.size();
		mp[from].pb(m-2);
		mp[to].pb(m-1);
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
	#undef inf
}dc; 
/*
dc.init(n);
dc.add_edge(a,b,cap); a,b: 1~n
*/
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int n,m;
int ar[105][105],sc[105][105];
int sar[105][105],ssc[105][105];
int get_id(int x,int y){return (x-1)*m+y;}
int main()
{
	int i,j,k,s,t,x,y,ans,ar_node,sc_node,now_node;
	scanf("%d%d",&n,&m);
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&ar[i][j]);
			ans+=ar[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&sc[i][j]);
			ans+=sc[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&sar[i][j]);
			ans+=sar[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&ssc[i][j]);
			ans+=ssc[i][j];
		}
	}
	s=3*n*m+1;
	t=s+1;
	dc.init(t);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			now_node=get_id(i,j);
			dc.add_edge(s,now_node,ar[i][j]);
			dc.add_edge(now_node,t,sc[i][j]);
			ar_node=now_node+n*m;
			sc_node=now_node+2*n*m;
			dc.add_edge(s,ar_node,sar[i][j]);
			dc.add_edge(sc_node,t,ssc[i][j]);
			dc.add_edge(ar_node,now_node,INF);
			dc.add_edge(now_node,sc_node,INF);
			for(k=0;k<4;k++)
			{
				x=i+dir[k][0];
				y=j+dir[k][1];
				if(x<1 || x>n || y<1 || y>m) continue;
				dc.add_edge(ar_node,get_id(x,y),INF);
				dc.add_edge(get_id(x,y),sc_node,INF);
			}
		}
	}
	printf("%d\n",ans-dc.max_flow(s,t));
	return 0;
}
