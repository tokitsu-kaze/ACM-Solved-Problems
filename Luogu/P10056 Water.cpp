#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	ll a,b,n;
	scanf("%lld%lld%lld",&a,&b,&n);
	printf("%lld\n",min(a/b*b,b*n));
	return 0;
}
