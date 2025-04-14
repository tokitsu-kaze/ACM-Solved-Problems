#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Dinic
{
	#define type int
	const type inf=INF;
	static const int N=605;
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
int n;
ll sx[MAX],sy[MAX],gx[MAX],gy[MAX];
long double dist(int i,int j)
{
	__int128_t x=sx[i]-gx[j];
	__int128_t y=sy[i]-gy[j];
	return sqrtl(x*x+y*y);
}
int ck(long double x)
{
	int i,j,s,t;
	s=2*n+1;
	t=s+1;
	dc.init(t);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(dist(i,j)<=x) dc.add_edge(i,n+j,1);
		}
	}
	for(i=1;i<=n;i++)
	{
		dc.add_edge(s,i,1);
		dc.add_edge(n+i,t,1);
	}
	return dc.max_flow(s,t)==n;
}
int main()
{
	int i;
	long double l,r,mid;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld%lld",&sx[i],&sy[i]);
	for(i=1;i<=n;i++) scanf("%lld%lld",&gx[i],&gy[i]);
	l=0;
	r=2e18;
	for(i=0;i<100;i++)
	{
		mid=(l+r)/2;
		if(ck(mid)) r=mid;
		else l=mid;
	}
	printf("%.10Lf\n",r);
	return 0;
}
