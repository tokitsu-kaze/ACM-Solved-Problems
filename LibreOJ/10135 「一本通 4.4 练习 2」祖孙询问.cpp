#include<bits/stdc++.h>
using namespace std;
const int MAX=4e4+10;
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
/*
O(nlogn)-O(logn)
lca.work(n,root,mp);
*/
vector<int> mp[MAX];
int main()
{
	int n,q,i,a,b,rt,lc;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		if(b==-1)
		{
			rt=a;
			continue;
		}
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	lca.work(n,rt,mp);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&a,&b);
		lc=lca.lca(a,b);
		if(lc==a) puts("1");
		else if(lc==b) puts("2");
		else puts("0");
	}
	return 0;
}
