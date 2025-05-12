#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
int a[MAX],sum[MAX],xorsum[MAX],n,m;
ll cal(ll x)
{
	if(x<=m) return sum[x];
	ll res=cal(n+2*((x-m-1)/4)+min((x-m-1)%4+1,2ll))-sum[n];
	if(xorsum[n]) res=x-m-res;
	return res+sum[m];
}
int main()
{
	int T,i;
	ll l,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld%lld",&n,&l,&r);
		sum[0]=xorsum[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
			xorsum[i]=xorsum[i-1]^a[i];
		}
		if(!(n&1))
		{
			n++;
			a[n]=xorsum[n/2];
			sum[n]=sum[n-1]+a[n];
			xorsum[n]=xorsum[n-1]^a[n];
		}
		m=2*n+1;
		for(i=n+1;i<=m;i++)
		{
			a[i]=xorsum[i/2];
			sum[i]=sum[i-1]+a[i];
			xorsum[i]=xorsum[i-1]^a[i];
		}
		printf("%lld\n",cal(r)-cal(l-1));
	}
	return 0;
}
