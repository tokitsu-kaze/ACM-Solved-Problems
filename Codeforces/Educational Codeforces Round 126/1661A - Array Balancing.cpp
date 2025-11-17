#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,i,a[33],b[33],ra,rb;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		ans=0;
		for(i=1;i<n;i++)
		{
			ra=abs(a[i]-a[i+1])+abs(b[i]-b[i+1]);
			rb=abs(a[i]-b[i+1])+abs(b[i]-a[i+1]);
			ans+=min(ra,rb);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
