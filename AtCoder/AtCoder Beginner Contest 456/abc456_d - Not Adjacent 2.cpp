#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
const int mod=998244353;
char s[MAX];
ll dp[MAX][3];
int main()
{
	int n,i,j,t;
	ll ans;
	scanf("%s",s+1);
	n=strlen(s+1);
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++)
	{
		t=s[i]-'a';
		for(j=0;j<3;j++) dp[i][j]=dp[i-1][j];
		dp[i][t]=(dp[i][t]+1)%mod;
		for(j=0;j<3;j++)
		{
			if(t==j) continue;
			dp[i][t]=(dp[i][t]+dp[i-1][j])%mod;
		}
	}
	ans=0;
	for(j=0;j<3;j++) ans=(ans+dp[n][j])%mod;
	printf("%lld\n",ans);
	return 0;
}
