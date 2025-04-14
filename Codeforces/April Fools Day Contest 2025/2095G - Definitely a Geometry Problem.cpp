#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const double PI=acos(-1.0);
double sqr(ll x)
{
	return x*x;
}
pair<ll,ll> a[MAX];
int main()
{
	int n,k,i;
	double d;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%lld%lld",&a[i].first,&a[i].second);
	sort(a+1,a+1+n);
	d=1e18;
	for(i=k;i<=n;i++)
	{
		d=min(d,sqrt(sqr(a[i].first-a[i-k+1].first)+
					 sqr(a[i].second-a[i-k+1].second)));
	}
	long double r=d*1.0/2;
	printf("%.10Lf\n",r*r*PI);
	return 0;
}
