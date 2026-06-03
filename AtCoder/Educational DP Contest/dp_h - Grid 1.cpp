#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
const int mod=1e9+7;
int dp[MAX][MAX];
char mp[MAX][MAX];
int main()
{
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	memset(dp,0,sizeof dp);
	dp[1][1]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(i==1 && j==1) continue;
			if(mp[i][j]=='#') continue;
			dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
		}
	}
	printf("%d\n",dp[n][m]);
	return 0;
}
