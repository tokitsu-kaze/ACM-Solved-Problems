#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
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
	bool merge(int a,int b)
	{
		int ra,rb;
		ra=find(a);
		rb=find(b);
		if(ra!=rb)
		{
			pre[ra]=rb;
			sz[rb]+=sz[ra];
			return 1;
		}
		return 0;
	}
}dsu;
struct LCA
{
	#define type int
	static const int N=MAX;
	static const int LOGN=log2(N)+3;
	struct node{int to;type w;};
	int fa[N][LOGN],dep[N],limt,bin[LOGN],n,len[N];
	type dis[N],mn[N][LOGN];
	bool vis[N];
	vector<node> mp[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int a,int b,type w=1){mp[a].push_back({b,w});}
	void dfs(int x,int pre)
	{
		int i;
		vis[x]=1;
		for(i=1;bin[i]<=dep[x];i++)
		{
			fa[x][i]=fa[fa[x][i-1]][i-1];
			mn[x][i]=min(mn[fa[x][i-1]][i-1],mn[x][i-1]);
		}
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(to==pre) continue;
			dis[to]=dis[x]+it.w;
			len[to]=len[x]+1;
			dep[to]=dep[x]+1;
			fa[to][0]=x;
			mn[to][0]=it.w;
			dfs(to,x);
		}
	}
	void work()
	{
		int i;
		for(limt=1;(1<<(limt-1))<n;limt++);
		for(i=bin[0]=1;i<=limt;i++) bin[i]=(bin[i-1]<<1);
		for(i=0;i<=n;i++)
		{
			dis[i]=len[i]=vis[i]=0;
			memset(fa[i],0,sizeof fa[i]);
			memset(mn[i],0,sizeof mn[i]);
		}
		for(i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			dep[i]=len[i]=dis[i]=0;
			dfs(i,0);
		}
	}
	pair<int,type> go(int x,int d)
	{
		type res=INF;
		for(int i=0;i<=limt&&d;i++)
		{
			if(bin[i]&d)
			{
				d^=bin[i];
				res=min(res,mn[x][i]);
				x=fa[x][i];
			}
		}
		return {x,res};
	}
	pair<int,type> lca(int x,int y)
	{
		if(dep[x]<dep[y]) swap(x,y);
		auto it=go(x,dep[x]-dep[y]);
		x=it.first;
		type res=it.second;
		if(x==y) return {x,res};
		for(int i=limt;~i;i--)
		{
			if(fa[x][i]!=fa[y][i])
			{
				res=min({res,mn[x][i],mn[y][i]});
				x=fa[x][i];
				y=fa[y][i];
			}
		}
		return {fa[x][0],min({res,mn[x][0],mn[y][0]})};
	}
	#undef type
}lca;
/*
O(nlogn)-O(logn)

lca.init(n);
lca.add_edge(a,b,w);
lca.work(rt);
*/
struct node{int x,y,w;};
int main()
{
	int t,n,m,i,a,b,c,ca,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		dsu.init(n);
		lca.init(n);
		vector<node> e;
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(dsu.merge(a,b))
			{
				lca.add_edge(a,b,c);
				lca.add_edge(b,a,c);
			}
			else e.push_back({a,b,c});
		}
		lca.work();
		ans=INF;
		for(auto &it:e)
		{
			if(min(lca.lca(it.x,it.y).second,it.w)<ans)
			{
				ans=min(lca.lca(it.x,it.y).second,it.w);
				a=it.x;
				b=it.y;
			}
		}
		vector<int> ra,rb,res;
		ca=lca.lca(a,b).first;
		while(a!=ca)
		{
			ra.push_back(a);
			a=lca.go(a,1).first;
		}
		while(b!=ca)
		{
			rb.push_back(b);
			b=lca.go(b,1).first;
		}
		reverse(rb.begin(),rb.end());
		for(auto &it:ra) res.push_back(it);
		res.push_back(ca);
		for(auto &it:rb) res.push_back(it);
		printf("%d %d\n",ans,res.size());
		for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i==res.size()-1]);
	}
	return 0;
}
