#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	ll n,a,b;
	scanf("%lld%lld%lld",&n,&a,&b);
	printf("%lld\n",n-(n/a+n/b-n/(a/__gcd(a,b)*b)));
	return 0;
}

