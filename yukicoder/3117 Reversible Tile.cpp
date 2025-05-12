#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
const int mod=998244353;
int a[MAX];
ll dp[2][MAX];
ll cal(ll x){return x*(x-1)/2%mod;}
int main()
{
	int n,m,i,j,f,cnt;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	cnt=0;
	a[0]=a[n+1]=0;
	for(i=1;i<=n+1;i++) cnt+=(a[i]!=a[i-1]);
	f=0;
	memset(dp[f],0,sizeof dp[f]);
	dp[f][cnt]=1;
	for(i=1;i<=m;i++)
	{
		f^=1;
		for(j=0;j<=n+1;j++)
		{
			dp[f][j]=0;
			if(j+2<=n+1) dp[f][j]+=dp[!f][j+2]*cal(j+2)%mod;
			if(j-2>=0) dp[f][j]+=dp[!f][j-2]*cal((n+1)-(j-2))%mod;
			dp[f][j]+=dp[!f][j]*(j*((n+1)-j)%mod)%mod;
			dp[f][j]%=mod;
		}
	}
	printf("%lld\n",dp[f][0]);
	return 0;
}

