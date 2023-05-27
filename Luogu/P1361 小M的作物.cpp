#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int MAX=1000+10;
const ll LLINF=0x3f3f3f3f3f3f3f3fll;
struct Dinic
{
	#define type ll
	#define inf LLINF
	static const int N=3005;
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
int a[MAX],b[MAX];
int main()
{
	int n,m,i,s,t,k,x,c1,c2;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) scanf("%d",&b[i]);
	scanf("%d",&m);
	s=n+2*m+1;
	t=s+1;
	dc.init(t);
	ans=0;
	for(i=1;i<=n;i++)
	{
		dc.add_edge(s,i,a[i]);
		dc.add_edge(i,t,b[i]);
		ans+=a[i]+b[i];
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&k,&c1,&c2);
		ans+=c1+c2;
		dc.add_edge(s,n+i,c1);
		dc.add_edge(n+m+i,t,c2);
		while(k--)
		{
			scanf("%d",&x);
			dc.add_edge(n+i,x,LLINF);
			dc.add_edge(x,n+m+i,LLINF);
		}
	}
	printf("%lld\n",ans-dc.max_flow(s,t));
	return 0;
}
