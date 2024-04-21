#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
int mp[22][22],dp[22][22][22][22];
int cal(int x1,int x2,int y1,int y2)
{
	int i,j,cnt;
	cnt=0;
	for(i=x1;i<=x2;i++)
	{
		for(j=y1;j<=y2;j++)
		{
			cnt+=mp[i][j];
		}
	}
	return cnt;
}
int dfs(int x1,int x2,int y1,int y2)
{
	if(dp[x1][x2][y1][y2]!=-1) return dp[x1][x2][y1][y2];
	int i,cnt,res;
	cnt=cal(x1,x2,y1,y2);
	if(cnt==0) return dp[x1][x2][y1][y2]=INF;
	else if(cnt==1) return dp[x1][x2][y1][y2]=0;
	res=INF;
	for(i=x1;i<x2;i++) res=min(res,dfs(x1,i,y1,y2)+dfs(i+1,x2,y1,y2)+y2-y1+1);
	for(i=y1;i<y2;i++) res=min(res,dfs(x1,x2,y1,i)+dfs(x1,x2,i+1,y2)+x2-x1+1);
	return dp[x1][x2][y1][y2]=res;
}
int main()
{
	int n,m,k,x,y,cas;
	cas=1;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		memset(mp,0,sizeof mp);
		while(k--)
		{
			scanf("%d%d",&x,&y);
			mp[x][y]=1;
		}
		memset(dp,-1,sizeof dp);
		printf("Case %d: %d\n",cas++,dfs(1,n,1,m));
	}
	return 0;
}
