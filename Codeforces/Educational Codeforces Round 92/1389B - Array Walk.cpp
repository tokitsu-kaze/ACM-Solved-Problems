#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX],dp[6][MAX];
int main()
{
	int T,n,k,z,i,j,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&k,&z);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		dp[0][0]=0;
		ans=0;
		for(i=0;i<=z;i++)
		{
			for(j=1;j<=n;j++)
			{
				dp[i][j]=dp[i][j-1]+a[j];
				if(i>0 && j<n) dp[i][j]=max(dp[i][j],dp[i-1][j+1]+a[j]);
				if(i*2+j-1==k) ans=max(ans,dp[i][j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
