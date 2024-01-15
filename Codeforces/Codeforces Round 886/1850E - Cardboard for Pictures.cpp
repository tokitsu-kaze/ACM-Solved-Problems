#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
ll sqr(ll x){return x*x;}
ll a[MAX];
int ck(int n,ll x,ll c)
{
	ll res=0;
	for(int i=1;i<=n;i++)
	{
		res+=sqr(a[i]+x*2);
		if(res>c) return 0;
	}
	return res<=c;
}
int main()
{
	int t,n,i;
	ll c,l,r,mid;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&c);
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		l=0;
		r=5e8;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(n,mid+1,c)) l=mid+1;
			else r=mid;
		}
		printf("%lld\n",l);
	}
	return 0;
}
