#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
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
			if(!dfn[to]) // dfn must be cleared
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
			col[i]=sz[i]=flag[i]=dfn[i]=0;
			mp[i].assign(_mp[i].begin(),_mp[i].end());
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
/*
scc.work(n,mp);
*/
vector<int> mp[MAX];
int dp[MAX],v[MAX],s[MAX],cnt[MAX],mod;
void dfs(int x)
{
	int pre;
	if(dp[x]!=-1) return;
	dp[x]=s[x];
	cnt[x]=1;
	sort(mp[x].begin(),mp[x].end());
	pre=-1;
	for(auto &to:mp[x])
	{
		if(to==pre) continue;
		pre=to;
		dfs(to);
		if(dp[x]<dp[to]+s[x])
		{
			dp[x]=dp[to]+s[x];
			cnt[x]=cnt[to];
		}
		else if(dp[x]==dp[to]+s[x])
		{
			cnt[x]=(cnt[x]+cnt[to])%mod;
		}
	}
}
int main()
{
	int n,m,i,a,b,ans,anscnt;
	scanf("%d%d%d",&n,&m,&mod);
	for(i=1;i<=n;i++)
	{
		v[i]=1;
		mp[i].clear();
		s[i]=0;
		dp[i]=-1;
	}
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
	}
	scc.work(n,mp);
	for(i=1;i<=n;i++) s[scc.col[i]]+=v[i];
	scc.rebuild(n,mp);
	for(i=1;i<=scc.scc_cnt;i++) dfs(i);
	ans=0;
	anscnt=0;
	for(i=1;i<=scc.scc_cnt;i++)
	{
		if(ans<dp[i])
		{
			ans=dp[i];
			anscnt=cnt[i];
		}
		else if(ans==dp[i]) anscnt=(anscnt+cnt[i])%mod;
	}
	printf("%d\n%d\n",ans,anscnt);
}

