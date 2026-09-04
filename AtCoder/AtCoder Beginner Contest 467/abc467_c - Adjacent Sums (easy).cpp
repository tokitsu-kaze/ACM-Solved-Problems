#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX],dp[MAX][2];
int main()
{
	int n,m,i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<n;i++)
	{
		scanf("%d",&b[i]);
		a[i]+=a[i+1]-b[i]+m;
		a[i]%=m;
	}
	dp[1][0]=a[1];
	dp[1][1]=!a[1];
	for(i=2;i<n;i++)
	{
		if(a[i])
		{
			dp[i][0]=dp[i-1][1]+1;
			dp[i][1]=dp[i-1][0];
		}
		else
		{
			dp[i][1]=dp[i-1][1]+1;
			dp[i][0]=dp[i-1][0];
		}
	}
	dp[n-1][0]=min(dp[n-1][0],dp[n-1][1]+1);
	printf("%d\n",dp[n-1][0]);
	return 0;
}
