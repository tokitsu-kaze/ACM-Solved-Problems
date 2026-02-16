#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int mod=1e9+7;
int n,d,a,b,v[MAX];
ll cal(int x)
{
	int i;
	ll sum=0;
	for(i=1;i<=a;i++)
	{
		if(v[i]+d>=x) sum+=min(d,v[i]+d-x);
	}
	return sum;
}
int ck(int x)
{
	return cal(x)>=1LL*b*d;
}
int main()
{
	int i,l,r,mid;
	ll ans,tmp;
	scanf("%d%d",&n,&d);
	scanf("%d%d",&a,&b);
	for(i=1;i<=n;i++) scanf("%d",&v[i]);
	sort(v+1,v+1+n);
	reverse(v+1,v+1+n);
	l=0;
	r=v[1]+d;
	while(l<r)
	{
		mid=(0LL+l+r)>>1;
		if(ck(mid+1)) l=mid+1;
		else r=mid;
	}
	tmp=cal(l)-1LL*d*b;
	for(i=1;i<=a;i++)
	{
		if(v[i]>=l) continue;
		if(v[i]+d<=l) v[i]+=d;
		else
		{
			if(tmp>0)
			{
				tmp--;
				v[i]=l+1;
			}
			else v[i]=l;
		}
	}
	ans=0;
	for(i=1;i<=n;i++) ans=(ans+1LL*v[i]*v[i])%mod;
	printf("%lld\n",ans);
	return 0;
}

