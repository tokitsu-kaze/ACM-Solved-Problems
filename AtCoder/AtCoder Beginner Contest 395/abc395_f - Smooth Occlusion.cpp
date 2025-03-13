#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int mod=998244353;
const int MAX=2e5+10;
int n;
ll x,u[MAX],d[MAX];
ll ck(ll h)
{
	int i;
	ll pl,pr,tl,tr,tmp,res,l,r;
	pl=0;
	pr=2e9;
	res=0;
	for(i=1;i<=n;i++)
	{
		tmp=u[i]+d[i]-h;
		res+=tmp;
		if(tmp>d[i]) tl=tmp-d[i];
		else tl=0;
		tr=min(u[i],u[i]+d[i]-h);
		l=u[i]-tr;
		r=u[i]-tl;
		pl=max(pl-x,l);
		pr=min(pr+x,r);
		if(pl>pr) return LLINF;
	}
	return res;
}
int main()
{
	int i;
	ll l,r,mid;
	scanf("%d%lld",&n,&x);
	for(i=1;i<=n;i++) scanf("%lld%lld",&u[i],&d[i]);
	l=0;
	r=2e9;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid)<=ck(mid+1)) r=mid;
		else l=mid+1;
	}
	printf("%lld\n",ck(l));
	return 0;
}
/*
u+d>h
tmp=u+d-h
if(tmp>d) l=tmp-d;
else l=0;
r=min(u,u+d-h);
u-r,u-l

u-r-x,u-l+x

upre-x<=?<=upre+x
*/
