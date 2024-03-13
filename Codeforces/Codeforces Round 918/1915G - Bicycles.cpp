#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e3+10;
ll ss[MAX];
struct Dijkstra
{
	#define type ll
	const type inf=LLINF;
	struct node
	{
		int id,bid;
		type v;
		friend bool operator <(node a,node b){return a.v>b.v;}
	};
	static const int N=MAX;
	vector<node> mp[N];
	type dis[N][N];
	int n,vis[N][N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type v){mp[x].push_back({y,0,v});}
	void work(int s)
	{
		int i,to;
		type w;
		priority_queue<node> q;
		for(i=0;i<=n;i++)
		{
			memset(dis[i],0x3f,sizeof dis[i]);
			memset(vis[i],0,sizeof vis[i]);
		}
		dis[s][s]=0;
		q.push({s,s,type(0)});
		while(!q.empty())
		{
			node t=q.top();
			q.pop();
			if(vis[t.id][t.bid]) continue;
			vis[t.id][t.bid]=1;
			for(auto &it:mp[t.id])
			{
				to=it.id;
				w=it.v;
				if(dis[to][t.bid]>dis[t.id][t.bid]+ss[t.bid]*w)
				{
					dis[to][t.bid]=dis[t.id][t.bid]+ss[t.bid]*w;
					if(!vis[to][t.bid]) q.push({to,t.bid,dis[to][t.bid]}); 
				}
				if(dis[to][t.id]>dis[t.id][t.bid]+ss[t.id]*w)
				{
					dis[to][t.id]=dis[t.id][t.bid]+ss[t.id]*w;
					if(!vis[to][t.id]) q.push({to,t.id,dis[to][t.id]}); 
				}
			}
		}
	}
	#undef type
}dij;
int main()
{
	int t,n,m,i,a,b,c;
	ll ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		dij.init(n);
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			dij.add_edge(a,b,c);
			dij.add_edge(b,a,c);
		}
		for(i=1;i<=n;i++) scanf("%lld",&ss[i]);
		dij.work(1);
		ans=LLINF;
		for(i=1;i<=n;i++) ans=min(ans,dij.dis[n][i]);
		printf("%lld\n",ans);
	}
	return 0;
}

