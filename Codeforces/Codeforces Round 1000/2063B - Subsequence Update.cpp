#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX];
int main()
{
	int T,n,l,r,i;
	ll ans,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&l,&r);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=LLINF;
		
		for(i=1;i<=r;i++) b[i]=a[i];
		sort(b+1,b+1+r);
		now=0;
		for(i=1;i<=r-l+1;i++) now+=b[i];
		ans=min(ans,now);
		
		for(i=l;i<=n;i++) b[i-l+1]=a[i];
		sort(b+1,b+1+(n-l+1));
		now=0;
		for(i=1;i<=r-l+1;i++) now+=b[i];
		ans=min(ans,now);
		
		printf("%lld\n",ans);
	}
	return 0;
}
