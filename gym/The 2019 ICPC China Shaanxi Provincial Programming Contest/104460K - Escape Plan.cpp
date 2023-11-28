#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct Dijkstra
{
	#define type int
	const type inf=INF;
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
	int ban[N];
	void work(vector<int> &s)
	{
		int i,to;
		type w;
		priority_queue<node> q;
		for(i=0;i<=n;i++)
		{
			dis[i]=inf;
			vis[i]=0;
		}
		for(auto &it:s)
		{
			ban[it]=0;
			dis[it]=0;
			q.push({it,type(0)});
		}
		while(!q.empty())
		{
			node t=q.top();
			q.pop();
			if(ban[t.id]>0)
			{
				ban[t.id]--;
				continue;
			}
			if(vis[t.id]) continue;
			vis[t.id]=1;// this node has already been extended
			dis[t.id]=t.v;
			for(auto &it:mp[t.id])
			{
				to=it.id;
				w=it.v;
				if(!vis[to]) q.push({to,t.v+w}); 
			}
		}
	}
	#undef type
}dij;
int main()
{
	int t,n,m,k,i,a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		dij.init(n);
		vector<int> s;
		while(k--)
		{
			scanf("%d",&a);
			s.push_back(a);
		}
		for(i=1;i<=n;i++) scanf("%d",&dij.ban[i]);
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			dij.add_edge(a,b,c);
			dij.add_edge(b,a,c);
		}
		dij.work(s);
		if(dij.dis[1]==dij.inf) puts("-1");
		else printf("%d\n",dij.dis[1]);
	}
	return 0;
}
