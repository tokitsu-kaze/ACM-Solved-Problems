#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
int a[MAX];
ll dp[MAX][MAX];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	memset(dp,-0x3f,sizeof dp);
	dp[0][0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		dp[i][0]=0;
		for(j=1;j<=i;j++)
		{
			if(dp[i-1][j-1]<0) continue;
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+a[i]);
//			printf("%d %d %d\n",i,j,dp[i][j]);
		}
	}
	for(i=n;~i;i--)
	{
		if(dp[n][i]>=0)
		{
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
