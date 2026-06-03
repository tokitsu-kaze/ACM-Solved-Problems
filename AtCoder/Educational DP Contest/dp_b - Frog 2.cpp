#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int h[MAX],dp[MAX];
int main()
{
	int n,i,j,k;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&h[i]);
	dp[1]=0;
	for(i=2;i<=n;i++)
	{
		dp[i]=INF;
		for(j=1;j<=k;j++)
		{
			if(i-j<1) break;
			dp[i]=min(dp[i],dp[i-j]+abs(h[i-j]-h[i]));
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}
