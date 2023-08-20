#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=4e5+10;
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
struct Disjoint_Set_Union
{
	int pre[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++) pre[i]=i;
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int a,int b)
	{
		int ra,rb;
		ra=find(a);
		rb=find(b);
		if(ra!=rb)
		{
			pre[ra]=rb;
			return 1;
		}
		return 0;
	}
}dsu;
struct Kruskal_Tree
{
	#define type int
	#define inf INF
	struct edge{int x,y;type a;};
	vector<edge> e;
	void init(){e.clear();}
	void add_edge(int x,int y,type a){e.push_back({x,y,a});}
	int build_kruskal_tree(int n,vector<int> *mp,type *w)
	{
		int rt,x,y,i;
		for(i=1;i<=2*n-1;i++)
		{
			mp[i].clear();
			w[i]=0;
		}
		dsu.init(2*n-1);
		sort(e.begin(),e.end(),[&](edge x,edge y){
			return x.a>y.a;
		});
		rt=n;
		for(auto &it:e)
		{
			x=dsu.find(it.x);
			y=dsu.find(it.y);
			if(x==y) continue;
			rt++;
			w[rt]=it.a;
			mp[rt].push_back(x);
			mp[rt].push_back(y);
			dsu.merge(x,rt);
			dsu.merge(y,rt);
		}
		return rt;
	}
	#undef type
	#undef inf
}krsk;
vector<int> mp[MAX];
const int LOG=log2(MAX);
int w[MAX],fa[MAX][LOG+1],mn[MAX];
void dfs(int x,int pre)
{
	mn[x]=dij.dis[x];
	fa[x][0]=pre;
	for(int i=1;i<=LOG;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(auto &to:mp[x])
	{
		if(to==pre) continue;
		dfs(to,x);
		mn[x]=min(mn[x],mn[to]);
	}
}
int main()
{
	int t,n,m,i,a,b,c,d,q,k,s,rt,v,p,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		krsk.init();
		dij.init(2*n-1);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			krsk.add_edge(a,b,d);
			dij.add_edge(a,b,c);
			dij.add_edge(b,a,c);
		}
		dij.work(1);
		rt=krsk.build_kruskal_tree(n,mp,w);
		memset(fa[0],0,sizeof fa[0]);
		dfs(rt,0);
		scanf("%d%d%d",&q,&k,&s);
		ans=0;
		while(q--)
		{
			scanf("%d%d",&v,&p);
			v=(v+k*ans-1)%n+1;
			p=(p+k*ans)%(s+1);
			for(i=LOG;~i;i--)
			{
				if(fa[v][i]&&w[fa[v][i]]>p) v=fa[v][i];
			}
			ans=mn[v];
			printf("%d\n",ans);
		}
	}
	return 0;
}
