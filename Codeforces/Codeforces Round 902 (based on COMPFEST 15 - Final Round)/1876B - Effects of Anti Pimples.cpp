#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int mod=998244353;
int mx[MAX],a[MAX];
ll pw2[MAX];
int main()
{
	int n,i,j,x;
	ll ans;
	pw2[0]=1;
	for(i=1;i<MAX;i++) pw2[i]=pw2[i-1]*2%mod;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		mx[i]=0;
		for(j=i;j<=n;j+=i) mx[i]=max(mx[i],a[j]);
	}
	sort(mx+1,mx+1+n);
	ans=0;
	for(i=1;i<=n;i++) ans=(ans+pw2[i-1]*mx[i])%mod;
	printf("%lld\n",ans);
	return 0;
}

