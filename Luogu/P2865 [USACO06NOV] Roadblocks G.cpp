#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
	type dis[N],ndis[MAX];
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
			ndis[i]=inf;
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
					ndis[to]=dis[to];
					dis[to]=dis[t.id]+w;
					if(!vis[to]) q.push({to,dis[to]});
				}
				else if(dis[to]<dis[t.id]+w)
				{
					ndis[to]=min(ndis[to],dis[t.id]+w);
				}
				ndis[to]=min(ndis[to],ndis[t.id]+w);
				ndis[to]=min(ndis[to],dis[t.id]+3*w);
			}
		}
	}
	#undef type
}dij;
int main()
{
	int n,m,i,a,b,c;
	scanf("%d%d",&n,&m);
	dij.init(n);
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		dij.add_edge(a,b,c);
		dij.add_edge(b,a,c);
	}
	dij.work(1);
	printf("%d\n",dij.ndis[n]);
	return 0;
}
/*
3 3
1 2 1
2 3 1
1 3 2
*/
