#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
int main()
{
	int T;
	ll a,b,g;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&a,&b);
		while(1)
		{
			g=__gcd(a,b);
			if(g==1) break;
			b/=g;
		}
		if(b==1) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
4
50 20
1 1
10 1
1 10
*/

