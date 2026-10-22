#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T;
	ll m,d,w,mn,g,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&m,&d,&w);
		mn=min(m,d);
		d--;
		g=__gcd(d,w);
		d/=g;
		w/=g;
		k=(mn-1)/w;
		printf("%lld\n",mn*k-(1+k)*k/2*w);
	}
	return 0;
}
