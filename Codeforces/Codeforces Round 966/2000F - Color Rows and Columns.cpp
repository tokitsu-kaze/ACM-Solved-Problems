#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1000+10;
int a[MAX],b[MAX],dp[MAX][105],f[205];
int main()
{
	int t,n,m,i,j,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
		memset(dp[0],0x3f,sizeof dp[0]);
		dp[0][0]=0;
		for(i=1;i<=n;i++)
		{
			memset(f,0x3f,sizeof f);
			for(j=0;j<=b[i];j++)
			{
				for(k=0;k<=a[i];k++)
				{
					f[j+k]=min(f[j+k],j*a[i]+k*b[i]-j*k);
				}
			}
			for(j=0;j<=m;j++)
			{
				dp[i][j]=dp[i-1][j];
				for(k=1;k<=a[i]+b[i] && j-k>=0;k++)
				{
					dp[i][j]=min(dp[i][j],dp[i-1][j-k]+f[k]);
				}
			}
		}
		if(dp[n][m]==INF) puts("-1");
		else printf("%d\n",dp[n][m]);
	}
	return 0;
}
