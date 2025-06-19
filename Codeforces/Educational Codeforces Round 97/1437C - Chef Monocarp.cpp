#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=200+10;
int a[MAX],dp[MAX][2*MAX];
int main()
{
	int T,n,i,j,k,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=2*n;j++)
			{
				if(i==0) dp[i][j]=0;
				else dp[i][j]=INF;
			}
		}
		dp[0][0]=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=2*n;j++)
			{
				for(k=j-1;k>=i-1;k--)
				{
					dp[i][j]=min(dp[i][j],dp[i-1][k]+abs(j-a[i]));
				}
			}
		}
		ans=INF;
		for(i=n;i<=2*n;i++) ans=min(ans,dp[n][i]);
		printf("%d\n",ans);
	}
	return 0;
}
