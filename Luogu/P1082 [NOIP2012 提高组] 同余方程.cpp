#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
const ll mod=19260817;
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
/*
xa+yb=gcd(a,b)

get x,y
x1=x+b/gcd(a,b)*t
y1=y-a/gcd(a,b)*t
t is any integer
*/
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
		if(x<=0) x+=b;//or x<0
		ll k=(t-x)/b;
		y+=k*a;
	}
	return g;
}
/*
xa+yb=c

get x,y and x>0 is min
have solution: c%gcd(a,b)==0
*/

int main()
{
	ll a,b,x,y;
	scanf("%lld%lld",&a,&b);
	linear_equation(a,b,1,x,y);
	printf("%lld\n",x);
	return 0;
}
