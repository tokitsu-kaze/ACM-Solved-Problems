#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int dp[MAX],lst[33];
int main()
{
	int n,i,j,x,ans;
	scanf("%d",&n);
	memset(lst,0,sizeof lst);
	memset(dp,0,sizeof dp);
	ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for(j=0;j<30;j++)
		{
			if(!((x>>j)&1)) continue;
			dp[i]=max(dp[i],dp[lst[j]]+1);
			lst[j]=i;
		}
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}
