#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int mod=998244353;
const int MAX=2e5+10;
struct Dijkstra
{
	#define type ll
	const type inf=LLINF;
	struct node
	{
		int id,f;
		type v;
		friend bool operator <(node a,node b){return a.v>b.v;}
	};
	static const int N=MAX;
	vector<node> mp[2][N];
	type dis[N][2];
	int n,vis[N][2];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++)
		{
			mp[0][i].clear();
			mp[1][i].clear();
		}
	}
	void add_edge(int x,int y,type v)
	{
		mp[0][x].push_back({y,-1,v});
		mp[1][y].push_back({x,-1,v});
	}
	void work(int s,type x)
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
		dis[s][1]=x;
		q.push({s,0,type(0)});
		q.push({s,1,type(x)});
		while(!q.empty())
		{
			node t=q.top();
			q.pop();
			if(vis[t.id][t.f]) continue;
			vis[t.id][t.f]=1;// this node has already been extended
			for(auto &it:mp[t.f][t.id])
			{
				to=it.id;
				w=it.v;
				if(dis[to][t.f]>dis[t.id][t.f]+w)
				{
					dis[to][t.f]=dis[t.id][t.f]+w;
					if(!vis[to][t.f]) q.push({to,t.f,dis[to][t.f]});
				}
			}
			for(auto &it:mp[!t.f][t.id])
			{
				to=it.id;
				w=it.v;
				if(dis[to][!t.f]>dis[t.id][t.f]+w+x)
				{
					dis[to][!t.f]=dis[t.id][t.f]+w+x;
					if(!vis[to][!t.f]) q.push({to,!t.f,dis[to][!t.f]});
				}
			}
		}
	}
	#undef type
}dij;
int main()
{
	int n,m,x,i,a,b;
	scanf("%d%d%d",&n,&m,&x);
	dij.init(n);
	while(m--)
	{
		scanf("%d%d",&a,&b);
		dij.add_edge(a,b,1);
	}
	dij.work(1,x);
	printf("%lld\n",min(dij.dis[n][0],dij.dis[n][1]));
	return 0;
}
