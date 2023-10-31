#include <bits/stdc++.h>
using namespace std;
double x[22],y[22],dp[(1<<16)+10][17];
double sqr(double x){return x*x;}
int main()
{
	int n,s,i,j;
	double ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);
	x[0]=y[0]=0;
	n++;
	for(s=1;s<(1<<n);s++)
	{
		for(i=0;i<n;i++)
		{
			dp[s][i]=1e9;
		}
	}
	dp[1][0]=0;
	for(s=1;s<(1<<n);s++)
	{
		for(i=0;i<n;i++)
		{
			if(!((s>>i)&1)) continue;
			for(j=1;j<n;j++)
			{
				if((s>>j)&1) continue;
				dp[s|(1<<j)][j]=min(dp[s|(1<<j)][j],
				  dp[s][i]+sqrt(sqr(x[j]-x[i])+sqr(y[j]-y[i])));
			}
		}
	}
	ans=1e9;
	for(i=1;i<n;i++) ans=min(ans,dp[(1<<n)-1][i]);
	printf("%.2f\n",ans);
	return 0;
}
