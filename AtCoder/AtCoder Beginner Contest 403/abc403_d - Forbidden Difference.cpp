#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int cnt[MAX],sum[MAX],dp[MAX][2];
int main()
{
	int n,d,i,j,x,ans,mx;
	scanf("%d%d",&n,&d);
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	if(d==0)
	{
		ans=0;
		for(i=0;i<MAX;i++) ans+=min(cnt[i],1);
		printf("%d\n",n-ans);
		return 0;
	}
	ans=0;
	for(i=0;i<=d-1;i++)
	{
		mx=0;
		dp[0][0]=0;
		dp[0][1]=cnt[i];
		mx=cnt[i];
		for(j=1;i+j*d<MAX;j++)
		{
			dp[j][0]=max(dp[j-1][0],dp[j-1][1]);
			dp[j][1]=dp[j-1][0]+cnt[i+j*d];
			mx=max({mx,dp[j][0],dp[j][1]});
		}
		ans+=mx;
	}
	printf("%d\n",n-ans);
	return 0;
}
