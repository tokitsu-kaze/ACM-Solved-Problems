#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,a[105],g,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		g=0;
		for(i=2;i<=n;i++) g=__gcd(g,a[i]-a[i-1]);
		ans=0;
		for(i=2;i<=n;i++) ans+=(a[i]-a[i-1])/g-1;
		printf("%d\n",ans);
	}
	return 0;
}

