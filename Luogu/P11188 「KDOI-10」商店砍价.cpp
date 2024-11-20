#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
char s[MAX];
int v[11];
ll dp[MAX][12];
int main()
{
	const int k=11;
	int sid,T,n,i,j;
	ll pw,ans;
	scanf("%d",&sid);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		for(i=1;i<=9;i++) scanf("%d",&v[i]);
		reverse(s+1,s+1+n);
		for(i=0;i<=n;i++) memset(dp[i],0x3f,sizeof dp[i]);
		dp[0][0]=0;
		for(i=1;i<=n;i++)
		{
			dp[i][0]=dp[i-1][0]+v[s[i]-'0'];
			pw=1;
			for(j=1;j<=k;j++)
			{
				dp[i][j]=dp[i-1][j]+v[s[i]-'0'];
				dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(s[i]-'0')*pw);
				pw*=10;
			}
		}
		ans=LLINF;
		for(i=0;i<=k;i++) ans=min(ans,dp[n][i]);
		printf("%lld\n",ans);
	}
	return 0;
}
