#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll dp[66][66];
int a[66],b[66];
int main()
{
	int T,n,m,i,j,k,lena,lenb;
	ll x,y,ans;
	memset(dp,0x3f,sizeof dp);
	dp[0][0]=0;
	for(i=1;i<=60;i++)
	{
		for(j=60;~j;j--)
		{
			for(k=60;~k;k--)
			{
				if(j-i>=0) dp[j][k]=min(dp[j][k],dp[j-i][k]+(1LL<<i));
				if(k-i>=0) dp[j][k]=min(dp[j][k],dp[j][k-i]+(1LL<<i));
			}
		}
	}
/*	for(i=0;i<=60;i++)
	{
		for(j=0;j<=60;j++)
		{
			printf("%d %d %lld\n",i,j,dp[i][j]);
		}
	}*/
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&x,&y);
		for(i=0;i<=60;i++) a[i+1]=((x>>i)&1);
		lena=0;
		for(i=61;i;i--)
		{
			if(a[i])
			{
				lena=i;
				break;
			}
		}
		reverse(a+1,a+1+lena);
		for(i=0;i<=60;i++) b[i+1]=((y>>i)&1);
		lenb=0;
		for(i=61;i;i--)
		{
			if(b[i])
			{
				lenb=i;
				break;
			}
		}
		reverse(b+1,b+1+lenb);
		ans=min({dp[lena][lenb],dp[lena][lenb+1],dp[lena+1][lenb]});
		for(i=1;i<=min(lena,lenb);i++)
		{
			if(a[i]!=b[i]) break;
			ans=min(ans,dp[lena-i][lenb-i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

