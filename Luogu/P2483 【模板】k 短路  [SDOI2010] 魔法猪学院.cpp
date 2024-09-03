#include<bits/stdc++.h>
using namespace std;
const int MAX=2e5+10;
struct Persistent_Leftist_Tree
{
	#define type double
	struct node
	{
		int ls,rs,d,id;
		type v;
		void init(){ls=rs=d=id=v=0;}
	}t[MAX<<5];
	int root[MAX],tot,n,sz[MAX<<5];
	void init()
	{
		tot=0;
		t[0].init();
		sz[0]=0;
	}
	int new_node(type v,int _id)
	{
		int id=++tot;
		t[id].init();
		t[id].v=v;
		t[id].id=_id;
		sz[id]=1;
		return id;
	}
	int copy_node(int x)
	{
		tot++;
		t[tot]=t[x];
		return tot;
	}
	int merge(int x,int y)
	{
		if(!x||!y) return x+y;
		if(t[x].v>t[y].v) swap(x,y); // > small, < big
		int id=copy_node(x);
		t[id].rs=merge(t[x].rs,y);
		if(t[t[id].rs].d>t[t[id].ls].d) swap(t[id].ls,t[id].rs);
		t[id].d=t[t[id].rs].d+1;
		sz[id]=sz[t[id].ls]+sz[t[id].rs]+1;
		return id;
	}
	void copy_ver(int now_ver,int pre_ver)
	{
		root[now_ver]=root[pre_ver];
	}
	void clear_ver(int now_ver){root[now_ver]=0;}
	void push_ver(int now_ver,type v,int _id=0)
	{
		root[now_ver]=merge(root[now_ver],new_node(v,_id));
	}
	void pop_ver(int now_ver)
	{
		int x=root[now_ver];
		root[now_ver]=merge(t[x].ls,t[x].rs);
	}
	node top_ver(int now_ver){return t[root[now_ver]];}
	int size_ver(int now_ver){return sz[root[now_ver]];}
	#undef type
}pq;
/*
pq.init();
pq.copy_ver(now_ver,pre_ver);
pq.clear_ver(now_ver);
pq.push_ver(now_ver,v);
pq.pop_ver(now_ver);
pq.top_ver(now_ver);
*/
struct Dijkstra
{
	#define type double
	const type inf=1e12;
	struct node
	{
		int id;
		type v;
		int eid;
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
	void add_edge(int x,int y,type v,int eid){mp[x].push_back({y,v,eid});}
	void work(int s,int *fa,int *intree)
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
		q.push({s,type(0),0});
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
					fa[to]=t.id;
					intree[to]=it.eid;
					dis[to]=dis[t.id]+w;
					if(!vis[to]) q.push({to,dis[to],0});
				}
			}
		}
	}
	int fa[N];
	void build_short_path_tree(int s,vector<int> *new_mp,int *intree)
	{
		int i;
		for(i=0;i<=n;i++) new_mp[i].clear();
		work(s,fa,intree);
		for(i=1;i<=n;i++)
		{
			if(i==s) continue;
			new_mp[fa[i]].push_back(i);
		}
	}
	#undef type
}dij;
struct edge{int eid,to;double w;};
vector<edge> mp[MAX];
vector<int> trmp[MAX];
int intree[MAX];
bool vis[MAX];
void dfs(int x,int fa)
{
	pq.copy_ver(x,fa);
	for(auto &it:mp[x])
	{
		if(vis[it.eid]) continue;
		pq.push_ver(x,it.w-(dij.dis[x]-dij.dis[it.to]),it.to);
	}
	for(auto &to:trmp[x]) dfs(to,x);
}
struct node
{
	double v;
	int id;
	friend bool operator<(node x,node y){return x.v>y.v;}
};
int main()
{
	int n,m,i,a,b,ans,ls,rs,nexid;
	double sum,c;
	scanf("%d%d%lf",&n,&m,&sum);
	dij.init(n);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		trmp[i].clear();
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%lf",&a,&b,&c);
		if(a==n) continue;
		mp[a].push_back({i,b,c});
		dij.add_edge(b,a,c,i);
	}
	dij.build_short_path_tree(n,trmp,intree);
	if(sum<dij.dis[1]) return 0*puts("0");
	for(i=1;i<=m;i++) vis[i]=0;
	for(i=1;i<n;i++) vis[intree[i]]=1;
	pq.init();
	pq.clear_ver(0);
	dfs(n,0);
	priority_queue<node> q;
	q.push({dij.dis[1]+pq.t[pq.root[1]].v,pq.root[1]});
	ans=1;
	sum-=dij.dis[1];
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
//		cout<<t.v<<endl;
		if(sum-t.v<0) break;
		sum-=t.v;
		ans++;
		
		nexid=pq.root[pq.t[t.id].id];
		ls=pq.t[t.id].ls;
		rs=pq.t[t.id].rs;
		if(nexid) q.push({t.v+pq.t[nexid].v,nexid});
		if(ls) q.push({t.v-pq.t[t.id].v+pq.t[ls].v,ls});
		if(rs) q.push({t.v-pq.t[t.id].v+pq.t[rs].v,rs});
	}
	printf("%d\n",ans);
	return 0;
}
