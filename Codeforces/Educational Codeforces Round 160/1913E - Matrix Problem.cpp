#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
struct MCMF_dij
{
	#define type int
	#define inf INF
	#define PTI pair<type,int>
	static const int N=1000;
	struct node
	{
		int from,to;
		type flow,cost;
		node(){}
		node(int u,int v,type f,type co):from(u),to(v),flow(f),cost(co){}
	};
	int n,s,t,id[N];
	vector<node> edge;
	vector<int> mp[N];
	type dis[N],h[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
		edge.clear();
	}
	void add_edge(int from,int to,type cap,type cost=0)
	{
		edge.push_back(node(from,to,cap,cost));
		edge.push_back(node(to,from,0,-cost));
		int m=edge.size();
		mp[from].push_back(m-2);
		mp[to].push_back(m-1);
	}
	bool dij()
	{
		int i,x,to;
		type cost,now_cost;
		for(i=0;i<=n;i++) dis[i]=inf;
		dis[s]=0;id[s]=0;
		priority_queue<PTI ,vector<PTI>,greater<PTI> > q;
		q.push({type(0),s});
		while(!q.empty())
		{
			PTI tmp=q.top();
			q.pop();
			cost=tmp.first;
			x=tmp.second;
			if(cost>dis[x]) continue;
			for(i=0;i<mp[x].size();i++)
			{
				node& e=edge[mp[x][i]];
				to=e.to;
				type now_cost=e.cost+h[x]-h[to];
				if(e.flow>0&&dis[to]>dis[x]+now_cost)
				{
					dis[to]=dis[x]+now_cost;
					q.push({dis[to],to});
					e.from=x;
					id[to]=mp[x][i];
				}
			}
		}
		return dis[t]!=inf;
	}
	pair<type,type> mincost_maxflow(int _s,int _t)
	{
		int i;
		type flow=0,cost=0;
		for(int i=0;i<=n;i++) h[i]=0;
		s=_s;
		t=_t;
		while(dij())
		{
			for(i=0;i<=n;i++) h[i]+=dis[i];
			type new_flow=inf;
			for(i=t;i!=s;i=edge[id[i]].from)
			{
				new_flow=min(new_flow,edge[id[i]].flow);
			}
			for(i=t;i!=s;i=edge[id[i]].from)
			{
				edge[id[i]].flow-=new_flow;
				edge[id[i]^1].flow+=new_flow;
			}
			flow+=new_flow;
			cost+=new_flow*h[t];
		}
		return {cost,flow};
	}
	#undef type
	#undef inf
	#undef PTI
}mcmf; //upper: O(nmlog(nm) + max_flow*mlogm)
int mp[55][55];
int a[55],b[55],idn0[55],idn1[55],idm0[55],idm1[55];
int main()
{
	int n,m,i,j,tot,S,T,sum;
	scanf("%d%d",&n,&m);
	tot=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&mp[i][j]);
		}
	}
	sum=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		idn0[i]=++tot;
		idn1[i]=++tot;
		sum+=a[i];
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		idm0[i]=++tot;
		idm1[i]=++tot;
		sum-=b[i];
	}
	if(sum)
	{
		puts("-1");
		return 0;
	}
	S=++tot;
	T=++tot;
	mcmf.init(T);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(mp[i][j])
			{
				mcmf.add_edge(idn1[i],idm1[j],1,0);
				mcmf.add_edge(idn0[i],idm0[j],1,1);
			}
			else
			{
				mcmf.add_edge(idn1[i],idm1[j],1,1);
				mcmf.add_edge(idn0[i],idm0[j],1,0);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		mcmf.add_edge(S,idn0[i],m-a[i],0);
		mcmf.add_edge(S,idn1[i],a[i],0);
	}
	for(i=1;i<=m;i++)
	{
		mcmf.add_edge(idm0[i],T,n-b[i],0);
		mcmf.add_edge(idm1[i],T,b[i],0);
	}
	auto res=mcmf.mincost_maxflow(S,T);
	if(res.second!=n*m) puts("-1");
	else printf("%d\n",res.first);
	return 0;
}
