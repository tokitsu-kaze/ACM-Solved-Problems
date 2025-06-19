#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
int d[MAX],a[MAX];
ll dp[MAX][MAX];
int main()
{
	int n,l,k,i,j,x;
	ll ans;
	scanf("%d%d%d",&n,&l,&k);
	for(i=1;i<=n;i++) scanf("%d",&d[i]);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	d[n+1]=l;
	a[n+1]=0;
	n++;
	memset(dp,0x3f,sizeof dp);
	dp[1][0]=0;
	for(i=2;i<=n;i++)
	{
		for(j=1;j<i;j++)
		{
			for(x=0;x<=k;x++)
			{
				if(x-(i-j-1)<0) continue;
				dp[i][x]=min(dp[i][x],dp[j][x-(i-j-1)]+1LL*a[j]*(d[i]-d[j]));
			}
		}
	}
	ans=LLINF;
	for(x=0;x<=k;x++) ans=min(ans,dp[n][x]);
	printf("%lld\n",ans);
	return 0;
}
