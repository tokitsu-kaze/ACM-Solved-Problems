#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
const int mod=1e9+7;
struct Disjoint_Set_Union
{
	int pre[MAX],sz[MAX];
	ll dp[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
			sz[i]=1;
			dp[i]=1;
		}
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int x,int y,bool dir=false)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(!dir && sz[x]>sz[y]) swap(x,y);
		pre[x]=y; // x -> y
		sz[y]+=sz[x];
		dp[y]=dp[y]*dp[x]%mod;
		return 1;
	}
}dsu;
char mp[1010][1010];
int id[1010][1010],vis[MAX],del[MAX];
int main()
{
	int n,m,i,j,tot,x;
	ll ans;
	scanf("%d%d",&n,&m);
	tot=0;
	for(i=1;i<=n;i++)
	{
		scanf("%s",mp[i]+1);
		for(j=1;j<=m;j++) id[i][j]=++tot;
	}
	dsu.init(n*m);
	memset(vis,0,sizeof vis);
	for(i=n;i;i--)
	{
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]=='#') continue;
			if(i<n && mp[i+1][j]=='.') dsu.merge(id[i+1][j],id[i][j]);
			if(j>1 && mp[i][j-1]=='.') dsu.merge(id[i][j-1],id[i][j]);
		}
		tot=0;
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]=='#') continue;
			x=dsu.find(id[i][j]);
			if(!vis[x])
			{
				vis[x]=1;
				del[tot++]=x;
				dsu.dp[x]++;
			}
		}
		for(j=0;j<tot;j++) vis[del[j]]=0;
	}
	ans=1;
	for(i=1;i<=n*m;i++)
	{
		if(dsu.find(i)==i) ans=ans*dsu.dp[i]%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
显然从下往上做并查集。
如果当前层不选，方案数为dp值乘积。
如果选，方案数为1。
所以在并查集过程中维护dp值，再单独算一下选的。
*/
