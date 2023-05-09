#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	ll g,t;
	g=exgcd(b,a%b,x,y);
	t=x;
	x=y;
	y=t-a/b*y;
	return g;
}
ll linear_equation(ll a,ll b,ll c,ll &x,ll &y)
{
	ll g,t;
	g=exgcd(a,b,x,y);
	if(!c) x=y=0;
	else if((!a&&!b&&c)||c%g) return -1;//no solution 
	else if(!a&&b) x=1,y=c/b;
	else if(a&&!b) x=c/a,y=-c/a;
	else
	{
		a/=g,b/=g,c/=g;
		x*=c,y*=c;
		t=x;
		x%=b;
		if(x<=0) x+=b;
		ll k=(t-x)/b;
		y+=k*a;
	}
	return g;
}
int main()
{
	ll x,y,m,n,L,g,a,b,c,ra,rb;
	scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&L);
	a=m-n;
	b=L;
	c=y-x;
	if(a<0) a=-a,c=-c;
	g=linear_equation(a,b,c,ra,rb);
	if(g==-1) puts("Impossible");
	else printf("%lld\n",ra);
	return 0;
}
