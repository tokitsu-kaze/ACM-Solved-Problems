#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
const int mod=1e9+7;
bool vis[MAX][MAX][2];
int dp[MAX][MAX][2],n;
int dfs(int x,int k,int d,int f)
{
	if(k==0) return 0;
	if(x<1||x>n) return 1;
	if(vis[x][k][f]) return dp[x][k][f];
	vis[x][k][f]=1;
	dp[x][k][f]=(dfs(x+d,k,d,f)+dfs(x-d,k-1,-d,f^1))%mod;
	return dp[x][k][f];
}
int main()
{
	int T,k,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=k;j++)
			{
				memset(vis[i][j],0,sizeof vis[i][j]);
				memset(dp[i][j],0,sizeof dp[i][j]);
			}
		}
		printf("%d\n",dfs(1,k,1,1));
	}
	return 0;
}
