#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int t,n,i,a[11];
	ll ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=1;
		sort(a+1,a+1+n);
		a[1]++;
		for(i=1;i<=n;i++) ans=ans*a[i];
		printf("%lld\n",ans);
	}
	return 0;
}
