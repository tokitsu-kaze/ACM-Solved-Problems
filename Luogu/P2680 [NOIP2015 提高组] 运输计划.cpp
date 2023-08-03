#include <bits/stdc++.h>
using namespace std;
const int MAX=3e5+10;
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
struct node{int x,y;};
vector<node> mp1[MAX];
vector<int> mp[MAX];
int v[MAX],dis[MAX];
void dfs1(int x,int fa)
{
	for(auto &to:mp1[x])
	{
		if(to.x==fa) continue;
		v[to.x]=to.y;
		dis[to.x]=dis[x]+to.y;
		dfs1(to.x,x);
	}
}
int get_dis(int a,int b)
{
	return dis[a]+dis[b]-2*dis[lca.lca(a,b)];
}
int tag[MAX];
vector<node> qst;
void dfs(int x,int fa)
{
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		tag[x]+=tag[to];
	}
}
int n,m,disq[MAX],lc[MAX];
int ck(int x)
{
	int i,cnt,res;
	for(i=1;i<=n;i++) tag[i]=0;
	cnt=0;
	for(i=0;i<m;i++)
	{
		if(disq[i]>x)
		{
			cnt++;
			tag[lc[i]]-=2;
			tag[qst[i].x]++;
			tag[qst[i].y]++;
		}
	}
	dfs(1,0);
	res=0;
	for(i=1;i<=n;i++)
	{
		if(tag[i]==cnt) res=max(res,v[i]);
	}
	for(i=0;i<m;i++)
	{
		if(disq[i]-res>x) return 0;
	}
	return 1;
}
int main()
{
	int i,a,b,c,l,r,mid;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		mp1[i].clear();
		v[i]=dis[i]=0;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		mp1[a].push_back({b,c});
		mp1[b].push_back({a,c});
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	dfs1(1,0);
	lca.work(n,1,mp);
	qst.clear();
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		qst.push_back({a,b});
		disq[i]=get_dis(a,b);
		lc[i]=lca.lca(a,b);
//		printf("%d %d %d\n",a,b,get_dis(a,b));
	}
	l=0;
	r=n*1000;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}
