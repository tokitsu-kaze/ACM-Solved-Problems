#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=8000+10;
int a[MAX],c[MAX];
ll dp[2][MAX];
int main()
{
	int T,n,i,j,f;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&c[i]);
		f=0;
		for(j=0;j<=n;j++) dp[f][j]=LLINF;
		dp[f][1]=0;
		dp[f][0]=c[1];
		a[0]=0;
		for(i=2;i<=n;i++)
		{
			f^=1;
			for(j=0;j<=n;j++) dp[f][j]=LLINF;
			for(j=0;j<i;j++)
			{
				dp[f][j]=dp[!f][j]+c[i];
				if(a[j]<=a[i]) dp[f][i]=min(dp[f][i],dp[!f][j]);
			}
		}
		ans=LLINF;
		for(i=0;i<=n;i++) ans=min(ans,dp[f][i]);
		printf("%lld\n",ans);
	}
	return 0;
}
