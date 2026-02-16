#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
const int mod=998244353;
int a[MAX],dp[2][2*MAX][2];
int main()
{
	int n,i,j,f,ans,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	ans=0;
	f=0;
	memset(dp[f],0,sizeof dp[f]);
	dp[f][0][0]=1;
	for(i=1;i<=n;i++)
	{
		f^=1;
		memset(dp[f],0,sizeof dp[f]);
		for(j=0;j<=2*5000+1;j++) dp[f][j][0]=(dp[!f][j][0]+dp[!f][j][1])%mod;
		for(j=0;j<=2*5000+1;j++)
		{
			k=min(2*5000+1,j+a[i]);
			dp[f][k][1]=(dp[f][k][1]+dp[f][j][0])%mod;
		}
		for(j=2*a[i]+1;j<=2*5000+1;j++) ans=(ans+dp[f][j][1])%mod;
	}
	printf("%d\n",ans);
	return 0;
}
