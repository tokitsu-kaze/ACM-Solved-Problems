#include <bits/stdc++.h>
using namespace std;
const int MAX=4e4+10;
int tot,v[100*20],w[100*20],dp[MAX];
int main()
{
	int n,W,i,j,k,vi,wi,mi,ans;
	scanf("%d%d",&n,&W);
	tot=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&vi,&wi,&mi);
		for(j=0;(1<<j)<=mi;j++)
		{
			tot++;
			v[tot]=vi*(1<<j);
			w[tot]=wi*(1<<j);
			mi-=(1<<j);
		}
		if(mi>0)
		{
			tot++;
			v[tot]=vi*mi;
			w[tot]=wi*mi;
		}
	}
	memset(dp,0,sizeof dp);
	for(i=1;i<=tot;i++)
	{
		for(j=W;j>=w[i];j--)
		{
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	ans=0;
	for(i=0;i<=W;i++) ans=max(ans,dp[i]);
	printf("%d\n",ans);
	return 0;
}

