#include <bits/stdc++.h>
using namespace std;
int dp[2002][2002];
char a[2002],b[2002];
int main()
{
	int n,m,i,j;
	scanf("%s",a+1);
	scanf("%s",b+1);
	n=strlen(a+1);
	m=strlen(b+1);
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++) dp[i][0]=i;
	for(i=1;i<=m;i++) dp[0][i]=i;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1];
			else dp[i][j]=min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]})+1;
		}
	}
	printf("%d\n",dp[n][m]);
	return 0;
}
