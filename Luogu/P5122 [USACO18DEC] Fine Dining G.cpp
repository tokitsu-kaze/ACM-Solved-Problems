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
		friend bool operator < (node a,node b){return a.v>b.v;}
	};
	struct edge{int to;type w;};
	static const int N=MAX;
	vector<edge> mp[N];
	type dis[N];
	int n,vis[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type v){mp[x].push_back({y,v});}
	void work(vector<pair<int,int>> &be)
	{
		int i,to;
		type w;
		priority_queue<node> q;
		for(i=0;i<=n;i++)
		{
			dis[i]=inf;
			vis[i]=0;
		}
		for(auto &it:be)
		{
			dis[it.first]=it.second;
			q.push({it.first,it.second});
		}
		while(!q.empty())
		{
			node t=q.top();
			q.pop();
			if(vis[t.id]) continue;
			vis[t.id]=1;// this node has already been extended
			for(auto &it:mp[t.id])
			{
				to=it.to;
				w=it.w;
				if(dis[to]>dis[t.id]+w)
				{
					dis[to]=dis[t.id]+w;
					q.push({to,dis[to]});
				}
			}
		}
	}
	#undef type
}dij;
int d[MAX];
int main()
{
	int n,m,k,i,a,b,c;
	scanf("%d%d%d",&n,&m,&k);
	dij.init(n);
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		dij.add_edge(a,b,c);
		dij.add_edge(b,a,c);
	}
	vector<pair<int,int>> be;
	be.push_back({n,0});
	dij.work(be);
	for(i=1;i<=n;i++) d[i]=dij.dis[i];
	be.clear();
	for(i=1;i<=k;i++)
	{
		scanf("%d%d",&a,&b);
		be.push_back({a,d[a]-b});
	}
	dij.work(be);
	for(i=1;i<n;i++)
	{
		if(dij.dis[i]<=d[i]) puts("1");
		else puts("0");
	}
	return 0;
}
/*
直接分层图会有负权边。
列一下题目条件：dis[x][a]+dis[a][n]-dis[x][n]<=v
转化一下式子变为：dis[x][a]+dis[a][n]-v<=dis[x][n]，
其中 dis[a][n], dis[x][n] 可以以 n 为起点跑一遍最短路处理出来。
考虑从干草点出发跑最短路，左边式子可以看成：
从干草点 a 出发，初始代价为 (dis[a][n]-v)，跑到 x 的最短路。
虽然初始代价可能为负，但并不是负边权，所以跑 dij 是对的。
*/
