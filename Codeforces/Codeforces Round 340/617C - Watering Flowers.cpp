#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e3+10;
ll sqr(ll x){return x*x;}
ll x[MAX],y[MAX];
int main()
{
	int n,i,j;
	ll a,b,c,d,r1,r2,ans;
	scanf("%d%lld%lld%lld%lld",&n,&a,&b,&c,&d);
	for(i=1;i<=n;i++) scanf("%lld%lld",&x[i],&y[i]);
	ans=LLINF;
	for(i=1;i<=n;i++)
	{
		r1=sqr(x[i]-a)+sqr(y[i]-b);
		r2=0;
		for(j=1;j<=n;j++)
		{
			if(sqr(x[j]-a)+sqr(y[j]-b)<=r1) continue;
			r2=max(r2,sqr(x[j]-c)+sqr(y[j]-d));
		}
		ans=min(ans,r1+r2);
	}
	swap(a,c);
	swap(b,d);
	for(i=1;i<=n;i++)
	{
		r1=sqr(x[i]-a)+sqr(y[i]-b);
		r2=0;
		for(j=1;j<=n;j++)
		{
			if(sqr(x[j]-a)+sqr(y[j]-b)<=r1) continue;
			r2=max(r2,sqr(x[j]-c)+sqr(y[j]-d));
		}
		ans=min(ans,r1+r2);
	}
	printf("%lld\n",ans);
	return 0;
}
