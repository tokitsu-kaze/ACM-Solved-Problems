#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int n,a[MAX],mx;
ll sum;
int ck(ll x)
{
	int i,ok,cnt;
	ok=1;
	cnt=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]==mx)
		{
			if(ok)
			{
				ok=0;
				if(2LL*(a[i]+x)*n<sum+x) cnt++;
				continue;
			}
		}
		if(2LL*a[i]*n<sum+x) cnt++;
	}
	return cnt*2>n;
}
int main()
{
	int T,i;
	ll l,r,mid;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		sum=mx=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
			mx=max(mx,a[i]);
		}
		l=0;
		r=1e18;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid)) r=mid;
			else l=mid+1;
		}
		if(ck(l)) printf("%lld\n",l);
		else puts("-1");
	}
	return 0;
}
