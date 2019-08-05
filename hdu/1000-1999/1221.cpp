////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-06-10 18:41:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1221
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1716KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <ctime>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=100000+10;
const ll mod=10000;
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
Vector operator +(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}
Vector operator *(Vector a,double p){return Vector(a.x*p,a.y*p);}
Vector operator /(Vector a,double p){return Vector(a.x/p,a.y/p);}
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double length(Vector a){return sqrt(dot(a,a));}
double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
Vector Normal(Vector x){return Point(-x.y,x.x)/length(x);}
Vector vecunit(Vector x){return x/length(x);}
struct Line
{  
	Point p;
	Vector v; 
	double ang;
	Line(){}
	Line(Point a,Vector b)
	{
		p=a;
		v=b;
		ang=atan2(v.y,v.x);
	}
	void twopoint(Point a,Point b)
	{
		p=a;
		v=b-a;
		ang=atan2(v.y,v.x);
	}
	Point getpoint(double a)
	{  
		return p+(v*a);  
	}
};
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
Point PointOfLineInter(Line a,Line b)
{
	Vector u=a.p-b.p;
	double t=cross(b.v,u)/cross(a.v,b.v);
	return a.p+a.v*t;
}
bool OnSeg(Point p, Point p1, Point p2)
{  
	return sgn(cross(p1-p,p2-p))==0&&sgn(dot(p1-p,p2-p))<=0;
}
int getSegCircleInter(Line l,Circle c)//线段与圆的交点
{  
	Point sol[2];
	Vector nor=Normal(l.v);
	Line l1=Line(c.c,nor);  
	Point p1=PointOfLineInter(l1,l);  
	double d=length(p1-c.c);  
    if(sgn(d-c.r)>0) return 0;
	Point p2=vecunit(l.v)*sqrt(c.r*c.r-d*d);  
	int res=0;  
	sol[res]=p1+p2;  
    if(OnSeg(sol[res],l.p,l.getpoint(1))) res++;
	sol[res]=p1-p2;
	if(OnSeg(sol[res],l.p,l.getpoint(1))) res++;  
	return res;  
}
int main()
{
	int t;
	double r;
	Point p1,p2;
	Line l1,l2,l3,l4;
	Circle c;
	scanf("%d",&t);
	while(t--)
	{
		p1.input();
		scanf("%lf",&r);
		c=Circle(p1,r);
		p1.input();
		p2.input();
		l1.twopoint(p1,Point(p2.x,p1.y));
		l2.twopoint(p1,Point(p1.x,p2.y));
		l3.twopoint(p2,Point(p2.x,p1.y));
		l4.twopoint(p2,Point(p1.x,p2.y));
		if(getSegCircleInter(l1,c)||getSegCircleInter(l2,c)||getSegCircleInter(l3,c)||getSegCircleInter(l4,c)) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
1111
0 0 2 -1 0 1 1
*/