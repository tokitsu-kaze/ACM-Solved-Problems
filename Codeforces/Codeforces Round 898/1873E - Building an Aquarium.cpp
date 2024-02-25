#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int a[MAX],n,x;
int ck(ll now)
{
	int i;
	ll res=0;
	for(i=1;i<=n;i++)
	{
		res+=max(0ll,now-a[i]);
		if(res>x) return 0;
	}
	return res<=x;
}
int main()
{
	int t,i;
	ll l,r,mid;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&x);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		l=1;
		r=2e14;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid+1)) l=mid+1;
			else r=mid;
		}
		printf("%lld\n",l);
	}
	return 0;
}
