#include <bits/stdc++.h>
using namespace std;
const int mod=10000;
int dp[1005][1005],bit[1005];
int main()
{
	int n,k,i,j,l,r;
	scanf("%d%d",&n,&k);
	memset(dp,0,sizeof dp);
	memset(bit,0,sizeof bit);
	dp[1][0]=1;
	bit[0]=bit[1]=dp[1][0];
	for(j=1;j<=k;j++) bit[j]=(bit[j-1]+dp[1][j])%mod;
	for(i=2;i<=n;i++)
	{
		for(j=0;j<=k;j++)
		{
			/*
			for(k=0;k<i && j-k>=0;k++)
			{
				dp[i][j]=(dp[i][j]+dp[i-1][j-k])%mod;
			}
			*/
			l=j-min(i-1,j);
			r=j;
			dp[i][j]=bit[r];
			if(l>0) dp[i][j]=(dp[i][j]-bit[l-1]+mod)%mod;
		}
		bit[0]=dp[i][0];
		for(j=1;j<=k;j++) bit[j]=(bit[j-1]+dp[i][j])%mod;
	}
	printf("%d\n",dp[n][k]);
	return 0;
}
