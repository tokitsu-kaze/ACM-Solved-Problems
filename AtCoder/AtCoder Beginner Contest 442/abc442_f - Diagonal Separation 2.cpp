#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
char mp[MAX][MAX];
int w[MAX][MAX],b[MAX][MAX],dp[MAX][MAX];
int main()
{
	int n,i,j,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	memset(w,0,sizeof w);
	for(j=1;j<=n;j++)
	{
		for(i=1;i<=n;i++)
		{
			w[i][j]=w[i-1][j]+(mp[i][j]=='#');
		}
	}
	memset(b,0,sizeof b);
	for(i=1;i<=n;i++)
	{
		for(j=n;j;j--)
		{
			b[i][j]=b[i][j+1]+(mp[i][j]=='.');
		}
	}
	memset(dp,0x3f,sizeof dp);
	dp[n][1]=0;
	for(i=n;i;i--)
	{
		for(j=1;j<=n;j++)
		{
			dp[i][j+1]=min(dp[i][j+1],dp[i][j]+w[i][j]);
			dp[i-1][j]=min(dp[i-1][j],dp[i][j]+b[i][j]);
		}
	}
	ans=INF;
	for(i=0;i<=n+1;i++) ans=min(ans,dp[i][n+1]);
	for(j=0;j<=n+1;j++) ans=min(ans,dp[0][j]);
	printf("%d\n",ans);
	return 0;
}
