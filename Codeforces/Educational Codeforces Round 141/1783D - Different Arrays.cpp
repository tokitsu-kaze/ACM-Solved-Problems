#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=300+10;
const int mod=998244353;
int a[MAX],dp[MAX][MAX*MAX*2];
int main()
{
	int n,i,j,D,sum,ans;
	scanf("%d",&n);
	sum=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	D=2*sum;
	memset(dp,0,sizeof dp);
	dp[0][a[2]+D]=1;
	for(i=0;i<=n-3;i++)
	{
		for(j=-sum;j<=sum;j++)
		{
			if(a[i+3]+j<=sum)
			{
				(dp[i+1][a[i+3]+j+D]+=dp[i][j+D])%=mod;
			}
			if(j!=0 && a[i+3]-j>=-sum)
			{
				(dp[i+1][a[i+3]-j+D]+=dp[i][j+D])%=mod;
			}
		}
	}
	ans=0;
	for(j=-sum;j<=sum;j++) ans=(ans+dp[n-2][j+D])%mod;
	printf("%d\n",ans);
	return 0;
}
