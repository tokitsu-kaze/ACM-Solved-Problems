#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=200+10;
struct Dinic
{
	#define type int
	const type inf=INF;
	static const int N=MAX*MAX+10;
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
	int add_edge(int from,int to,type cap)
	{
		edge.push_back(node(from,to,cap,0));
		edge.push_back(node(to,from,0,0));
		int m=edge.size();
		mp[from].push_back(m-2);
		mp[to].push_back(m-1);
		return m-2;
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
struct node{int x,y;};
int col[MAX][MAX],vis[MAX][MAX];
int dir[4][2]={1,1,1,-1,-1,1,-1,-1};
int id[MAX][MAX];
char mp[MAX][MAX];
int ck(int n,int m,int x,int y)
{
	if(x<1||y<1||x>n||y>m) return 0;
	return 1;
}
void init_col(int n,int m,int a,int b)
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++) vis[i][j]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(vis[i][j]) continue;
			queue<node> q;
			q.push({i,j});
			vis[i][j]=1;
			col[i][j]=0;
			while(!q.empty())
			{
				node t=q.front();
				q.pop();
				for(k=0;k<8;k++)
				{
					if(k%4==0) swap(a,b);
					node nex=t;
					nex.x+=dir[k&3][0]*a;
					nex.y+=dir[k&3][1]*b;
					if(!ck(n,m,nex.x,nex.y)) continue;
					if(vis[nex.x][nex.y])
					{
						assert(col[t.x][t.y]!=col[nex.x][nex.y]);
						continue;
					}
					q.push(nex);
					vis[nex.x][nex.y]=1;
					col[nex.x][nex.y]=(!col[t.x][t.y]);
				}
			}
		}
	}
}
int main()
{
	int n,m,a,b,i,j,k,tot,s,t,x,y,p,ans;
	a=3;
	b=1;
	scanf("%d%d%d",&n,&m,&k);
	ans=n*m;
	for(i=1;i<=k;i++)
	{
		scanf("%d%d",&x,&y);
		if(mp[x][y]==0)
		{
			ans--;
			mp[x][y]=1;
		}
	}
	init_col(n,m,a,b);
	tot=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++) id[i][j]=++tot;
	}
	s=++tot;
	t=++tot;
	dc.init(t);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]) continue;
			if(!col[i][j]) dc.add_edge(s,id[i][j],1);
			else
			{
				dc.add_edge(id[i][j],t,1);
				continue;
			}
			for(k=0;k<8;k++)
			{
				if(k%4==0) swap(a,b);
				x=i+dir[k&3][0]*a;
				y=j+dir[k&3][1]*b;
				if(!ck(n,m,x,y)) continue;
				if(mp[x][y]) continue;
				dc.add_edge(id[i][j],id[x][y],1);
				assert(col[i][j]!=col[x][y]);
			}
		}
	}
	ans-=dc.max_flow(s,t);
	printf("%d\n",ans);
	return 0;
}
// abc445_g
