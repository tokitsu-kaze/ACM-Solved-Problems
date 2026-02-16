#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Edge_Biconnected_Component
{
	int bcc_cnt,tot;
	int low[MAX],dfn[MAX];
	int st[MAX],top,col[MAX];
	vector<int> *mp;
	vector<pair<int,int>> bridge;
	void dfs(int x,int fa)
	{
		int i,tmp,k;
		st[top++]=x;
		low[x]=dfn[x]=++tot;
		k=0;
		for(auto &to:mp[x])
		{
			if(to==fa&&!k) 
			{
				k++;
				continue;
			}
			if(!dfn[to])
			{
				dfs(to,x);
				low[x]=min(low[x],low[to]);
				if(low[to]>dfn[x]) bridge.push_back({x,to});
			}
			else low[x]=min(low[x],dfn[to]);
		}
		if(low[x]==dfn[x])
		{
			bcc_cnt++;
			do
			{
				tmp=st[--top];
				col[tmp]=bcc_cnt;
			}while(tmp!=x);
		}
	}
	void work(int n,vector<int> *_mp)
	{
		int i;
		mp=_mp;
		for(i=1;i<=n;i++) low[i]=dfn[i]=col[i]=0;
		bcc_cnt=top=tot=0;
		bridge.clear();
		for(i=1;i<=n;i++)
		{
			if(!dfn[i]) dfs(i,i);
		}
	}
	void rebuild(int n,vector<int> *g)
	{
		int i;
		for(i=1;i<=n;i++) g[i].clear();
		for(i=1;i<=n;i++)
		{
			for(auto &to:mp[i])
			{
				if(col[i]==col[to]) continue;
				g[col[i]].push_back(col[to]);
			}
		}
	}
}bcc;
/*
bcc.work(n,mp);
*/
struct Dijkstra
{
	#define type ll
	const type inf=LLINF;
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
				w=it.v;
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
vector<int> mp[MAX];
ll dis1[MAX],disn[MAX];
int a[MAX],b[MAX],c[MAX],vis[MAX];
int main()
{
	int n,m,i,ok,x,y;
	scanf("%d%d",&n,&m);
	dij.init(n);
	map<pair<int,int>,int> id;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		dij.add_edge(a[i],b[i],c[i]);
		dij.add_edge(b[i],a[i],c[i]);
		id[{a[i],b[i]}]=i;
	}
	dij.work(1);
	for(i=1;i<=n;i++) dis1[i]=dij.dis[i];
	dij.work(n);
	for(i=1;i<=n;i++) disn[i]=dij.dis[i];
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<=m;i++)
	{
		ok=0;
		if(dis1[a[i]]+c[i]+disn[b[i]]==dis1[n]) ok=1;
		if(dis1[b[i]]+c[i]+disn[a[i]]==dis1[n]) ok=1;
		if(ok)
		{
			mp[a[i]].push_back(b[i]);
			mp[b[i]].push_back(a[i]);
		}
	}
	bcc.work(n,mp);
	for(i=1;i<=m;i++) vis[i]=0;
	for(auto &it:bcc.bridge)
	{
		x=it.first;
		y=it.second;
		if(x>y) swap(x,y);
		vis[id[{x,y}]]=1;
	}
	for(i=1;i<=m;i++)
	{
		if(vis[i]) puts("Yes");
		else puts("No");
	}
	return 0;
}
