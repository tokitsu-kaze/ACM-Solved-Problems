#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e5+10;
const int mod=1e9;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	ll g,tmp;
	g=exgcd(b,a%b,x,y);
	tmp=x;
	x=y;
	y=tmp-a/b*y;
	return g;
}
ll linear_equation(ll a,ll b,ll c,ll &x,ll &y)
{
	ll g,dx,dy,t;
	g=exgcd(a,b,x,y);
	if(a==0&&b==0)
	{
		if(c) return -1;
		x=y=0;
		return g;
	}
	if(c%g) return -1; //no solution
	dx=b/g,dy=-a/g;
	x*=c/g,y*=c/g;
	t=(x%dx-x)/dx;
	if(x+dx*t<=0) t++;
	x+=dx*t,y+=dy*t;
	return g;
}
/*
xa+yb=c

get x,y and x>0 is min
have solution: c%gcd(a,b)==0
x=x0+dx*t
y=y0-dy*t
*/
int main()
{
	int T;
	ll x,y,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&a,&b);
		a%=mod;
		b%=mod;
		x=y=0;
		if(linear_equation(a,mod,mod-b,x,y)==-1) puts("-1");
		else printf("%lld\n",x);
	}
	return 0;
}
