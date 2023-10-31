#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=55+10;
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
	static const int K=55;
	vector<node> mp[N];
	type dis[N][K];
	int n,vis[N][K];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type v){ mp[x].pb({y,0,v});}
	void work(int s,int k)
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
				if(t.k+1<=k && dis[to][t.k+1]>dis[t.id][t.k]+w/2)
				{
					dis[to][t.k+1]=dis[t.id][t.k]+w/2;
					if(!vis[to][t.k+1]) q.push({to,t.k+1,dis[to][t.k+1]}); 
				}
			}
		}
	}
	#undef type
	#undef inf
}dij;
int main()
{
	int n,m,k,i,a,b,s,t;
	ll v;
	scanf("%d%d%d",&n,&m,&k);
	dij.init(n);
	while(m--)
	{
		scanf("%d%d%lld",&a,&b,&v);
		dij.add_edge(a,b,v);
		dij.add_edge(b,a,v);
	}
	dij.work(1,n);
	ll ans=LLINF;
	for(i=0;i<=k;i++) ans=min(ans,dij.dis[n][i]);
	printf("%lld\n",ans);
}
