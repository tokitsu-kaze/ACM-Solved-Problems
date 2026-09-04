#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
const int mod=998244353;
int cnt[MAX];
int dp[MAX][MAX];
int main()
{
	int n,i,j,s,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&cnt[i]);
	sort(cnt+1,cnt+1+n);
	s=0;
	memset(dp[0],0,sizeof dp[0]);
	dp[0][0]=1;
	ans=0;
	for(i=1;i<=n;i++)
	{
		s+=cnt[i];
		for(j=0;j<=s;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(j-cnt[i]>=0)
			{
				dp[i][j]=(dp[i][j]+dp[i-1][j-cnt[i]])%mod;
				ans=(ans+1LL*dp[i-1][j-cnt[i]]*max((j+1)/2,cnt[i]))%mod;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
计算贡献需要知道当前sum和max。
sum{a}<=5000
从小到大枚举，当前就是max。
dp[i][j]表示考虑了前 i 种颜色，当前个数之和为 j 的方案数。
当前不选，只更新dp；当前选，更新dp和ans。
*/
