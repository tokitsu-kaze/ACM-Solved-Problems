#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+20;
const int mod=1e9+7;
int dp[MAX][10],res[MAX];
int main()
{
	int T,n,m,i,j,ans;
	dp[0][0]=1;
	res[0]=1;
	for(i=1;i<MAX;i++)
	{
		dp[i][0]=dp[i-1][9];
		for(j=1;j<=9;j++) dp[i][j]=dp[i-1][j-1];
		dp[i][1]=(dp[i][1]+dp[i-1][9])%mod;
		res[i]=0;
		for(j=0;j<=9;j++) res[i]=(res[i]+dp[i][j])%mod;
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		ans=0;
		string tmp=to_string(n);
		for(auto &ch:tmp) ans=(ans+res[ch-'0'+m])%mod;
		printf("%d\n",ans);
	}
	return 0;
}
