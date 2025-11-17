#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i,h,w;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&w,&h);
		ans=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=max(ans,1LL*(a[n]-a[1])*h);
		
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=max(ans,1LL*(a[n]-a[1])*h);
		
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=max(ans,1LL*(a[n]-a[1])*w);
		
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=max(ans,1LL*(a[n]-a[1])*w);
		
		printf("%lld\n",ans);
	}
	return 0;
}

