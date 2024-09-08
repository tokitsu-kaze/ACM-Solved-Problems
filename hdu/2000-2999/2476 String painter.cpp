#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
char a[105],b[105];
int dp[105][105],ans[105];
int main()
{
	int n,i,j,l,r,len;
	while(~scanf("%s",a+1))
	{
		scanf("%s",b+1);
		n=strlen(a+1);
		memset(dp,0x3f,sizeof dp);
		for(i=1;i<=n;i++) dp[i][i]=1;
		for(len=2;len<=n;len++)
		{
			for(l=1;l+len-1<=n;l++)
			{
				r=l+len-1;
				if(b[l]==b[r])
				{
					dp[l][r]=min(dp[l+1][r],dp[l][r-1]);
					continue;
				}
				// s[l]!=s[r]
				for(i=l+1;i<=r;i++)
				{
					dp[l][r]=min(dp[l][r],dp[l][i-1]+dp[i][r]);
				}
			}
		}
		ans[0]=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]==b[i])
			{
				ans[i]=ans[i-1];
				continue;
			}
			ans[i]=INF;
			for(j=0;j<i;j++) ans[i]=min(ans[i],ans[j]+dp[j+1][i]);
		}
		printf("%d\n",ans[n]);
	}
	return 0;
}
