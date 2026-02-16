#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
int dp[MAX][MAX];
int main()
{
	int r,g,b,i,j,d;
	const int delta=500;
	scanf("%d%d%d",&r,&g,&b);
	memset(dp,0x3f,sizeof dp);
	dp[0][0]=0;
	for(d=-499;d<=500;d++)
	{
		i=d+delta;
		dp[i][0]=dp[i-1][0];
		for(j=1;j<=r+g+b;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(j<=r) dp[i][j]=min(dp[i][j],dp[i-1][j-1]+abs(-100-d));
			else if(j<=r+g) dp[i][j]=min(dp[i][j],dp[i-1][j-1]+abs(0-d));
			else dp[i][j]=min(dp[i][j],dp[i-1][j-1]+abs(100-d));
		}
	}
	printf("%d\n",dp[2*delta][r+g+b]);
	return 0;
}
