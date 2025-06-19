#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T;
	ll n,now,g;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		while(1)
		{
			string tmp=to_string(n);
			now=0;
			for(auto &it:tmp) now+=it-'0';
			g=__gcd(now,n);
			if(g>1 && n%g==0) break;
			n++;
		}
		printf("%lld\n",n);
	}
	return 0;
}
