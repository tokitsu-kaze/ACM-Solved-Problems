#include <bits/stdc++.h>
using namespace std;
const int MAX=105;
struct Strongly_Connected_Components
{
	int scc_cnt,tot;
	int low[MAX],dfn[MAX],col[MAX],sz[MAX];
	int st[MAX],top,flag[MAX];
	vector<int> mp[MAX];
	void dfs(int x)
	{
		int tmp;
		st[top++]=x;
		flag[x]=1;
		low[x]=dfn[x]=++tot;
		for(auto &to:mp[x])
		{
			if(!dfn[to])
			{
				dfs(to);
				low[x]=min(low[x],low[to]);
			}
			else if(flag[to]) low[x]=min(low[x],dfn[to]);
		}
		if(low[x]==dfn[x])
		{
			scc_cnt++;
			do
			{
				tmp=st[--top];
				flag[tmp]=0;
				col[tmp]=scc_cnt;
				sz[scc_cnt]++;
			}while(tmp!=x);
		}
	}
	void work(int n,vector<int> *_mp)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			col[i]=sz[i]=flag[i]=0;
			mp[i]=_mp[i];
		}
		scc_cnt=top=tot=0;
		for(i=1;i<=n;i++)
		{
			if(col[i]) continue;
			dfs(i);
		}
	}
	void rebuild(int n,vector<int> *g)
	{
		int i;
		for(i=1;i<=n;i++) g[i].clear();
		for(i=1;i<=n;i++)
		{
			for(auto &to:mp[i])
			{
				if(col[i]==col[to]) continue;
				g[col[i]].push_back(col[to]);
			}
		}
	}
}scc;
int n,m,ww[MAX],vv[MAX];
int w[MAX],v[MAX],dp[MAX][505],in[MAX];
vector<int> mp[MAX];
void dfs(int x)
{
	int i,j;
	for(i=m;i>=w[x];i--) dp[x][i]=v[x];
	for(auto &to:mp[x])
	{
		dfs(to);
		for(i=m;i>=w[x];i--)
		{
			for(j=0;j<=i-w[x];j++)
			{
				dp[x][i]=max(dp[x][i],dp[x][i-j]+dp[to][j]);
			}
		}
	}
}
int main()
{
	int i,fa;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n+1;i++)
	{
		mp[i].clear();
		w[i]=v[i]=in[i]=0;
		memset(dp[i],0,sizeof dp[i]);
	}
	for(i=1;i<=n;i++) scanf("%d",&ww[i]);
	for(i=1;i<=n;i++) scanf("%d",&vv[i]);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&fa);
		if(fa) mp[fa].push_back(i);
	}
	scc.work(n,mp);
	for(i=1;i<=n;i++)
	{
		w[scc.col[i]]+=ww[i];
		v[scc.col[i]]+=vv[i];
	}
	scc.rebuild(n,mp);
	n=scc.scc_cnt;
	for(i=1;i<=n;i++)
	{
		for(auto &to:mp[i]) in[to]++;
	}
	for(i=1;i<=n;i++)
	{
		if(!in[i]) mp[n+1].push_back(i);
	}
	v[n+1]=w[n+1]=0;
	dfs(n+1);
	printf("%d\n",dp[n+1][m]);
	return 0;
}
/*
7 401
2 2 2 2 2 2 2
1 2 4 8 16 32 64
2 1 1 1 6 5 3
*/
