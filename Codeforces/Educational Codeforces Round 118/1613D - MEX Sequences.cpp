#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
const int mod=998244353;
int a[MAX];
ll dp[MAX][2];
int main()
{
	int T,i,j,n,cnt1;
	ll ans,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=0;i<=n+2;i++) dp[i][0]=dp[i][1]=0;
		cnt1=0;
		for(i=1;i<=n;i++)
		{
			dp[a[i]][0]+=dp[a[i]][0];
			if(a[i]>=1) dp[a[i]][0]+=dp[a[i]-1][0];
			if(a[i]==0) dp[a[i]][0]++;
			dp[a[i]][0]%=mod;
			
			dp[a[i]][1]+=dp[a[i]][1];
			if(a[i]>=2) dp[a[i]][1]+=dp[a[i]-2][0];
			dp[a[i]][1]%=mod;
			dp[a[i]+2][1]=dp[a[i]+2][1]*2%mod;
			
			if(a[i]==1) cnt1++;
		}
		ans=0;
		for(i=0;i<=n;i++) ans=(ans+dp[i][0]+dp[i][1])%mod;
		now=1;
		for(i=1;i<=cnt1;i++) now=now*2%mod;
		ans=(ans+now-1+mod)%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
4
6
0 1 2 0 1 2
10
0 1 2 3 0 1 2 3 0 1
6
0 2 0 2 2 0
5
0 2 4 2 0

0 1 1 1 2 2 2
0 2 0 2 2 0 2
*/
