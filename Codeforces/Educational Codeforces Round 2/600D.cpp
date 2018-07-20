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
const long double PI=acos(-1.0);
const long double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
int sgn(long double x)
{  
	if(fabs(x)<eps) return 0;
	else return x>0?1:-1;  
}
struct Point
{  
	long double x,y;
	Point(){}
	Point(long double a,long double b)
	{
		x=a;
		y=b;
	}
	void input()
	{
		cin>>x>>y;
	}
};
typedef Point Vector;
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}
long double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
long double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}
struct Circle  
{  
    Point c;  
    long double r;  
    Circle(){}  
    Circle(Point a,long double b)
    {
		c=a;
		r=b;
	}
};
double CircleCircleArea(Circle c1,Circle c2)
{
	long double d=dist(c1.c,c2.c);
	if(sgn(d-(c1.r+c2.r))>=0||sgn(c1.r)==0||sgn(c2.r)==0) return 0;
	else if(sgn(d-fabs(c1.r-c2.r))<=0)
	{  
		long double r=min(c1.r,c2.r);
		return r*r*PI;  
	} 
	else
	{
		long double a,b,m,n,x,y;
		a=acos((d*d+c1.r*c1.r-c2.r*c2.r)/(2*d*c1.r));  
		b=acos((d*d+c2.r*c2.r-c1.r*c1.r)/(2*d*c2.r));  
		m=a*c1.r*c1.r;  
		n=b*c2.r*c2.r;
		x=c1.r*c1.r*sin(a)*cos(a);  
		y=c2.r*c2.r*sin(b)*cos(b);  
		return m+n-(x+y);  
	}
}
int main()
{
	long double r;
	Point p;
	Circle c1,c2;
	p.input();
	cin>>r;
	c1=Circle(p,r);
	p.input();
	cin>>r;
	c2=Circle(p,r);
	printf("%.20f\n",CircleCircleArea(c1,c2));
	return 0;
}