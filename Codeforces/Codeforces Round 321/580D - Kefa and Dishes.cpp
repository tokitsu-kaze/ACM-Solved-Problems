#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
ll dp[(1<<18)+10][21],mp[22][22],v[22];
int main()
{
	int n,m,k,s,i,j,a,b,c;
	ll ans;
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<n;i++) scanf("%lld",&v[i]);
	while(k--)
	{
		scanf("%d%d%d",&a,&b,&c);
		a--;
		b--;
		mp[a][b]=c;
	}
	memset(dp,0,sizeof dp);
	for(i=0;i<n;i++) dp[1<<i][i]=v[i];
	for(s=0;s<(1<<n);s++)
	{
		for(i=0;i<n;i++)
		{
			if(!((s>>i)&1)) continue;
			for(j=0;j<n;j++)
			{
				if((s>>j)&1) continue;
				dp[s|(1<<j)][j]=max(dp[s|(1<<j)][j],dp[s][i]+v[j]+mp[i][j]);
			}
		}
	}
	ans=0;
	for(s=0;s<(1<<n);s++)
	{
		if(__builtin_popcount(s)!=m) continue;
		for(i=0;i<n;i++) ans=max(ans,dp[s][i]);
	}
	printf("%lld\n",ans);
	return 0;
}
