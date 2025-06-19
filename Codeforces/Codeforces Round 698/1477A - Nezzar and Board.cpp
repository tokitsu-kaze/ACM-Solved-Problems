#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll a[MAX];
int main()
{
	int T,n,i;
	ll k,g;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld",&n,&k);
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		sort(a+1,a+1+n);
		g=0;
		for(i=2;i<=n;i++) g=__gcd(a[i]-a[1],g);
		if((k-a[1])%g) puts("NO");
		else puts("YES");
	}
	return 0;
}
