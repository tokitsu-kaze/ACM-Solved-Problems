#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=400+10;
ll dp[MAX][MAX],bit[MAX];
int a[MAX];
int main()
{
	int n,len,l,r,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(dp,0x3f,sizeof dp);
	bit[0]=0;
	for(i=1;i<=n;i++)
	{
		bit[i]=bit[i-1]+a[i];
		dp[i][i]=0;
	}
	for(len=2;len<=n;len++)
	{
		for(l=1;l+len-1<=n;l++)
		{
			r=l+len-1;
			for(i=l+1;i<=r;i++)
			{
				dp[l][r]=min(dp[l][r],dp[l][i-1]+dp[i][r]+bit[r]-bit[l-1]);
			}
		}
	}
	printf("%lld\n",dp[1][n]);
	return 0;
}
