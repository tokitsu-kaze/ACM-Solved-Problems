#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int sgn(double x)
{  
	if(fabs(x)<eps) return 0;
	else return x>0?1:-1;  
}
struct Point
{  
	double x,y;
	Point(){}
	Point(double a,double b)
	{
		x=a;
		y=b;
	}
	void input()
	{
		scanf("%lf%lf",&x,&y);
	}
};
typedef Point Vector;
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}
bool operator ==(Point a,Point b){return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;}
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}
double length(Vector a){return sqrt(dot(a,a));}
struct Circle  
{  
    Point c;  
    double r;  
    Circle(){}  
    Circle(Point a,double b)
    {
		c=a;
		r=b;
	}
}; 
bool OnCircle(Point x,Circle c){return sgn(c.r-length(c.c-x))==0;}
int getCircleInter(Circle c1,Circle c2,Point *sol)
{
	double r1,r2,x1,y1,x2,y2,d;
	r1=c1.r;
	r2=c2.r;
	x1=c1.c.x;
	y1=c1.c.y;
	x2=c2.c.x;
	y2=c2.c.y;
	d=length(c1.c-c2.c);
	if(sgn(fabs(r1-r2)-d)>0) return -1;
	if(sgn(r1+r2-d)<0) return 0;
	double a,b,c,p,q,r;
	a=r1*(x1-x2)*2;
	b=r1*(y1-y2)*2;
	c=r2*r2-r1*r1-d*d;
	p=a*a+b*b;
	q=-a*c*2;
	r=c*c-b*b;
    double cosa,sina,cosb,sinb; 
	if(sgn(d-(r1+r2))== 0||sgn(d-fabs(r1-r2))==0)
	{
		cosa=-q/p/2;
		sina=sqrt(1-cosa*cosa);
		Point p(x1+c1.r*cosa,y1+c1.r*sina);
		if(!OnCircle(p,c2)) p.y=y1-c1.r*sina;
		sol[0]=p;
		return 1;
    }
	double delta=sqrt(q*q-p*r*4);
	cosa=(delta-q)/p/2;
	cosb=(-delta-q)/p/2;
	sina=sqrt(1-cosa*cosa);
	sinb=sqrt(1-cosb*cosb);
	Point p1(x1+c1.r*cosa,y1+c1.r*sina);
	Point p2(x1+c1.r*cosb,y1+c1.r*sinb);
	if(!OnCircle(p1,c2)) p1.y=y1-c1.r*sina;
	if(!OnCircle(p2,c2)) p2.y=y1-c1.r*sinb;
	if(p1==p2) p1.y=y1-c1.r*sina;
	sol[0]=p1;
	sol[1]=p2;
	return 2;
}
int main()
{
	int cnt;
	Point res[5],a,b;
	double r1,r2;
	Circle c,d;
	a.input();
	b.input();
	scanf("%lf",&r1);
	r2=dist(a,b);
	if(sgn(2*r2-r1)<=0||sgn(r1)==0) return 0*puts("NO");
	c=Circle(a,r1);
	d=Circle(b,r2);
	cnt=getCircleInter(c,d,res);
	if(cnt<=1) return 0*puts("NO");
	puts("YES");
	printf("%.10lf %.10lf %.10lf %.10lf\n",res[0].x,res[0].y,res[1].x,res[1].y);
	return 0;
}