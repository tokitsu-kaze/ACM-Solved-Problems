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
int a[MAX],b[MAX];
ll sum[MAX];
int main()
{
	int n,q,i,s,t;
	ll ans;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) scanf("%d",&b[i]);
	dij.init(n+1);
	sum[0]=0;
	for(i=1;i<=n;i++)
	{
		dij.add_edge(i,i%n+1,a[i]);
		dij.add_edge(i%n+1,i,a[i]);
		dij.add_edge(i,n+1,b[i]);
		dij.add_edge(n+1,i,b[i]);
		sum[i]=sum[i-1]+a[i];
	}
	dij.work(n+1);
	while(q--)
	{
		scanf("%d%d",&s,&t);
		assert(s<t);
		if(t==n+1)
		{
			printf("%lld\n",dij.dis[s]);
			continue;
		}
		ans=min(sum[t-1]-sum[s-1],sum[n]-(sum[t-1]-sum[s-1]));
		ans=min(ans,dij.dis[s]+dij.dis[t]);
		printf("%lld\n",ans);
	}
	return 0;
}
