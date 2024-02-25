#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
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
	
	ll g,dx,dy,t,mnx,mxx,mny,mxy;
	g=exgcd(a,b,x,y);
	if(c%g) return -1; //no solution
	dx=b/g,dy=-a/g;
	x*=c/g,y*=c/g;
	t=(x%dx-x)/dx;
	if(x+dx*t<=0) t++;
	x+=dx*t,y+=dy*t;
	mnx=x;
	mxy=y;
	t=(y%dy-y)/dy;
	if(y+dy*t<=0) t--;
	x+=dx*t,y+=dy*t;
	mny=y;
	mxx=x;
	if((mnx>0&&mxy>0)&&(mxx>0&&mny>0))
	{
		printf("%lld ",(mxx-mnx)/dx+1);
		printf("%lld %lld %lld %lld\n",mnx,mny,mxx,mxy);
	}
	else printf("%lld %lld\n",mnx,mny);
	return g;
}
int main()
{
	int t;
	ll a,b,c,x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		if(linear_equation(a,b,c,x,y)==-1) puts("-1");
	}
	return 0;
}

