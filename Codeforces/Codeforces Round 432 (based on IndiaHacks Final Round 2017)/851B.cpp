#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=10007;
int sgn(ll x)
{  
	if(fabs(x)<eps) return 0;
	else return x>0?1:-1;  
}
struct Point
{  
	ll x,y;
	Point(){}
	Point(ll a,ll b)
	{
		x=a;
		y=b;
	}
};
typedef Point Vector;
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}  
ll dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
ll dist(Point a,Point b){return dot(a-b,a-b);}
ll cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
bool OnSeg(Point p,Point p1,Point p2)
{  
	return sgn(cross(p1-p,p2-p))==0&&sgn(dot(p1-p,p2-p))<0;
}
int main()
{
	Point a,b,c;
	ll d1,d2;
	while(~scanf("%lld%lld%lld%lld%lld%lld",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y))
	{
		if(OnSeg(b,a,c))
		{
			puts("No");
			continue;
		}
		d1=dist(a,b);
		d2=dist(b,c);
		if(d1==d2) puts("Yes");
		else puts("No");
	}
	return 0;
}