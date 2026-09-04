#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
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
	type dis[N],cnt[N];
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
		cnt[s]=1;
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
					cnt[to]=cnt[t.id];
				}
				else if(dis[to]==dis[t.id]+w)
				{
					cnt[to]+=cnt[t.id];
				}
			}
		}
	}
	#undef type
}dij;
int mp[MAX][MAX];
int main()
{
	int n,m,i,j,a,b,c;
	scanf("%d%d",&n,&m);
	memset(mp,0x3f,sizeof mp);
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		mp[a][b]=min(mp[a][b],c);
	}
	dij.init(n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(mp[i][j]==INF) continue;
			dij.add_edge(i,j,mp[i][j]);
		}
	}
	dij.work(1);
	if(dij.dis[n]==dij.inf) puts("No answer");
	else printf("%d %d\n",dij.dis[n],dij.cnt[n]);
	return 0;
}

