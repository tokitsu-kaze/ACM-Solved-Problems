#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2000+10;
int dp[3*MAX][6*MAX];
const int delta=6001;
int main()
{
	int n,mod,i,j,ans;
	scanf("%d%d",&n,&mod);
	memset(dp,0,sizeof dp);
	dp[0][delta]=1;
	for(i=1;i<=3*n;i++)
	{
		for(j=-i+delta;j<=i+delta;j++)
		{
			dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
			if(i>=2) dp[i][j]=(dp[i][j]+1LL*dp[i-2][j+1]*(i-1))%mod;
			if(i>=3) dp[i][j]=(dp[i][j]+1LL*dp[i-3][j]*(i-1)%mod*(i-2))%mod;
		}
	}
	ans=0;
	for(i=0;i<=3*n;i++) ans=(ans+dp[3*n][i+delta])%mod;
	printf("%d\n",ans);
	return 0;
}
