#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
const int mod=998244353;
ll sum[MAX],inv[MAX];
void init_inv(int n,ll p)
{
	inv[1]=1;
	for(int i=2;i<=n;i++) inv[i]=(p-p/i)*inv[p%i]%p;
}
int main()
{
	int n,i,x,l,r;
	ll ans;
	scanf("%d",&n);
	init_inv(n,mod);
	memset(sum,0,sizeof sum);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		l=min(i,n-i+1);
		r=max(i,n-i+1);
		sum[1]=(sum[1]+x)%mod;
		sum[l+1]=(sum[l+1]-x+mod)%mod;
		sum[r+1]=(sum[r+1]-x+mod)%mod;
	}
	for(i=1;i<=n;i++) sum[i]=(sum[i-1]+sum[i])%mod;
	for(i=1;i<=n;i++) sum[i]=(sum[i-1]+sum[i])%mod;
	ans=0;
	for(i=1;i<=n;i++) ans=(ans+sum[i]*inv[i])%mod;
	printf("%lld\n",ans);
	return 0;
}
