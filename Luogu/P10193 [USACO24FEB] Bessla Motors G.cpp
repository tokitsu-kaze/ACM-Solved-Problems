#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e4+10;
struct Dijkstra
{
	#define type int
	const type inf=INF;
	struct node
	{
		int be,id;
		type v;
		friend bool operator < (node a,node b){return a.v>b.v;}
	};
	struct edge{int to;type w;};
	static const int N=MAX;
	vector<edge> mp[N];
	int n;
	map<int,int> vis[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type v){mp[x].push_back({y,v});}
	void work(int c,int r,int k)
	{
		int i,to;
		type w;
		priority_queue<node> q;
		for(i=0;i<=n;i++) vis[i].clear();
		for(i=1;i<=c;i++) q.push({i,i,type(0)});
		while(!q.empty())
		{
			node t=q.top();
			q.pop();
			if(vis[t.id].count(t.be) || vis[t.id].size()>=k) continue;
			vis[t.id][t.be]=1;
			for(auto &it:mp[t.id])
			{
				to=it.to;
				w=it.w;
				if(t.v+w>r) continue;
				if(vis[to].count(t.be) || vis[to].size()>=k) continue;
				q.push({t.be,to,t.v+w});
			}
		}
	}
	#undef type
}dij;
int main()
{
	int n,m,c,r,k,i,a,b,w;
	scanf("%d%d%d%d%d",&n,&m,&c,&r,&k);
	dij.init(n);
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&w);
		dij.add_edge(a,b,w);
		dij.add_edge(b,a,w);
	}
	dij.work(c,r,k);
	vector<int> res;
	for(i=c+1;i<=n;i++)
	{
		if(dij.vis[i].size()==k) res.push_back(i);
	}
	printf("%d\n",(int)res.size());
	for(auto &it:res) printf("%d\n",it);
	return 0;
}
/*
这个题意应该是经过充电站不能充电的，只有起点能充电。
然后充电站不计入答案。 
多源最短路，维护每个点最先到达的10个起点。 
*/
