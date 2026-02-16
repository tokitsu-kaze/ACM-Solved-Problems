#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
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
	int n,vis[N],deg[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++)
		{
			mp[i].clear();
			deg[i]=0;
		}
	}
	void add_edge(int x,int y,type v)
	{
		mp[x].push_back({y,v});
		deg[y]++;
	}
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
				w=deg[to]--;
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
int main()
{
	int n,m,i,a,b;
	scanf("%d%d",&n,&m);
	dij.init(n);
	while(m--)
	{
		scanf("%d%d",&a,&b);
		dij.add_edge(b,a,1);
	}
	dij.work(n);
	printf("%d\n",dij.dis[1]);
	return 0;
}
/*
反向建图从n开始dp。
用类似dij的写法做dp，转移时用出度辅助计算cost。
*/
