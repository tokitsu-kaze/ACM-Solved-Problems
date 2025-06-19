#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=1e9+7;
ll fac[MAX];
int a[MAX];
int main()
{
	int T,n,i,res,cnt;
	fac[0]=1;
	for(i=1;i<MAX;i++) fac[i]=fac[i-1]*i%mod;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		res=a[1];
		for(i=2;i<=n;i++) res&=a[i];
		cnt=0;
		for(i=1;i<=n;i++) cnt+=(a[i]==res);
		printf("%lld\n",1LL*cnt*(cnt-1)%mod*fac[n-2]%mod);
	}
	return 0;
}
