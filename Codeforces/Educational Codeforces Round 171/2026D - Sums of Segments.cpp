#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
int a[MAX],n;
ll sum[MAX],bit[MAX],suma[MAX],suf[MAX],cnt[MAX];
ll cal(ll x)
{
	int l,r,mid;
	ll res;
	l=0;
	r=n;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(cnt[mid+1]<=x) l=mid+1;
		else r=mid;
	}
	res=bit[l];
	x-=cnt[l];
	// s(l+1,l+1) s(l+1,l+2), ...,s(l+1,l+x)
	if(x>0) res+=(bit[l+1]-bit[l])-1LL*(n-(l+x))*(suma[l+x]-suma[l])-suf[l+x+1];
	return res;
}
int main()
{
	int T,i,q;
	ll ans,l,r;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=0;i<=n;i++) sum[i]=0;
	for(i=1;i<=n;i++)
	{
		sum[1]+=1LL*(n-i+1)*a[i];
		sum[i+1]-=1LL*(n-i+1)*a[i];
	}
	for(i=2;i<=n;i++) sum[i]+=sum[i-1];
	bit[0]=0;
	for(i=1;i<=n;i++) bit[i]=bit[i-1]+sum[i];
	suma[0]=0;
	for(i=1;i<=n;i++) suma[i]=suma[i-1]+a[i];
	suf[n+1]=0;
	for(i=n;i;i--) suf[i]=suf[i+1]+1LL*(n-i+1)*a[i];
	cnt[0]=0;
	for(i=1;i<=n;i++) cnt[i]=cnt[i-1]+n-i+1;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",cal(r)-cal(l-1));
	}
	return 0;
}

