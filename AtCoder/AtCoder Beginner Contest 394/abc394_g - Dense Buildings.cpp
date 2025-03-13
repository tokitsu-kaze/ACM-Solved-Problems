#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=6e5+10;
struct LCA
{
	static const int N=MAX;
	static const int LOG=log2(N)+2;
	int fa[LOG][N],dep[N];
	vector<int> *mp;
	void dfs(int x,int pre)
	{
		int i;
		fa[0][x]=pre;
		for(i=1;i<LOG;i++) fa[i][x]=fa[i-1][fa[i-1][x]];
		for(auto &to:mp[x])
		{
			if(to==pre) continue;
			dep[to]=dep[x]+1;
			dfs(to,x);
		}
	}
	void work(int root,vector<int> *_mp)
	{
		mp=_mp;
		for(int j=0;j<LOG;j++) fa[j][0]=0;
		dep[root]=0;
		dfs(root,0);
	}
	int go(int x,int d)
	{
		for(int i=0;i<LOG;i++)
		{
			if((d>>i)&1) x=fa[i][x];
		}
		return x;
	}
	int lca(int x,int y)
	{
		if(dep[x]<dep[y]) swap(x,y);
		x=go(x,dep[x]-dep[y]);
		if(x==y) return x;
		for(int i=LOG-1;~i;i--)
		{
			if(fa[i][x]!=fa[i][y])
			{
				x=fa[i][x];
				y=fa[i][y];
			}
		}
		return fa[0][x];
	}
}lca;
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
struct Kruskal_Tree
{
	#define type int
	struct edge{int x,y;type w;};
	vector<edge> e;
	void init(){e.clear();}
	void add_edge(int x,int y,type w){e.push_back({x,y,w});}
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
			return x.w>y.w;
		});
		rt=n;
		for(auto &it:e)
		{
			x=dsu.find(it.x);
			y=dsu.find(it.y);
			if(x==y) continue;
			rt++;
			w[rt]=it.w;
			mp[rt].push_back(x);
			mp[rt].push_back(y);
			dsu.merge(x,rt,true);
			dsu.merge(y,rt,true);
		}
		return rt;
	}
	#undef type
}krsk;
/*
O(nlogn)-O(logn)
lca.work(n,root,mp);
*/
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int id[505][505],h[505][505],w[MAX];
vector<int> mp[MAX];
int main()
{
	int n,m,i,j,k,q,a,b,c,d,x,y,tot,rt,tmp;
	scanf("%d%d",&n,&m);
	tot=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			id[i][j]=++tot;
			scanf("%d",&h[i][j]);
		}
	}
	krsk.init();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			for(k=0;k<4;k++)
			{
				x=i+dir[k][0];
				y=j+dir[k][1];
				if(x<1||x>n||y<1||y>m) continue;
				krsk.add_edge(id[i][j],id[x][y],min(h[i][j],h[x][y]));
			}
		}
	}
	rt=krsk.build_kruskal_tree(tot,mp,w);
	lca.work(rt,mp);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d%d%d%d",&a,&b,&x,&c,&d,&y);
		if(id[a][b]==id[c][d])
		{
			printf("%d\n",abs(x-y));
			continue;
		}
		tmp=w[lca.lca(id[a][b],id[c][d])];
//		cout<<tmp<<endl;
		if(tmp>=max(x,y)) printf("%d\n",abs(x-y));
		else printf("%d\n",abs(x-tmp)+abs(y-tmp));
	}
	return 0;
}
