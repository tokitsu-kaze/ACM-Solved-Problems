#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	scanf("%lld",&n);
	printf("%lld\n",(n>>16)+((n&((1<<16)-1))<<16));
	return 0;
}
