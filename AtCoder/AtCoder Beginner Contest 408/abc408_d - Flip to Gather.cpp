#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int dp[MAX][2][2];
char s[MAX];
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for(i=0;i<=n;i++) memset(dp[i],0,sizeof dp[i]);
		dp[0][0][0]=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='0')
			{
				dp[i][0][0]=dp[i-1][0][0];
				dp[i][1][0]=min(dp[i-1][1][0],dp[i-1][1][1]);
				dp[i][1][1]=min(dp[i-1][0][0],dp[i-1][1][1])+1;
			}
			else
			{
				dp[i][0][0]=dp[i-1][0][0]+1;
				dp[i][1][0]=dp[i-1][1][0]+1;
				dp[i][1][1]=min(dp[i-1][0][0],dp[i-1][1][1]);
			}
		}
		printf("%d\n",min({dp[n][0][0],dp[n][1][0],dp[n][1][1]}));
	}
	return 0;
}
