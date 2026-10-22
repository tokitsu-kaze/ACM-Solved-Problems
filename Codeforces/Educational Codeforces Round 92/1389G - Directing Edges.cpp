#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
struct Edge_Biconnected_Component
{
	int bcc_cnt,tot;
	int low[MAX],dfn[MAX];
	int st[MAX],top,col[MAX];
	vector<int> mp[MAX];
	vector<pair<int,int>> bridge;
	void dfs(int x,int fa)
	{
		int i,tmp,k;
		st[top++]=x;
		low[x]=dfn[x]=++tot;
		k=0;
		for(auto &to:mp[x])
		{
			if(to==fa&&!k) 
			{
				k++;
				continue;
			}
			if(!dfn[to])
			{
				dfs(to,x);
				low[x]=min(low[x],low[to]);
				if(low[to]>dfn[x]) bridge.push_back({x,to});
			}
			else low[x]=min(low[x],dfn[to]);
		}
		if(low[x]==dfn[x])
		{
			bcc_cnt++;
			do
			{
				tmp=st[--top];
				col[tmp]=bcc_cnt;
			}while(tmp!=x);
		}
	}
	void work(int n,vector<int> *_mp)
	{
		int i;
		for(i=1;i<=n;i++) 
		{
			low[i]=dfn[i]=col[i]=0;
			mp[i].assign(_mp[i].begin(),_mp[i].end());
		}
		bcc_cnt=top=tot=0;
		bridge.clear();
		for(i=1;i<=n;i++)
		{
			if(!dfn[i]) dfs(i,i);
		}
	}
}bcc;
/*
bcc.work(n,mp);
*/
struct node{int to,w;};
vector<node> g[MAX];
vector<int> mp[MAX];
int tag[MAX],c[MAX],w[MAX],a[MAX],b[MAX],k;
int sz[MAX],tagcnt[MAX];
ll v[MAX],dp[MAX],ans[MAX];
void dfs0(int x,int fa)
{
	int to,cost;
	dp[x]=v[x];
	sz[x]=tagcnt[x];
	for(auto &it:g[x])
	{
		to=it.to;
		if(to==fa) continue;
		dfs0(to,x);
		sz[x]+=sz[to];
		if(sz[to]==0 || sz[to]==k) cost=0;
		else cost=it.w;
		dp[x]+=max(0LL,dp[to]-cost);
	}
}
void dfs(int x,int fa)
{
	int to,cost;
	ans[x]=dp[x];
	for(auto &it:g[x])
	{
		to=it.to;
		if(to==fa) continue;
		
		if(sz[to]==0 || sz[to]==k) cost=0;
		else cost=it.w;
		dp[x]-=max(0LL,dp[to]-cost);
		sz[x]-=sz[to];
		
		if(sz[x]==0 || sz[x]==k) cost=0;
		else cost=it.w;
		dp[to]+=max(0LL,dp[x]-cost);
		sz[to]+=sz[x];
		
		dfs(to,x);
		
		if(sz[x]==0 || sz[x]==k) cost=0;
		else cost=it.w;
		dp[to]-=max(0LL,dp[x]-cost);
		sz[to]-=sz[x];
		
		if(sz[to]==0 || sz[to]==k) cost=0;
		else cost=it.w;
		dp[x]+=max(0LL,dp[to]-cost);
		sz[x]+=sz[to];
	}
}
int main()
{
	int n,m,i,x;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		g[i].clear();
		v[i]=tagcnt[i]=tag[i]=0;
	}
	for(i=1;i<=k;i++)
	{
		scanf("%d",&x);
		tag[x]=1;
	}
	for(i=1;i<=n;i++) scanf("%d",&c[i]);
	for(i=1;i<=m;i++) scanf("%d",&w[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		mp[a[i]].push_back(b[i]);
		mp[b[i]].push_back(a[i]);
	}
	bcc.work(n,mp);
	for(i=1;i<=m;i++)
	{
		if(bcc.col[a[i]]==bcc.col[b[i]]) continue;
		g[bcc.col[a[i]]].push_back({bcc.col[b[i]],w[i]});
		g[bcc.col[b[i]]].push_back({bcc.col[a[i]],w[i]});
	}
	for(i=1;i<=n;i++)
	{
		v[bcc.col[i]]+=c[i];
		tagcnt[bcc.col[i]]+=tag[i];
	}
	dfs0(1,0);
	dfs(1,0);
	for(i=1;i<=n;i++) printf("%lld%c",ans[bcc.col[i]]," \n"[i==n]);
	return 0;
}
/*
有向边是没有代价的，所以考虑强连通缩点，缩点后这个点是没有代价的。
重新建图后是树，换根dp即可。

现在的问题是，原图是个无向图，应该要跑双连通，跑点双还是边双呢？
似乎有个定理：罗宾斯定理，说明了：
如果能够给一个无向图的边定向后，变成一个强连通图，那么原无向图是个边双。
所以跑边双缩点即可。
*/
