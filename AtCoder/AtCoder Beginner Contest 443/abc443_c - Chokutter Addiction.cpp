#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
ll a[MAX];
int main()
{
	int n,i;
	ll ans,now,t;
	scanf("%d%lld",&n,&t);
	a[0]=0;
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	now=ans=0;
	for(i=1;i<=n;i++)
	{
		if(now<=a[i])
		{
			ans+=a[i]-now;
			now=a[i]+100;
		}
	}
	ans+=max(0LL,t-now);
	printf("%lld\n",ans);
	return 0;
}
