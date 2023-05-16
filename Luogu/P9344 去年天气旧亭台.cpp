#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fll;
const int MAX=2e6+10;
ll a[MAX];
int c[MAX];
int main()
{
	int t,n,i;
	ll ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&c[i]);
		ans=LLINF;
		for(i=1;i<n;i++)
		{
			if(c[i]==c[1] && c[i+1]==c[n]) ans=min(ans,a[1]+a[i]+a[i+1]+a[n]);
		}
		if(c[1]==c[n]) ans=min(ans,a[1]+a[n]);
		printf("%lld\n",ans);
	}
	
	return 0;
}
