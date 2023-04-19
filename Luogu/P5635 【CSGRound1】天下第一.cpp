#include <bits/stdc++.h>
using namespace std;
const int MAX=1e4+10;
int mod;
char dp[MAX][MAX][2];
char dfs(int x,int y,int z)
{
	if(dp[x][y][z]) return dp[x][y][z];
	if(x==0) return 1;
	if(y==0) return 2;
	dp[x][y][z]=3;
	if(z==1) dp[x][y][z]=dfs((x+y)%mod,y,0);
	else dp[x][y][z]=dfs(x,(x+y)%mod,1);
	return dp[x][y][z];
}
int main()
{
	int t,x,y;
	scanf("%d%d",&t,&mod);
	memset(dp,0,sizeof dp);
	while(t--)
	{
		scanf("%d%d",&x,&y);
		int res=dfs(x,y,1);
		if(res==3) puts("error");
		else printf("%d\n",res);
	}
	return 0;
}
