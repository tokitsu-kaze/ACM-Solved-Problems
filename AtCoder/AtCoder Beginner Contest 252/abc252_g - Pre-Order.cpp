#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int dp[505][505],a[505];
int main()
{
	int len,l,r,i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++) dp[i][i]=1;
	for(len=2;len<=n;len++)
	{
		for(l=1;l+len-1<=n;l++)
		{
			r=l+len-1;
			for(i=l+1;i<=r;i++)
			{
				if(i==r || a[l+1]<a[i+1]) dp[l][r]=(dp[l][r]+1LL*dp[l+1][i]*dp[i][r])%mod;
			}
		}
	}
	printf("%d\n",dp[1][n]);
	return 0;
}
