#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int v[4][MAX],tot[4],c1[MAX],c2[MAX];
ll dp[MAX];
int main()
{
	int n,m,i,w,c;
	ll ans,sum;
	scanf("%d%d",&n,&m);
	memset(tot,0,sizeof tot);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&w,&c);
		v[w][++tot[w]]=c;
	}
	for(i=1;i<=3;i++)
	{
		sort(v[i]+1,v[i]+1+n);
		reverse(v[i]+1,v[i]+1+n);
	}
	dp[0]=0;
	c1[0]=c2[0]=0;
	for(i=1;i<=m;i++)
	{
		dp[i]=-LLINF;
		if(c1[i-1]+1<=tot[1] && dp[i]<dp[i-1]+v[1][c1[i-1]+1])
		{
			dp[i]=dp[i-1]+v[1][c1[i-1]+1];
			c1[i]=c1[i-1]+1;
			c2[i]=c2[i-1];
		}
		if(i-2>=0)
		{
			if(c1[i-2]+2<=tot[1] && dp[i]<dp[i-2]+v[1][c1[i-2]+1]+v[1][c1[i-2]+2])
			{
				dp[i]=dp[i-2]+v[1][c1[i-2]+1]+v[1][c1[i-2]+2];
				c1[i]=c1[i-2]+2;
				c2[i]=c2[i-2];
			}
			if(c2[i-2]+1<=tot[2] && dp[i]<dp[i-2]+v[2][c2[i-2]+1])
			{
				dp[i]=dp[i-2]+v[2][c2[i-2]+1];
				c1[i]=c1[i-2];
				c2[i]=c2[i-2]+1;
			}
		}
	}
	for(i=1;i<=m;i++) dp[i]=max(dp[i],dp[i-1]);
	ans=dp[m];
	sum=0;
	for(i=1;i<=tot[3] && 3*i<=m;i++)
	{
		sum+=v[3][i];
		ans=max(ans,sum+dp[m-3*i]);
	}
	printf("%lld\n",ans);
	return 0;
}
