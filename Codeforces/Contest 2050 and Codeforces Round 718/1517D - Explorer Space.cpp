#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int mp[505][505][4],dp[12][505][505];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int main()
{
	int n,m,k,i,j,s,l,x,y;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<m;j++)
		{
			scanf("%d",&mp[i][j][1]);
			mp[i][j+1][0]=mp[i][j][1];
		}
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&mp[i][j][3]);
			mp[i+1][j][2]=mp[i][j][3];
		}
	}
	memset(dp,0x3f,sizeof dp);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			dp[0][i][j]=0;
		}
	}
	for(s=1;s<=k/2;s++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				for(l=0;l<4;l++)
				{
					x=i+dir[l][0];
					y=j+dir[l][1];
					if(x<1||y<1||x>n||y>m) continue;
					dp[s][i][j]=min(dp[s][i][j],dp[s-1][x][y]+mp[x][y][l]);
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(k&1) dp[k/2][i][j]=-1;
			else dp[k/2][i][j]*=2;
			printf("%d%c",dp[k/2][i][j]," \n"[j==m]);
		}
	}
	return 0;
}
