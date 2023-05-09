#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
char s[1005];
int main()
{
	int l,r,len,i,n;
	scanf("%s",s+1);
	n=strlen(s+1);
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++) dp[i][i]=1;
	for(len=2;len<=n;len++)
	{
		for(l=1;l+len-1<=n;l++)
		{
			r=l+len-1;
			if(s[l]==s[r]) dp[l][r]=dp[l+1][r-1]+2;
			else dp[l][r]=max(dp[l+1][r],dp[l][r-1]);
		}
	}
	printf("%d\n",n-dp[1][n]);
	return 0;
}
