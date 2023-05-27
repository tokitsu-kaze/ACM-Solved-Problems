#include <bits/stdc++.h>
using namespace std;
int dp[505][505];
int main()
{
	int n,i,j,len,l,r,a[305];
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(dp,0x3f,sizeof dp);
	for(i=1;i<=n;i++) dp[i][i]=1;
	for(len=2;len<=n;len++)
	{
		for(l=1;l+len-1<=n;l++)
		{
			r=l+len-1;
			if(a[l]==a[r]) dp[l][r]=min(dp[l+1][r],dp[l][r-1]);
			for(i=l+1;i<=r;i++)
			{
				dp[l][r]=min(dp[l][r],dp[l][i-1]+dp[i][r]);
			}
		}
	}
	printf("%d\n",dp[1][n]);
}
