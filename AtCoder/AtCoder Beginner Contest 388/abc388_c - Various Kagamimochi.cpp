#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e5+10;
int a[MAX];
int main()
{
	int n,i;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=0;
	for(i=1;i<=n;i++)
	{
		ans+=upper_bound(a+1,a+1+n,a[i]/2)-a-1;
	}
	printf("%lld\n",ans);
	return 0;
}

