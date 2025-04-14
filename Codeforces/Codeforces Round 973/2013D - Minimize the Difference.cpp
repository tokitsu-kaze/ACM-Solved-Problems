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
	ll sum,tmp,mn,mx;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		sum=0;
		mn=LLINF;
		for(i=1;i<=n;i++)
		{
			sum+=a[i];
			mn=min(mn,sum/i);
		}
		sum=0;
		mx=-LLINF;
		for(i=n;i;i--)
		{
			sum+=a[i];
			mx=max(mx,(sum+n-i)/(n-i+1));
		}
		printf("%lld\n",mx-mn);
	}
	return 0;
}
