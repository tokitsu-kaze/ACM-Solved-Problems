#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],n;
ll h;
int ck(ll k)
{
	int i;
	ll res,pre;
	pre=a[1];
	res=0;
	for(i=2;i<=n;i++)
	{
		res+=min(a[i-1]+k,1LL*a[i])-pre;
		pre=a[i];
	}
	res+=k;
	return res>=h;
}
int main()
{
	int T,i;
	ll l,r,mid;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld",&n,&h);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		n=unique(a+1,a+1+n)-a-1;
		l=1;
		r=1e18;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid)) r=mid;
			else l=mid+1;
		}
		printf("%lld\n",l);
	}
	return 0;
}
