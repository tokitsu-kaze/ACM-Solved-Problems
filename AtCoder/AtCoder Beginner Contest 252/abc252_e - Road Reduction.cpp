#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Dijkstra
{
	#define type ll
	const type inf=LLINF;
	static const int N=MAX;
	struct node
	{
		int id;
		type v;
		friend bool operator <(node a,node b){return a.v>b.v;}
	};
	struct E{int to;type w;int eid;};
	vector<E> mp[N];
	type dis[N];
	int n,vis[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type w,int id){mp[x].push_back({y,w,id});}
	int ans[MAX];
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
				to=it.to;
				w=it.w;
				if(dis[to]>dis[t.id]+w)
				{
					dis[to]=dis[t.id]+w;
					ans[to]=it.eid;
					if(!vis[to]) q.push({to,dis[to]});
				}
			}
		}
		vector<int> res;
		for(i=2;i<=n;i++) res.push_back(ans[i]);
		for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i==res.size()-1]);
	}
	#undef type
}dij;
int main()
{
	int n,m,i,a,b,c;
	scanf("%d%d",&n,&m);
	dij.init(n);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		dij.add_edge(a,b,c,i);
		dij.add_edge(b,a,c,i);
	}
	dij.work(1);
	return 0;
}
