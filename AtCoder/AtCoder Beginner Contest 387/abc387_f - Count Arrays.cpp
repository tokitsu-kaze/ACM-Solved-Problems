#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3000;
const int mod=998244353;
struct Strongly_Connected_Components
{
	int scc_cnt,tot;
	int low[MAX],dfn[MAX],col[MAX],sz[MAX];
	int st[MAX],top,flag[MAX];
	vector<int> *mp;
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
		mp=_mp;
		for(i=1;i<=n;i++) col[i]=sz[i]=flag[i]=0;
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
/*
scc.work(n,mp);
*/
vector<int> g[MAX],mp[MAX];
int a[MAX],in[MAX],dp[MAX][MAX],m,bit[MAX][MAX];
void dfs(int x,int fa)
{
	int i;
	for(i=1;i<=m;i++) dp[x][i]=1;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		for(i=1;i<=m;i++) dp[x][i]=(1LL*dp[x][i]*bit[to][i])%mod;
	}
	bit[x][0]=0;
	for(i=1;i<=m;i++) bit[x][i]=(bit[x][i-1]+dp[x][i])%mod;
}
int main()
{
	int n,i;
	ll ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		g[i].clear();
		mp[i].clear();
		scanf("%d",&a[i]);
		in[i]=0;
	}
	for(i=1;i<=n;i++) g[a[i]].push_back(i);
	scc.work(n,g);
	scc.rebuild(n,mp);
	n=scc.scc_cnt;
	for(i=1;i<=n;i++)
	{
		for(auto &to:mp[i]) in[to]++;
	}
	ans=1;
	for(i=1;i<=n;i++)
	{
		if(in[i]) continue;
		dfs(i,0);
		ans=ans*bit[i][m]%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
