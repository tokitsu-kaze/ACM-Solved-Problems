#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
ll cal(ll n,ll m,ll x)
{
	ll res=0;
	res+=x/n;
	res+=x/m;
	res-=2*(x/(n/__gcd(n,m)*m));
	return res;
}
int main()
{
	ll n,m,k,l,r,mid;
	scanf("%lld%lld%lld",&n,&m,&k);
	if(n>m) swap(n,m);
	l=n;
	r=2e18;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(cal(n,m,mid)>=k) r=mid;
		else l=mid+1;
	}
//	printf("%lld\n",cal(n,m,l));
	printf("%lld\n",l);
	return 0;
}
