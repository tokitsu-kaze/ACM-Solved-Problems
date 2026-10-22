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
		int sub,add;
		friend bool operator < (node a,node b){return a.v>b.v;}
	};
	struct edge{int to;type w;};
	static const int N=MAX;
	vector<edge> mp[N];
	type dis[N][2][2];
	int n,vis[N][2][2];
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
			memset(dis[i],0x3f,sizeof dis[i]);
			memset(vis[i],0,sizeof vis[i]);
		}
		dis[s][0][0]=0;
		q.push({s,type(0),0,0});
		while(!q.empty())
		{
			node t=q.top();
			q.pop();
			if(vis[t.id][t.sub][t.add]) continue;
			vis[t.id][t.sub][t.add]=1;
			for(auto &it:mp[t.id])
			{
				to=it.to;
				w=it.w;
				if(dis[to][t.sub][t.add]>dis[t.id][t.sub][t.add]+w)
				{
					dis[to][t.sub][t.add]=dis[t.id][t.sub][t.add]+w;
					q.push({to,dis[to][t.sub][t.add],t.sub,t.add});
				}
				if(t.sub==0)
				{
					if(dis[to][t.sub+1][t.add]>dis[t.id][t.sub][t.add])
					{
						dis[to][t.sub+1][t.add]=dis[t.id][t.sub][t.add];
						q.push({to,dis[to][t.sub+1][t.add],t.sub+1,t.add});
					}
				}
				if(t.add==0)
				{
					if(dis[to][t.sub][t.add+1]>dis[t.id][t.sub][t.add]+2*w)
					{
						dis[to][t.sub][t.add+1]=dis[t.id][t.sub][t.add]+2*w;
						q.push({to,dis[to][t.sub][t.add+1],t.sub,t.add+1});
					}
				}
				if(t.sub==0 && t.add==0)
				{
					if(dis[to][t.sub+1][t.add+1]>dis[t.id][t.sub][t.add]+w)
					{
						dis[to][t.sub+1][t.add+1]=dis[t.id][t.sub][t.add]+w;
						q.push({to,dis[to][t.sub+1][t.add+1],t.sub+1,t.add+1});
					}
				}
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
	for(i=2;i<=n;i++) printf("%lld%c",dij.dis[i][1][1]," \n"[i==n]);
	return 0;
}
/*
求 min{路径长度-最大边+最小边}。
可以将，减最大边看作减掉一条边，加最小边看作将某条边变为2倍。
这样转化是与原问题等价的。
因为求的是最小值，如果减掉的不是最大边，变为2倍的不是最小边，肯定不优。
然后直接跑 dij 即可。
*/
