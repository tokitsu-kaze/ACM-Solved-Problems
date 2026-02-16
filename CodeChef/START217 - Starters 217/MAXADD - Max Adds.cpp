#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll a[MAX],b[MAX];
ll cal(ll l,ll r)
{
	return (l+r)*(r-l+1)/2;
}
int main()
{
	int T,n,m,i;
	ll l,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(i=1;i<=n;i++) scanf("%lld",&b[i]);
		l=1;
		r=m;
		for(i=1;i<=n;i++)
		{
			l=max(l+b[i],a[i]);
			r=max(r+b[i],a[i]);
		}
		printf("%lld\n",cal(l,r)+l*(m-(r-l+1)));
	}
	return 0;
}
/*
维护[l,r] 中间一定是值域连续一段，剩下的都是l 
*/
