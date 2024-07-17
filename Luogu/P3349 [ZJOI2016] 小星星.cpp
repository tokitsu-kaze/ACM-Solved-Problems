#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int g[22][22],t[22][22],n;
ll dp[22][22];
void dfs(int x,int fa,int s)
{
	int i,j,to;
	ll tmp;
	for(i=1;i<=n;i++) dp[x][i]=(s>>(i-1))&1;
	for(to=1;to<=n;to++)
	{
		if(to==fa) continue;
		if(!t[x][to]) continue;
		dfs(to,x,s);
		for(i=1;i<=n;i++)
		{
			if(!((s>>(i-1))&1)) continue;
			tmp=0;
			for(j=1;j<=n;j++)
			{
				if(!g[i][j]) continue;
				if(!((s>>(j-1))&1)) continue;
				tmp+=dp[to][j];
			}
			dp[x][i]*=tmp;
		}
	}
}
int main()
{
	int m,i,a,b,s;
	ll ans,tmp;
	scanf("%d%d",&n,&m);
	memset(g,0,sizeof g);
	memset(t,0,sizeof t);
	while(m--)
	{
		scanf("%d%d",&a,&b);
		g[a][b]=g[b][a]=1;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		t[a][b]=t[b][a]=1;
	}
	ans=0;
	for(s=1;s<(1<<n);s++)
	{
		memset(dp,0,sizeof dp);
		dfs(1,0,s);
		tmp=0;
		for(i=1;i<=n;i++) tmp+=dp[1][i];
		if((n-__builtin_popcount(s))&1) ans-=tmp;
		else ans+=tmp;
	}
	printf("%lld\n",ans);
	return 0;
}
