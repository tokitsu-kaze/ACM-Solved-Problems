#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int s[8],c[8];
double dp[5001][1<<8],p[8];
int main()
{
	int n,x,i,j,k;
	double ans,now;
	scanf("%d%d",&n,&x);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%lf",&s[i],&c[i],&p[i]);
		p[i]/=100;
	}
	ans=0;
	for(k=0;k<=x;k++)
	{
		memset(dp[k],0,sizeof dp[k]);
		for(i=1;i<(1<<n);i++)
		{
			for(j=0;j<n;j++)
			{
				if(k-c[j]<0) continue;
				if(!((i>>j)&1)) continue;
				dp[k][i]=max(dp[k][i],(dp[k-c[j]][i^(1<<j)]+s[j])*p[j]
									  +dp[k-c[j]][i]*(1-p[j]));
			}
			ans=max(ans,dp[k][i]);
		}
	}
	printf("%.10f\n",ans);
	return 0;
}

