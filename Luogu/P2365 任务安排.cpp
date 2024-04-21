#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e3+10;
ll t[MAX],f[MAX],dp[MAX],bitt[MAX],bitf[MAX];
int main()
{
	int n,i,j;
	ll s;
	scanf("%d",&n);
	scanf("%lld",&s);
	bitt[0]=bitf[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&t[i],&f[i]);
		bitt[i]=bitt[i-1]+t[i];
		bitf[i]=bitf[i-1]+f[i];
	}
	memset(dp,0x3f,sizeof dp);
	dp[0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			dp[i]=min(dp[i],dp[j-1]
							+s*(bitf[n]-bitf[j-1])
							+(bitf[i]-bitf[j-1])*bitt[i]);
		}
	}
	printf("%lld\n",dp[n]);
	return 0;
}
/*
(f1+f2)*(s+t1+t2) + (f3)*(2*s+t1+t2+t3) + (f4+f5)*(3*s+t1+...+t5)

=(f1+...+f5)*s + (f3+f4+f5)*s + (f4+f5)*s
 + (f1+f2)*(t1+t2) + f3*(t1+t2+t3) + (f4+f5)*(t1+...+t5)

*/
