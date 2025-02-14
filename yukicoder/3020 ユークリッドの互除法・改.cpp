#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e5+10;
const int mod=1e9;
int main()
{
	ll a,b,c,d,z,g;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	z=abs(a*d-b*c);
	g=0;
	g=abs(__gcd(g,a));
	g=abs(__gcd(g,b));
	g=abs(__gcd(g,c));
	g=abs(__gcd(g,d));
	if(g==0) printf("%lld %lld\n",g,0LL);
	else printf("%lld %lld\n",g,z/g);
	
	return 0;
}
