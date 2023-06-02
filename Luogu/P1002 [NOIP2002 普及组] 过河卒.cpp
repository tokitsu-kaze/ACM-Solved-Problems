#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dir[8][2]={-1,-2,-2,-1,-1,2,-2,1,1,-2,2,-1,1,2,2,1};
int flag[33][33];
ll dp[33][33];
int main()
{
	int n,m,x,y,i,j;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	n++;
	m++;
	x++;
	y++;
	memset(flag,0,sizeof flag);
	flag[x][y]=1;
	for(i=0;i<8;i++) flag[x+dir[i][0]][y+dir[i][1]]=1;
	memset(dp,0,sizeof dp);
	dp[1][1]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(i==1&&j==1) continue;
			if(flag[i][j]) continue;
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	printf("%lld\n",dp[n][m]);
	return 0;
}
