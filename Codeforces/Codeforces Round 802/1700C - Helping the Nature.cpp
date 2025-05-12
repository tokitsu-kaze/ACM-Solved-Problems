#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll a[MAX],d[MAX];
int main()
{
	int T,n,i;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		a[0]=a[n+1]=0;
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(i=1;i<=n+1;i++) d[i]=a[i]-a[i-1];
		ans=0;
		for(i=2;i<=n;i++)
		{
			ans+=abs(d[i]);
			if(d[i]>0) d[n+1]+=d[i];
			else if(d[i]<0) d[1]-=-d[i];
			d[i]=0;
		}
		if(d[1]>0)
		{
			// op 1
			ans+=d[1];
			d[n+1]+=d[1];
			d[1]=0;
		}
		else
		{
			// op 3
			ans+=-d[1];
			d[n+1]-=-d[1];
			d[1]=0;
		}
		assert(d[n+1]==0);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1. d[1]--,d[i]++
2. d[i]--,d[n+1]++
3. d[1]++,d[n+1]--
*/

