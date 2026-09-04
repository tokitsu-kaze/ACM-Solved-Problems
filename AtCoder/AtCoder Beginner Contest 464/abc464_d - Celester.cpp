#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int x[MAX],y[MAX];
ll dp[MAX][2];
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for(i=1;i<=n;i++) scanf("%d",&x[i]);
		for(i=1;i<n;i++) scanf("%d",&y[i]);
		dp[1][0]=-(s[1]!='S')*x[1];
		dp[1][1]=-(s[1]!='R')*x[1];
		for(i=2;i<=n;i++)
		{
			dp[i][0]=dp[i-1][1]-(s[i]!='S')*x[i]+y[i-1];
			dp[i][0]=max(dp[i][0],dp[i-1][0]-(s[i]!='S')*x[i]);
			dp[i][1]=max(dp[i-1][0],dp[i-1][1])-(s[i]!='R')*x[i];
		}
		printf("%lld\n",max(dp[n][0],dp[n][1]));
	}
	return 0;
}
