#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
ll xor_sum(ll n)
{
    ll t=n&3;
    if (t&1) return t/2ull^1;
    return t/2ull^n;
}
int main()
{
	int T;
	ll l,r,i,k,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld%lld",&l,&r,&i,&k);
		ans=xor_sum(r)^xor_sum(l-1);
		l=((l-k-1)>>i)+1;
		r=(r-k)>>i;
		if((r-l+1)&1) ans^=k;
		ans^=(xor_sum(r)^xor_sum(max(l-1,0LL)))<<i;
		printf("%lld\n",ans);
	}
	return 0;
}

