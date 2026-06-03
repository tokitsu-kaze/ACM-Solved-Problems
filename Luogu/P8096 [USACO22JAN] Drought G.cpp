#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
const int mod=1e9+7;
int h[102],dp[102][1002];
int main()
{
	int n,i,j,k,x,ans,mn;
	scanf("%d",&n);
	mn=INF;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
		mn=min(mn,h[i]);
	}
	ans=0;
	if(n%2==0) mn=0;
	for(x=0;x<=mn;x++)
	{
		for(i=1;i<=n;i++) h[i]-=x;
		memset(dp,0,sizeof dp);
		dp[0][0]=1;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=h[i-1] && h[i]-j+1>=0;j++)
			{
	//			for(k=j;k<=h[i];k++) dp[i][k-j]+=dp[i-1][j];
				dp[i][0]=(dp[i][0]+dp[i-1][j])%mod;
				dp[i][h[i]-j+1]=(dp[i][h[i]-j+1]-dp[i-1][j]+mod)%mod;
			}
			for(j=1;j<=h[i]+1;j++) dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
		}
		ans=(ans+dp[n][0])%mod;
		for(i=1;i<=n;i++) h[i]+=x;
	}
	printf("%d\n",ans);
	return 0;
}
/*
dp[i][j]表示前i-1都是0，第i个剩j的方案数。
转移：前一个剩j，枚举当前填 k，则剩k-j
当n为偶数时，如果整个序列能变成一种数，那么这个序列也能全变为0。
所以当n为偶数时，以0作为代表。
当n为奇数时，需要枚举全变为 x。相当于把h[i]全减掉 x。

发现转移过程，相当于把dp[i-1][j]对dp[i]的一个区间进行更新。
用差分优化一下。 
*/
