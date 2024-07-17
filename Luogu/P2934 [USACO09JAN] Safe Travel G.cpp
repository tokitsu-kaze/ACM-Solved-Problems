#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct Disjoint_Set_Union
{
	int pre[MAX],sz[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
			sz[i]=1;
		}
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int x,int y,bool dir=false)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(!dir && sz[x]>sz[y]) swap(x,y);
		pre[x]=y; // x -> y
		sz[y]+=sz[x];
		return 1;
	}
}dsu;
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
int dep[MAX],fa[MAX],ans[MAX];
void dfs(int x,int pre)
{
	fa[x]=pre;
	dep[x]=dep[pre]+1;
	for(auto &to:mp[x])
	{
		if(to==pre) continue;
		dfs(to,x);
	}
}
struct edge{int a,b,w;};
int main()
{
	int n,m,i,a,b,c;
	scanf("%d%d",&n,&m);
	dij.init(n);
	vector<edge> e,res;
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		dij.add_edge(a,b,c);
		dij.add_edge(b,a,c);
		e.push_back({a,b,c});
	}
	dij.work(1);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		ans[i]=-1;
	}
	for(auto &it:e)
	{
		if(dij.dis[it.a]+it.w==dij.dis[it.b]||
		   dij.dis[it.b]+it.w==dij.dis[it.a])
		{
			mp[it.a].push_back(it.b);
			mp[it.b].push_back(it.a);
		}
		else res.push_back(it);
	}
	sort(res.begin(),res.end(),[](edge x,edge y){
		int wx,wy;
		wx=dij.dis[x.a]+dij.dis[x.b]+x.w;
		wy=dij.dis[y.a]+dij.dis[y.b]+y.w;
		return wx<wy;
	});
	dep[0]=0;
	dfs(1,0);
	dsu.init(n);
	for(auto &it:res)
	{
		a=dsu.find(it.a);
		b=dsu.find(it.b);
		while(a!=b)
		{
			if(dep[a]<dep[b]) swap(a,b);
			ans[a]=dij.dis[it.a]+dij.dis[it.b]+it.w-dij.dis[a];
			dsu.merge(a,fa[a],true);
			a=dsu.find(a);
		}
	}
	for(i=2;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}
