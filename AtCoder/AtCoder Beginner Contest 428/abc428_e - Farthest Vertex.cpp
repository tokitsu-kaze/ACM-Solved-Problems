#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
struct LCA
{
	static const int N=MAX;
	static const int LOG2N=log2(2*N)+3;
	#define type int
	struct node{int to;type w;};
	type dis[N];
	int path[2*N],deep[2*N],first[N],len[N],tot,n;
	int dp[2*N][LOG2N];
	vector<node> mp[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++)
		{
			dis[i]=len[i]=0;
			mp[i].clear();
		}
	}
	void add_edge(int a,int b,type w=1){mp[a].push_back({b,w});}
	void dfs(int x,int pre,int h)
	{
		int i;
		path[++tot]=x;
		first[x]=tot;
		deep[tot]=h;
		for(i=0;i<mp[x].size();i++)
		{
			int to=mp[x][i].to;
			if(to==pre) continue;
			dis[to]=dis[x]+mp[x][i].w;
			len[to]=len[x]+1;
			dfs(to,x,h+1);
			path[++tot]=x;
			deep[tot]=h;
		}
	}
	void ST(int n)
	{
		int i,j,x,y;
		for(i=1;i<=n;i++) dp[i][0]=i;
		for(j=1;(1<<j)<=n;j++)
		{
			for(i=1;i+(1<<j)-1<=n;i++)
			{
				x=dp[i][j-1];
				y=dp[i+(1<<(j-1))][j-1];
				dp[i][j]=deep[x]<deep[y]?x:y;
			}
		}
	}
	int query(int l,int r)
	{
		int len,x,y;
		len=__lg(r-l+1); 
		x=dp[l][len];
		y=dp[r-(1<<len)+1][len];
		return deep[x]<deep[y]?x:y;
	}
	int lca(int x,int y)
	{
		int l,r,pos;
		l=first[x];
		r=first[y];
		if(l>r) swap(l,r);
		pos=query(l,r);
		return path[pos];
	} 
	type get_dis(int a,int b){return dis[a]+dis[b]-2*dis[lca(a,b)];}
	int get_len(int a,int b){return len[a]+len[b]-2*len[lca(a,b)];}
	void work(int rt)
	{
		tot=0;
		dfs(rt,0,0);
		ST(2*n-1);
	}
	int lca_root(int rt,int x,int y)
	{
		int fx,fy;
		fx=lca(x,rt);
		fy=lca(y,rt);
		if(fx==fy) return lca(x,y);
		else
		{
			if(get_len(fx,rt)<get_len(fy,rt)) return fx;
			else return fy;
		}
	}
	#undef type
}lca;
/*
O(n*log(n))-O(1)

lca.init(n);
lca.add_edge(a,b,w);
lca.work(rt);
*/
struct Tree_Diameter
{
	vector<int> *mp;
	int fa[MAX],rt,mx;
	void dfs(int x,int pre,int h)
	{
		fa[x]=pre;
		for(auto &to:mp[x])
		{
			if(to==pre) continue;
			dfs(to,x,h+1);
		}
		if(h>mx)
		{
			mx=h;
			rt=x;
		}
		else if(h==mx) rt=max(rt,x);
	}
	vector<int> get_tree_diameter(vector<int> *_mp)
	{
		mp=_mp;
		fa[0]=0;
		rt=1;
		mx=0;
		dfs(rt,0,0);
		mx=0;
		dfs(rt,0,0);
		vector<int> res;
		while(rt)
		{
			res.push_back(rt);
			rt=fa[rt];
		}
		return res;
	}
}td;
vector<int> mp[MAX];
int main()
{
	int n,i,a,b,da,db;
	scanf("%d",&n);
	lca.init(n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
		lca.add_edge(a,b);
		lca.add_edge(b,a);
	}
	lca.work(1);
	auto res=td.get_tree_diameter(mp);
	a=res[0];
	b=res.back();
	for(i=1;i<=n;i++)
	{
		da=lca.get_len(i,a);
		db=lca.get_len(i,b);
		if(da>db) printf("%d\n",a);
		else if(da<db) printf("%d\n",b);
		else printf("%d\n",max(a,b));
	}
	return 0;
}
