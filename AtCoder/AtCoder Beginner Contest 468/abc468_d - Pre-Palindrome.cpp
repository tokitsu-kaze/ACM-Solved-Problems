#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e4+10;
char s[MAX];
int dp[MAX][MAX][2];
int main()
{
	int n,i,len,l,r,ans;
	scanf("%s",s+1);
	n=strlen(s+1);
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++) dp[i][i][0]=1;
	for(i=1;i<n;i++)
	{
		if(s[i]==s[i+1]) dp[i][i+1][0]=1;
		else dp[i][i+1][1]=1;
	}
	for(len=3;len<=n;len++)
	{
		for(l=1;l+len-1<=n;l++)
		{
			r=l+len-1;
			if(s[l]==s[r])
			{
				dp[l][r][0]+=dp[l+1][r-1][0];
				dp[l][r][1]+=dp[l+1][r-1][1];
			}
			else dp[l][r][1]+=dp[l+1][r-1][0];
		}
	}
	ans=0;
	for(l=1;l<=n;l++)
	{
		for(r=l;r<=n;r++)
		{
			ans+=dp[l][r][0]+dp[l][r][1];
		}
	}
	printf("%d\n",ans);
	return 0;
}
