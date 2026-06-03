#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=500+10;
int dp[MAX][MAX],a[MAX];
int main()
{
	int n,i,len,l,r,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++) dp[i][i]=a[i];
	for(len=2;len<=n;len++)
	{
		for(l=1;l+len-1<=n;l++)
		{
			r=l+len-1;
			for(i=l;i<r;i++)
			{
				if(!dp[l][i]) continue;
				if(!dp[i+1][r]) continue;
				if(dp[l][i]==dp[i+1][r])
				{
					dp[l][r]=dp[l][i]+1;
					break;
				}
			}
		}
	}
	ans=0;
	for(l=1;l<=n;l++)
	{
		for(r=l;r<=n;r++)
		{
			ans=max(ans,dp[l][r]);
		}
	}
	printf("%d\n",ans);
	return 0;
}

