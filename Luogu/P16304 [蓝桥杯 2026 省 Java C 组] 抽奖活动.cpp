#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=(1<<20)+10;
int dp[MAX],a[22];
int main()
{
	int n,k,i,s,l,r,ans;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	memset(dp,-0x3f,sizeof dp);
	dp[(1<<n)-1]=0;
	for(s=(1<<n)-1;~s;s--)
	{
		l=0;
		r=__builtin_popcount(s);
		for(i=0;i<n;i++)
		{
			if(!((s>>i)&1)) continue;
			r--;
			if(r>0 && l%r==0) dp[s^(1<<i)]=max(dp[s^(1<<i)],dp[s]+a[i]);
			l++;
		}
	}
	ans=0;
	for(s=0;s<(1<<n);s++)
	{
		if(n-__builtin_popcount(s)<=k) ans=max(ans,dp[s]);
	}
	printf("%d\n",ans);
	return 0;
}
