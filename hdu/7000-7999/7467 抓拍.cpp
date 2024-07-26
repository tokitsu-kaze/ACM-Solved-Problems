#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll x[MAX],y[MAX];
char dir[MAX][2];
int n;
ll cal(ll tm)
{
	int i;
	ll a,b,c,d,nx,ny;
	a=b=LLINF;
	c=d=-LLINF;
	for(i=1;i<=n;i++)
	{
		nx=x[i];
		ny=y[i];
		if(dir[i][0]=='E') nx+=tm;
		else if(dir[i][0]=='W') nx-=tm;
		else if(dir[i][0]=='S') ny-=tm;
		else ny+=tm;
		a=min(a,nx);
		b=min(b,ny);
		c=max(c,nx);
		d=max(d,ny);
	}
	return 2*((c-a)+(d-b));
}
int main()
{
	int i;
	ll l,r,lm,rm,tl,tr;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld%lld%s",&x[i],&y[i],dir[i]);
	l=0;
	r=1e12;
	while(l<r)  
	{  
		lm=l+(r-l)/3;
		rm=r-(r-l)/3;
		tl=cal(lm);
		tr=cal(rm);
		if(tl>tr) l=lm+1;
		else r=rm-1;
	}
	printf("%lld\n",cal(l));
	return 0;
}
