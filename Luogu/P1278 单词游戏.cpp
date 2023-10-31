#include <bits/stdc++.h>
using namespace std;
char t[18][105];
int len[18],dp[(1<<16)+10][18];
int main()
{
	int n,s,i,j,ans;
	scanf("%d",&n);
	memset(dp,0,sizeof dp);
	for(i=0;i<n;i++)
	{
		scanf("%s",t[i]+1);
		len[i]=strlen(t[i]+1);
		dp[1<<i][i]=len[i];
	}
	ans=0;
	for(s=0;s<(1<<n);s++)
	{
		for(i=0;i<n;i++)
		{
			if(!((s>>i)&1)) continue;
			for(j=0;j<n;j++)
			{
				if((s>>j)&1) continue;
				if(t[i][len[i]]!=t[j][1]) continue;
				dp[s|(1<<j)][j]=max(dp[s|(1<<j)][j],
					dp[s][i]+len[j]);
			}
		}
		for(i=0;i<n;i++) ans=max(ans,dp[s][i]);
	}
	printf("%d\n",ans);
	return 0;
}
