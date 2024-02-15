#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll a[MAX],d[MAX];
int main()
{
	int n,i;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	a[0]=0;
	for(i=1;i<=n;i++) d[i]=a[i]-a[i-1];
	d[0]=0;
	ans=0;
	for(i=1;i<=n;i++) ans+=abs(d[i]-d[i-1]);
	printf("%lld\n",ans);
	return 0;
}
/*
1 2 -5 -5 12
0 1 -6 -6 11
0 0 -7 -7 10
0 0  0  0 17

1 1 -7 0 17
*/
