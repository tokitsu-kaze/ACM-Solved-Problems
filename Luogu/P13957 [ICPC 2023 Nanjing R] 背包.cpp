#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=5e3+10;
const int W=1e4+10;
struct node{int w,v;}a[N];
ll dpsuf[N][N],dp[W];
int main()
{
	int n,w,k,i,j;
	ll ans;
	scanf("%d%d%d",&n,&w,&k);
	for(i=1;i<=n;i++) scanf("%d%d",&a[i].w,&a[i].v);
	sort(a+1,a+1+n,[](node x,node y){
		return x.w<y.w;
	});
	memset(dpsuf,0,sizeof dpsuf);
	for(i=n;i;i--)
	{
		dpsuf[i][0]=dpsuf[i+1][0];
		for(j=1;j<=k;j++)
		{
			dpsuf[i][j]=max(dpsuf[i+1][j],dpsuf[i+1][j-1]+a[i].v);
		}
	}
	memset(dp,0,sizeof dp);
	ans=dpsuf[1][k];
	for(i=1;i<=n;i++)
	{
		for(j=w;j>=a[i].w;j--) dp[j]=max(dp[j],dp[j-a[i].w]+a[i].v);
		for(j=0;j<=w;j++) ans=max(ans,dp[j]+dpsuf[i+1][k]);
	}
	printf("%lld\n",ans);
	return 0;
}

