#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int tag[MAX];
struct Dijkstra
{
	#define type ll
	const type inf=LLINF;
	struct node
	{
		int id;
		type v;
		int f;
		friend bool operator <(node a,node b){return a.v>b.v;}
	};
	static const int N=MAX;
	vector<node> mp[N];
	type dis[N][2];
	int n,vis[N][2];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type v){mp[x].push_back({y,v});}
	void work(int s)
	{
		int i,to,f;
		type w;
		priority_queue<node> q;
		for(i=0;i<=n;i++)
		{
			dis[i][0]=dis[i][1]=inf;
			vis[i][0]=vis[i][1]=0;
		}
		dis[s][0]=0;
		q.push({s,type(0),0});
		if(tag[s])
		{
			dis[s][1]=0;
			q.push({s,type(0),1});
		}
		while(!q.empty())
		{
			node t=q.top();
			q.pop();
			if(vis[t.id][t.f]) continue;
			vis[t.id][t.f]=1;// this node has already been extended
			for(auto &it:mp[t.id])
			{
				to=it.id;
				if(t.f) w=it.v/2;
				else w=it.v;
				f=t.f;
				if(tag[to]) f|=1;
				if(dis[to][f]>t.v+w)
				{
					dis[to][f]=t.v+w;
					if(!vis[to][f]) q.push({to,dis[to][f],f});
				}
			}
		}
	}
	#undef type
}dij;
ll ra[MAX],rb[MAX];
int main()
{
	int T,n,m,h,i,a,b,c;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&h);
		for(i=1;i<=n;i++) tag[i]=0;
		for(i=1;i<=h;i++)
		{
			scanf("%d",&a);
			tag[a]=1;
		}
		dij.init(n);
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			dij.add_edge(a,b,c);
			dij.add_edge(b,a,c);
		}
		dij.work(1);
		for(i=1;i<=n;i++) ra[i]=min(dij.dis[i][0],dij.dis[i][1]);
		dij.work(n);
		for(i=1;i<=n;i++) rb[i]=min(dij.dis[i][0],dij.dis[i][1]);
		ans=LLINF;
		for(i=1;i<=n;i++) ans=min(ans,max(ra[i],rb[i]));
		if(ans==LLINF) ans=-1;
		printf("%lld\n",ans);
	}
	return 0;
}
