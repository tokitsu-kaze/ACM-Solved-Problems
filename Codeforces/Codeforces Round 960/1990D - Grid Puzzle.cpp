#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],dp[MAX][3];
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			memset(dp[i],0x3f,sizeof dp[i]);
		}
		dp[0][0]=0;
		for(i=1;i<=n;i++)
		{
			dp[i][0]=dp[i-1][0]+(a[i]!=0);
			if(a[i]>4 || a[i]==0) continue;
			if(a[i]<=2)
			{
				dp[i][0]=min(dp[i][0],dp[i-1][1]+1);
				dp[i][1]=dp[i-1][0];
			}
			else // 2<a[i]<=4
			{
				dp[i][1]=dp[i-1][2]+1;
				dp[i][2]=dp[i-1][1]+1;
			}
		}
		printf("%d\n",dp[n][0]);
	}
	return 0;
}

