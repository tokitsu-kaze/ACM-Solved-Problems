#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e4+10;
const int M=1e5+10;
struct LCA
{
	static const int N=2*MAX;
	static const int LOG=log2(N)+2;
	int fa[LOG][N],dep[N];
	bool vis[N];
	vector<int> *mp;
	void dfs(int x,int pre)
	{
		int i;
		vis[x]=1;
		dep[x]=dep[pre]+1;
		fa[0][x]=pre;
		for(i=1;i<LOG;i++) fa[i][x]=fa[i-1][fa[i-1][x]];
		for(auto &to:mp[x])
		{
			if(to==pre) continue;
			dfs(to,x);
		}
	}
	void work(int n,vector<int> *_mp)
	{
		int i,j;
		mp=_mp;
		dep[0]=0;
		for(j=0;j<LOG;j++) fa[j][0]=0;
		for(i=1;i<=n;i++) vis[i]=0;
		for(i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			dfs(i,0);
		}
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
/*
O(nlogn)-O(logn)
lca.work(n,root,mp);
*/
struct Round_Square_Tree
{
	int tot,id,bcc_cnt;
	int low[MAX],dfn[MAX];
	int st[MAX],top;
	vector<int> *mp,*g;
	void dfs(int x,int fa)
	{
		int i,tmp,k;
		st[top++]=x;
		low[x]=dfn[x]=++tot;
		for(auto &to:mp[x])
		{
			if(!dfn[to])
			{
				dfs(to,x);
				low[x]=min(low[x],low[to]);
				if(low[to]==dfn[x])
				{
					id++;
					while(top)
					{
						tmp=st[--top];
						g[tmp].push_back(id);
						g[id].push_back(tmp);
						if(tmp==to) break;
					}
					g[x].push_back(id);
					g[id].push_back(x);
				}
			}
			else low[x]=min(low[x],dfn[to]);
		}
	}
	int build(int n,vector<int> *_mp,vector<int> *_g)
	{
		int i;
		mp=_mp;
		g=_g;
		for(i=0;i<=n;i++) low[i]=dfn[i]=0;
		for(i=0;i<=(n<<1);i++) g[i].clear();
		top=tot=0;
		id=n;
		for(i=1;i<=n;i++)
		{
			if(!dfn[i]) dfs(i,i);
		}
		bcc_cnt=id-n;
		return id;
	}
}rst;
/*
vector<int> mp[MAX],g[MAX<<1];
tot=rst.build(n,mp,g);
*/
vector<int> mp[MAX],g[MAX<<1];
int val[MAX<<1],fa[MAX<<1],n;
bool vis[MAX<<1];
void dfs(int x,int pre)
{
	vis[x]=1;
	if(x<=n) val[x]=1;
	else val[x]=0;
	val[x]+=val[pre];
	fa[x]=pre;
	for(auto &to:g[x])
	{
		if(to==pre) continue;
		dfs(to,x);
	}
}
int cal(int a,int b)
{
	int c=lca.lca(a,b);
	return val[a]+val[b]-val[c]-val[fa[c]]-2;
}
int x[M],y[M];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m,q,i,a,b;
	while(cin>>n>>m)
	{
		if(n==0 && m==0) break;
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<=m;i++)
		{
			cin>>a>>b;
			mp[a].push_back(b);
			mp[b].push_back(a);
			x[i]=a;
			y[i]=b;
		}
		rst.build(n,mp,g);
		lca.work(n,g);
		val[0]=0;
		for(i=1;i<=n;i++) vis[i]=0;
		for(i=1;i<=n;i++)
		{
			if(!vis[i]) dfs(i,0);
		}
		cin>>q;
		while(q--)
		{
			cin>>a>>b;
			cout<<max({cal(x[a],x[b]),cal(x[a],y[b]),
					  cal(y[a],x[b]),cal(y[a],y[b])})<<"\n";
		}
	}
	return 0;
}
