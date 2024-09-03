#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e3+10;
struct Dijkstra
{
	#define type ll
	const type inf=LLINF;
	struct node
	{
		int id;
		type v;
		friend bool operator <(node a,node b){return a.v>b.v;}
	};
	static const int N=MAX;
	vector<node> mp[N];
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
				to=it.id;
				w=it.v;
				if(dis[to]>dis[t.id]+w)
				{
					dis[to]=dis[t.id]+w;
					if(!vis[to]) q.push({to,dis[to]});
				}
			}
		}
	}
	#undef type
}dij;
struct node
{
	int x;
	ll v;
	friend bool operator<(node a,node b)
	{
		return a.v+dij.dis[a.x]>b.v+dij.dis[b.x];
	}
};
vector<node> mp[MAX];
int main()
{
	int n,m,k,i,a,b,c,s,t;
	scanf("%d%d%d",&n,&m,&k);
	dij.init(n);
	for(i=1;i<=n;i++) mp[i].clear();
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		dij.add_edge(b,a,c);
		mp[a].push_back({b,c});
	}
	s=n;
	t=1;
	dij.work(t);
	priority_queue<node> q;
	q.push({s,0});
	while(!q.empty() && k>0)
	{
		node now=q.top();
		q.pop();
		if(now.x==1)
		{
			printf("%lld\n",now.v);
			k--;
		}
		for(auto &it:mp[now.x]) q.push({it.x,now.v+it.v});
	}
	while(k--) puts("-1");
	return 0;
}
