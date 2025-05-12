#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct Dijkstra
{
	#define type ll
	#define inf LLINF
	struct node
	{
		int id,k;
		type v;
		friend bool operator <(node a,node b){return a.v>b.v;}
	};
	static const int N=MAX;
	vector<node> mp[N];
	type dis[N][12];
	int n,vis[N][5];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type v){mp[x].push_back({y,0,v});}
	void work(int s,int K)
	{
		int i,to;
		type w;
		priority_queue<node> q;
		for(i=0;i<=n;i++)
		{
			memset(dis[i],0x3f,sizeof dis[i]);
			memset(vis[i],0,sizeof vis[i]);
		}
		dis[s][0]=0;
		q.push({s,0,type(0)});
		while(!q.empty())
		{
			node t=q.top();
			q.pop();
			if(vis[t.id][t.k]) continue;
			vis[t.id][t.k]=1;// this node has already been extended
			for(auto &it:mp[t.id])
			{
				to=it.id;
				w=it.v;
				if(dis[to][t.k]>dis[t.id][t.k]+w)
				{
					dis[to][t.k]=dis[t.id][t.k]+w;
					if(!vis[to][t.k]) q.push({to,t.k,dis[to][t.k]}); 
				}
				if(t.k+1<=K && dis[to][t.k+1]>dis[t.id][t.k])
				{
					dis[to][t.k+1]=dis[t.id][t.k];
					if(!vis[to][t.k+1]) q.push({to,t.k+1,dis[to][t.k+1]}); 
				}
			}
		}
	}
	#undef type
	#undef inf
}dij;
int w[MAX];
int main()
{
	int n,m,k,i,a,b,s,t;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i++) scanf("%d",&w[i]);
	dij.init(n);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		dij.add_edge(a,b,w[i]);
		dij.add_edge(b,a,w[i]);
	}
	dij.work(1,k);
	ll ans=LLINF;
	for(i=0;i<=k;i++) ans=min(ans,dij.dis[n][i]);
	if(ans==LLINF) ans=-1;
	printf("%lld\n",ans);
}
