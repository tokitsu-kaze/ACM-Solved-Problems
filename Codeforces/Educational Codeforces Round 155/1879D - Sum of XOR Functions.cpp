#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
const int mod=998244353;
int a[MAX],cnt[MAX][2];
ll sum[MAX][2];
int main()
{
	int n,i,j,k,f;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=0;
	for(j=0;j<=30;j++)
	{
		cnt[0][0]=1;
		sum[0][0]=sum[0][1]=cnt[0][1]=0;
		f=0;
		for(i=1;i<=n;i++)
		{
			f+=(a[i]>>j)&1;
			f&=1;
			ans+=(1LL<<j)*((1LL*cnt[i-1][!f]*i-sum[i-1][!f])%mod)%mod;
			ans%=mod;
			for(k=0;k<2;k++)
			{
				cnt[i][k]=cnt[i-1][k];
				sum[i][k]=sum[i-1][k];
			}
			sum[i][f]+=i;
			cnt[i][f]++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}

