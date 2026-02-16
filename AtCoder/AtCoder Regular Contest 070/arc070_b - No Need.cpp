#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e3+10;
const int mod=1e9+9;
int dp[MAX],a[MAX],tmp[MAX];
int main()
{
	int n,k,i,j,ans,ok;
	scanf("%d%d",&n,&k);
	memset(dp,0,sizeof dp);
	dp[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(j=k;j>=a[i];j--) dp[j]=(dp[j]+dp[j-a[i]])%mod;
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]>=k) continue;
		for(j=0;j<=k;j++) tmp[j]=dp[j];
		for(j=a[i];j<=k;j++) tmp[j]=(tmp[j]-tmp[j-a[i]]+mod)%mod;
		ok=1;
		for(j=k-a[i];j<k;j++)
		{
			if(tmp[j]) ok=0;
		}
		ans+=ok;
	}
	printf("%d\n",ans);
	return 0;
}
