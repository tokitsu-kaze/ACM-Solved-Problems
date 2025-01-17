#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int dis[22][22],head[22],tail[22][22],dp[(1<<20)+10][22];
int main()
{
	int n,q,s,i,j,x,ans;
	char op[2];
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++)
	{
		head[i]=1;
		dis[i][i]=0;
		for(j=0;j<n;j++)
		{
			if(i==j) continue;
			dis[i][j]=1;
			tail[i][j]=2;
		}
	}
	for(i=1;i<=q;i++)
	{
		scanf("%d%s",&x,op);
		x--;
		if(op[0]=='+') head[x]++;
		for(j=0;j<n;j++)
		{
			if(j==x) continue;
			if(op[0]=='+')
			{
				if(head[x]==tail[x][j])
				{
					dis[x][j]++;
					tail[x][j]++;
				}
			}
			else tail[j][x]++;
		}
	}
	memset(dp,0x3f,sizeof dp);
	for(i=0;i<n;i++) dp[1<<i][i]=1;
	for(s=0;s<(1<<n);s++)
	{
		for(i=0;i<n;i++)
		{
			if(!((s>>i)&1)) continue;
			for(j=0;j<n;j++)
			{
				if(!((s>>j)&1)) continue;
				dp[s][j]=min(dp[s][j],dp[s^(1<<j)][i]+dis[i][j]);
			}
		}
	}
	ans=INF;
	for(i=0;i<n;i++) ans=min(ans,dp[(1<<n)-1][i]+head[i]-1);
	printf("%d\n",ans);
	return 0;
}
