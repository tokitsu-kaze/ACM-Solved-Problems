#include <bits/stdc++.h>
using namespace std;
int mp[1010][1010],dp[1010][1010];
int main()
{
	int n,i,j,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			scanf("%d",&mp[i][j]);
		}
	}
	memset(dp,0,sizeof dp);
	for(i=n;i;i--)
	{
		for(j=1;j<=i;j++)
		{
			dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+mp[i][j];
		}
	}
	printf("%d\n",dp[1][1]);
	return 0;
}
