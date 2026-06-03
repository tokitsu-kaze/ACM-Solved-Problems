#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int h[MAX],dp[MAX];
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&h[i]);
	dp[1]=0;
	for(i=2;i<=n;i++)
	{
		dp[i]=dp[i-1]+abs(h[i-1]-h[i]);
		if(i>=3) dp[i]=min(dp[i],dp[i-2]+abs(h[i-2]-h[i]));
	}
	printf("%d\n",dp[n]);
	return 0;
}
