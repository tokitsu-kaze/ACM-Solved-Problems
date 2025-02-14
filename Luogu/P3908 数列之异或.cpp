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
	ll n;
	scanf("%lld",&n);
	printf("%lld\n",xor_sum(n));
	return 0;
}
