#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Dijkstra
{
	#define type ll
	const type inf=LLINF;
	struct node
	{
		int id;
		type v;
		friend bool operator < (node a,node b){return a.v>b.v;}
	};
	struct edge{int to;type w;};
	static const int N=MAX;
	vector<edge> mp[N];
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
				to=it.to;
				w=it.w;
				if(dis[to]>dis[t.id]+w)
				{
					dis[to]=dis[t.id]+w;
					q.push({to,dis[to]});
				}
			}
		}
	}
	#undef type
}dij;
int main()
{
	int n,m,y,a,b,c,i,x;
	ll ans;
	scanf("%d%d%d",&n,&m,&y);
	dij.init(n+1);
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		dij.add_edge(a,b,c);
		dij.add_edge(b,a,c);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		dij.add_edge(i,n+1,x);
		dij.add_edge(n+1,i,x+y);
	}
	dij.work(1);
	for(i=2;i<=n;i++) printf("%lld%c",dij.dis[i]," \n"[i==n]);
	return 0;
}
