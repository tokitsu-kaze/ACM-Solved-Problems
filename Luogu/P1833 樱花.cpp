#include <bits/stdc++.h>
using namespace std;
const int MAX=1000+10;
int tot,v[10000*20],w[10000*20],dp[MAX];
int main()
{
	int n,W,i,j,k,vi,wi,mi,ans,h1,m1,h2,m2;
	scanf("%d:%d %d:%d %d",&h1,&m1,&h2,&m2,&n);
	W=(h2*60+m2)-(h1*60+m1);
	tot=0;
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&wi,&vi,&mi);
		if(mi==0)
		{
			for(j=wi;j<=W;j++)
			{
				dp[j]=max(dp[j],dp[j-wi]+vi);
			}
			continue;
		}
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

