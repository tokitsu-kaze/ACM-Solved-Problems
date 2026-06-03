#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
int dp[MAX][MAX],a[MAX];
int main()
{
	int n,i,j,l,r,len;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(dp,0,sizeof dp);
	for(len=3;len<=n;len++)
	{
		for(l=1;l+len-1<=n;l++)
		{
			r=l+len-1;
			for(i=l;i<r;i++) dp[l][r]=max(dp[l][r],dp[l][i]+dp[i+1][r]);
			if((r-l+1)%3) continue;
			for(i=l+1;i<r;i++)
			{
				if((i-l-1)%3) continue;
				if((r-i-1)%3) continue;
				dp[l][r]=max(dp[l][r],a[l]+a[i]+a[r]
					+dp[l+1][i-1]+dp[i+1][r-1]);
			}
		}
	}
	printf("%d\n",dp[1][n]);
	return 0;
}
/*
发现有硬币的格子可以任意移动，只要中间间隔是3的倍数。
考虑区间dp。
*/
