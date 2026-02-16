#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int K=450;
int a[MAX];
ll dp[MAX][K],sum[MAX];
int main()
{
	int T,n,i,j,p;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		sum[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		memset(dp[n+1],-0x3f,sizeof dp[n+1]);
		for(i=n;i;i--)
		{
			for(j=0;j<K;j++) dp[i][j]=dp[i+1][j];
			dp[i][1]=max(dp[i][1],1LL*a[i]);
			for(j=2;j<K;j++)
			{
				if(i+j>n) continue;
				p=i+j-1;
				if(sum[p]-sum[i-1]>=dp[p+1][j-1]) continue;
				dp[i][j]=max(dp[i][j],sum[p]-sum[i-1]);
			}
		}
		for(j=K-1;j;j--)
		{
			if(dp[1][j]>0)
			{
				printf("%d\n",j);
				break;
			}
		}
	}
	return 0;
}
/*
首先发现最多只有根号段。
设 dp[i][j] 表示前 i 个数分成 j 段的最小值，
发现因为第一段长度是根据总段数决定，
所以考虑倒过来，
设 dp[i][j] 表示后 i 个数分成 j 段的最大值。
*/
