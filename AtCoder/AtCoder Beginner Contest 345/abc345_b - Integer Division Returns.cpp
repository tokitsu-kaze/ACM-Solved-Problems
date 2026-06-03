#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	ll x;
	scanf("%lld",&x);
	if(x<0) printf("%lld\n",x/10);
	else printf("%lld\n",(x+9)/10);
	return 0;
}
