#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
const int mod=998244353;
int a[MAX],b[MAX];
ll suma[MAX],s[MAX];
int main()
{
	int n,m,i,j,tmp;
	ll ans,now;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=m;i++) scanf("%d",&b[i]);
	suma[0]=s[0]=0;
	for(i=1;i<=n;i++)
	{
		suma[i]=(suma[i-1]+a[i])%mod;
		s[i]=(s[i-1]+1LL*i*a[i])%mod;
	}
	ans=0;
	for(i=2;i<=m;i++)
	{
		for(j=i;j<=n;j+=i)
		{
			now=(s[j-1]-s[j-i])-(j-i)*(suma[j-1]-suma[j-i]);
			now=(now%mod+mod)%mod;
			ans=(ans+now*b[i])%mod;
		}
		if(n%i)
		{
			tmp=(n+i-1)/i*i;
			now=(s[n]-s[tmp-i])-(tmp-i)*(suma[n]-suma[tmp-i]);
			now=(now%mod+mod)%mod;
			ans=(ans+now*b[i])%mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
