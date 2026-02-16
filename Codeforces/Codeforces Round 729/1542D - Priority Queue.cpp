#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
const int mod=998244353;
int n,v[MAX],dp[MAX][MAX];
ll ans;
void work(int p)
{
	int i,j;
	memset(dp,0,sizeof dp);
	dp[0][0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(i==p)
			{
				if(j>=1) dp[i][j]=dp[i-1][j-1];
				continue;
			}
			if(v[i]==-1)
			{
				dp[i][j]=(dp[i-1][j]+dp[i-1][j+1])%mod;
				if(i<p && j==0) dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
			}
			else if(v[i]<v[p] || (v[i]==v[p] && i<p))
			{
				dp[i][j]=dp[i-1][j];
				if(j>=1) dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
			}
			else // v[i]>v[p]
			{
				dp[i][j]=dp[i-1][j]*2%mod;
			}
			if(i>p) dp[i][0]=0;
		}
	}
	for(i=1;i<=n;i++) ans=(ans+1LL*v[p]*dp[n][i])%mod;
}
int main()
{
	int i;
	char op[2];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",op);
		if(op[0]=='-') v[i]=-1;
		else scanf("%d",&v[i]);
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		if(v[i]>=1) work(i);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
考虑对于每个 + x 算贡献。
每个 + x 单独考虑。
dp[i][j] 表示前i个中，有j个数<=x的方案数。
转移分讨一下。
注意在本次 + x 之后的dp[i][0]都是不合法的。 

4
-
+ 1
+ 1
-

ans=10

*/
