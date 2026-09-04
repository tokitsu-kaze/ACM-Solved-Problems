#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=200+10;
int main()
{
	int T;
	ll a,b,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&a,&b,&k);
		if(k==1)
		{
			puts("No");
			continue;
		}
		if(a<b) swap(a,b);
		if(a==b || (a-1+b-__gcd(a,b))/b<k) puts("Yes");
		else puts("No");
	}
	return 0;
}

