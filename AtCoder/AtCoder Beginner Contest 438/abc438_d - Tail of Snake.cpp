#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int a[MAX],b[MAX],c[MAX];
ll dp[MAX][3];
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) scanf("%d",&b[i]);
	for(i=1;i<=n;i++) scanf("%d",&c[i]);
	dp[0][0]=0;
	dp[0][1]=dp[0][2]=-LLINF;
	for(i=1;i<=n;i++)
	{
		dp[i][0]=dp[i-1][0]+a[i];
		if(i>=2) dp[i][1]=max(dp[i-1][0],dp[i-1][1])+b[i];
		else dp[i][1]=-LLINF;
		if(i>=3) dp[i][2]=max(dp[i-1][1],dp[i-1][2])+c[i];
		else dp[i][2]=-LLINF;
	}
	printf("%lld\n",dp[n][2]);
	return 0;
}
