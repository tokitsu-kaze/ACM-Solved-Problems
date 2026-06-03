#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int n;
ll a[MAX],k;
int ck(ll tar)
{
	int i;
	ll res=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]>=tar) continue;
		res+=(tar-a[i]+i-1)/i;
		if(res>k) return 0;
	}
	return res<=k;
}
int main()
{
	int i;
	ll l,r,mid;
	scanf("%d%lld",&n,&k);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	l=0;
	r=2e18;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid+1)) l=mid+1;
		else r=mid;
	}
	printf("%lld\n",l);
	return 0;
}
