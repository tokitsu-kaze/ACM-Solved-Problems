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
		int f,cnt;
		friend bool operator < (node a,node b){return a.v>b.v;}
	};
	struct edge{int to;type w;};
	static const int N=MAX;
	vector<edge> mp[N];
	type dis[N][2][4];
	int n,vis[N][2][4];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type v){mp[x].push_back({y,v});}
	void work(int s,int tar)
	{
		int i,to;
		type w;
		priority_queue<node> q;
		for(i=0;i<=n;i++)
		{
			memset(dis[i],0x3f,sizeof dis[i]);
			memset(vis[i],0,sizeof vis[i]);
		}
		if(s==tar)
		{
			dis[s][1][3]=0;
			q.push({s,type(0),1,3});
		}
		else
		{
			dis[s][0][0]=0;
			q.push({s,type(0),0,0});
		}
		while(!q.empty())
		{
			node t=q.top();
			q.pop();
			if(vis[t.id][t.f][t.cnt]) continue;
			vis[t.id][t.f][t.cnt]=1;
			for(auto &it:mp[t.id])
			{
				to=it.to;
				w=it.w;
				node nex=t;
				nex.id=to;
				nex.v=t.v+w;
				if(to==tar && t.f==0)
				{
					nex.f=1;
					nex.cnt=3;
				}
				if(dis[to][nex.f][nex.cnt]>nex.v)
				{
					dis[to][nex.f][nex.cnt]=nex.v;
					q.push(nex);
				}
			}
			if(t.cnt>0)
			{
				for(auto &it:mp[t.id])
				{
					to=it.to;
					node nex=t;
					nex.id=to;
					nex.v=t.v+1;
					nex.cnt--;
					if(dis[to][nex.f][nex.cnt]>nex.v)
					{
						dis[to][nex.f][nex.cnt]=nex.v;
						q.push(nex);
					}
				}
			}
		}
	}
	#undef type
}dij;
int main()
{
	int n,m,x,a,b,c,i;
	ll ans;
	scanf("%d%d%d",&n,&m,&x);
	dij.init(n);
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		dij.add_edge(a,b,c);
		dij.add_edge(b,a,c);
	}
	dij.work(n,x);
	ans=dij.dis[1][0][0];
	for(i=0;i<=3;i++) ans=min(ans,dij.dis[1][1][i]);
	if(ans==LLINF) ans=-1;
	printf("%lld\n",ans);
	return 0;
}
