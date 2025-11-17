#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int h[MAX],n,mx;
ll nd[MAX];
int ck(ll x,ll tar)
{
	int i;
	ll cntev,cntod,tmp;
	cntev=x/2;
	cntod=x-x/2;
	for(i=1;i<=n;i++) nd[i]=tar-h[i];
	for(i=1;i<=n;i++)
	{
		tmp=min(nd[i]/2,cntev);
		nd[i]-=tmp*2;
		cntev-=tmp;
	}
	for(i=1;i<=n;i++)
	{
		tmp=min(nd[i],cntod);
		nd[i]-=tmp;
		cntod-=tmp;
	}
	for(i=1;i<=n;i++)
	{
		if(nd[i]>0) return 0;
	}
	return 1;
}
int main()
{
	int T,i;
	ll l,r,mid;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		mx=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&h[i]);
			mx=max(mx,h[i]);
		}
		l=0;
		r=3e14;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid,mx)||ck(mid,mx+1)||ck(mid,mx+2)) r=mid;
			else l=mid+1;
		}
		printf("%lld\n",l);
	}
	return 0;
}
