#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
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
	void work(int n,int root,vector<int> *_mp)
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
	int get_len(int a,int b){return dep[a]+dep[b]-2*dep[lca(a,b)];}
}lca;
/*
O(nlogn)-O(logn)
lca.work(n,root,mp);
*/
vector<int> mp[MAX];
int v[MAX],e[MAX],sumv[MAX],sume[MAX],x[MAX],y[MAX];
void dfs(int x,int fa)
{
	sumv[x]=sumv[fa]+v[x];
	sume[x]=sume[fa]+e[x];
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
	}
}
int main()
{
	int n,a,b,c,ca,cb,m,i;
	ll ans1,ans2;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		v[i]=e[i]=sumv[i]=sume[i]=0;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	lca.work(n,1,mp);
	scanf("%d",&m);
	map<pair<int,pair<int,int>>,int> cnt;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		c=lca.lca(a,b);
		if(a==c) ca=0;
		else ca=lca.go(a,lca.dep[a]-lca.dep[c]-1);
		if(b==c) cb=0;
		else cb=lca.go(b,lca.dep[b]-lca.dep[c]-1);
		if(ca>cb)
		{
			swap(ca,cb);
			swap(a,b);
		}
		if(ca && cb) cnt[{c,{ca,cb}}]++;
		v[c]++;
		if(ca) e[ca]++;
		if(cb) e[cb]++;
		x[i]=a;
		y[i]=b;
	}
	sumv[0]=sume[0]=0;
	dfs(1,0);
	ans1=ans2=0;
	for(i=1;i<=m;i++)
	{
		a=x[i];
		b=y[i];
		c=lca.lca(a,b);
		if(a==c) ca=0;
		else ca=lca.go(a,lca.dep[a]-lca.dep[c]-1);
		if(b==c) cb=0;
		else cb=lca.go(b,lca.dep[b]-lca.dep[c]-1);
		
		if(ca) ans1+=(sumv[a]-sumv[c])-(sume[a]-sume[ca]);
		if(cb) ans1+=(sumv[b]-sumv[c])-(sume[b]-sume[cb]);
		
		ans2+=v[c];
		if(ca) ans2-=e[ca];
		if(cb) ans2-=e[cb];
		if(ca && cb) ans2+=cnt[{c,{ca,cb}}];
		if(!ca && !cb) ans2-=1;
	}
	printf("%lld\n",ans1+ans2/2);
	return 0;
}
/*
容易发现交点一定是一条路径的 lca。
随便选个根，先处理所有路径：在 lca 处点权+1，在 lca 往儿子的边，边权+1。
枚举路径，考虑两种路径的形态：lca 是否为其中一个端点。
1. 如果当前枚举的路径的 lca 是端点，那么答案为 sum{点权}-sum{边权}；
2. 如果 lca 不是端点，则分成两条路径分开算，然后再处理其他路径与当前 lca 重合的情况。
最终答案是：ans+重合情况/2。
*/
