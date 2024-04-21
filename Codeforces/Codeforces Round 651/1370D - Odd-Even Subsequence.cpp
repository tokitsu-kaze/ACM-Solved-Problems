#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int n,k,a[MAX],dp[MAX][2];
int ck(int x)
{
	int i;
	for(i=0;i<=n;i++) memset(dp[i],0,sizeof dp[i]);
	dp[0][1]=-INF;
	for(i=1;i<=n;i++)
	{
		dp[i][0]=dp[i-1][0];
		dp[i][1]=dp[i-1][1];
		if(a[i]<=x) dp[i][1]=max(dp[i][1],dp[i-1][0]+1);
		dp[i][0]=max(dp[i][0],dp[i-1][1]+1);
	}
	if(dp[n][k&1]>=k) return 1;
	for(i=0;i<=n;i++) memset(dp[i],0,sizeof dp[i]);
	dp[0][1]=-INF;
	for(i=1;i<=n;i++)
	{
		dp[i][0]=dp[i-1][0];
		dp[i][1]=dp[i-1][1];
		if(a[i]<=x) dp[i][0]=max(dp[i][0],dp[i-1][1]+1);
		dp[i][1]=max(dp[i][1],dp[i-1][0]+1);
	}
	if(dp[n][k&1]>=k) return 1;
	return 0;
}
int main()
{
	int i,l,r,mid;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	l=1;
	r=1e9;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}
