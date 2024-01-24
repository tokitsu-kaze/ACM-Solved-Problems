#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const ll mod=1e9+7;
struct LCA
{
	static const int N=MAX;
	static const int LOGN=log2(N)+3;
	int fa[N][LOGN],dep[N],limt,bin[LOGN];
	void dfs(int x,int pre,vector<int> mp[])
	{
		int i;
		for(i=1;bin[i]<=dep[x];i++) fa[x][i]=fa[fa[x][i-1]][i-1];
		for(auto &to:mp[x])
		{
			if(to==pre) continue;
			dep[to]=dep[x]+1;
			fa[to][0]=x;
			dfs(to,x,mp);
		}
	}
	void work(int n,int root,vector<int> mp[])
	{
		int i;
		for(limt=1;(1<<(limt-1))<n;limt++);
		for(i=bin[0]=1;i<=limt;i++) bin[i]=(bin[i-1]<<1);
		for(i=0;i<=n;i++) memset(fa[i],0,sizeof fa[i]);
		dep[root]=0;
		dfs(root,-1,mp);
	}
	int go(int x,int d)
	{
		for(int i=0;i<=limt&&d;i++)
		{
			if(bin[i]&d)
			{
				d^=bin[i];
				x=fa[x][i];
			}
		}
		return x;
	}
	int lca(int x,int y)
	{
		if(dep[x]<dep[y]) swap(x,y);
		x=go(x,dep[x]-dep[y]);
		if(x==y) return x;
		for(int i=limt;~i;i--)
		{
			if(fa[x][i]!=fa[y][i])
			{
				x=fa[x][i];
				y=fa[y][i];
			}
		}
		return fa[x][0];
	}
}lca;
vector<int> mp[MAX];
int bit[MAX],mx;
void dfs(int x,int fa)
{
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		bit[x]+=bit[to];
	}
	mx=max(mx,bit[x]);
}
int main()
{
	int n,k,i,a,b;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		bit[i]=0;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	lca.work(n,1,mp);
	while(k--)
	{
		scanf("%d%d",&a,&b);
		bit[a]++;
		bit[b]++;
		bit[lca.lca(a,b)]--;
		bit[lca.fa[lca.lca(a,b)][0]]--;
	}
	mx=0;
	dfs(1,0);
	printf("%d\n",mx);
	return 0;
}
