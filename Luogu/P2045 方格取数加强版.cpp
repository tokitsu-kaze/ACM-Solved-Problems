#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e4+10;
struct MCMF
{
	#define type ll
	#define inf LLINF
	static const int N=5000+10;
	struct node
	{
		int from,to;
		type cap,flow,cost;
		node(){}
		node(int u,int v,type c,type f,type co):from(u),to(v),cap(c),flow(f),cost(co){}
	};
	int n,s,t;
	vector<node> edge;
	vector<int> mp[N];
	int vis[N],id[N];
	type d[N],a[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
		edge.clear();
	}
	void add_edge(int from,int to,type cap,type cost)
	{
		edge.push_back(node(from,to,cap,0,cost));
		edge.push_back(node(to,from,0,0,-cost));
		int m=edge.size();
		mp[from].push_back(m-2);
		mp[to].push_back(m-1);
	}
	bool spfa(type& flow,type& cost)
	{
		for(int i=0;i<=n;i++)
		{
			d[i]=inf;
			vis[i]=0;
		}
		d[s]=0;vis[s]=1;id[s]=0;a[s]=inf;
		queue<int> q;
		q.push(s);
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			vis[x]=0;
			for(int i=0;i<mp[x].size();i++)
			{
				node& e=edge[mp[x][i]];
				int to=e.to;
				if(e.cap>e.flow&&d[to]>d[x]+e.cost)
				{ 
					d[to]=d[x]+e.cost;
					a[to]=min(a[x],e.cap-e.flow);
					id[to]=mp[x][i];
					if(!vis[to])
					{
						vis[to]=1;
						q.push(to);
					}
				}
			}
		}
		if(d[t]==inf) return false;
		flow+=a[t];
		cost+=a[t]*d[t];
		int x=t;
		while(x!=s)
		{
			edge[id[x]].flow+=a[t];
			edge[id[x]^1].flow-=a[t];
			x=edge[id[x]].from;
		}
		return true;
	}
	pair<type,type> mincost_maxflow(int _s,int _t)
	{
		type flow=0,cost=0;
		s=_s;
		t=_t;
		while(spfa(flow,cost));
		return {cost,flow};
	}
	#undef type
	#undef inf
}mcmf;
/*
mcmf.init(n);
mcmf.add_edge(a,b,cap,cost);  a,b: 1~n
*/
int mp[55][55],in_id[55][55],out_id[55][55];
int main()
{
	int n,k,i,j,tot,s,t;
	scanf("%d%d",&n,&k);
	tot=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&mp[i][j]);
			in_id[i][j]=++tot;
			out_id[i][j]=++tot;
		}
	}
	s=tot+1;
	t=s+1;
	mcmf.init(t);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			mcmf.add_edge(in_id[i][j],out_id[i][j],1,-mp[i][j]);
			mcmf.add_edge(in_id[i][j],out_id[i][j],INF,0);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i+1<=n) mcmf.add_edge(out_id[i][j],in_id[i+1][j],INF,0);
			if(j+1<=n) mcmf.add_edge(out_id[i][j],in_id[i][j+1],INF,0);
		}
	}
	mcmf.add_edge(s,in_id[1][1],k,0);
	mcmf.add_edge(out_id[n][n],t,k,0);
	printf("%lld\n",-mcmf.mincost_maxflow(s,t).first);
	return 0;
}
