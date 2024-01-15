#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
int main()
{
	ll d,k,a,b,t,ans;
	scanf("%lld%lld%lld%lld%lld",&d,&k,&a,&b,&t);
	ans=b*d;
	ans=min(ans,min(d,k)*a+(d-min(d,k))*b);
	ans=min(ans,d/k*t+d*a);
	ans=min(ans,max(0ll,d/k-1)*t+d/k*k*a+(d-d/k*k)*b);
	printf("%lld\n",ans);
	return 0;
}
