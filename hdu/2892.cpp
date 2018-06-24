////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-06-10 18:06:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2892
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:3288KB
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
const double eps=1e-9;
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
bool operator <(Point a,Point b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double length(Vector a){return sqrt(dot(a,a));}
Vector Normal(Vector x){return Point(-x.y,x.x)/length(x);}
Vector vecunit(Vector x){return x/length(x);}
double getangle(Vector v){return atan2(v.y, v.x);}
bool OnSeg(Point p, Point p1, Point p2)
{  
	return sgn(cross(p1-p,p2-p))==0&&sgn(dot(p1-p,p2-p))<0;
}
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
bool InCircle(Point x,Circle c){return sgn(c.r-length(c.c-x))>=0;}
int getSegCircleInter(Line l,Circle c,Point *sol)  
{  
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
double SegCircleArea(Circle c,Point a,Point b)
{  
	double a1=getangle(a-c.c);  
	double a2=getangle(b-c.c);  
	double da=fabs(a1-a2);  
	if (sgn(da-PI)>0) da=PI*2.0-da;  
	return sgn(cross(b-c.c,a-c.c))*da*c.r*c.r/2.0;  
}
double PolyCiclrArea(Circle c,Point *p,int n)
{  
	double res=0;  
	Point sol[2];  
	p[n]=p[0];  
	for(int i=0;i<n;i++)
	{
		double t1,t2;  
		int cnt=getSegCircleInter(Line(p[i],p[i+1]-p[i]),c,sol);  
		if(cnt==0)  
		{  
			if(!InCircle(p[i],c)||!InCircle(p[i+1],c)) res+=SegCircleArea(c,p[i],p[i+1]);  
			else res+=cross(p[i+1]-c.c,p[i]-c.c)/2.0;  
		}  
		if(cnt==1)  
		{  
			if(InCircle(p[i],c)&&!InCircle(p[i+1],c))
			{
				res+=cross(sol[0]-c.c,p[i]-c.c)/2.0;
				res+=SegCircleArea(c,sol[0],p[i+1]);  
			}
			else
			{
				res+=SegCircleArea(c,p[i],sol[0]);
				res+=cross(p[i+1]-c.c,sol[0]-c.c)/2.0;  
			}
		}  
		if(cnt==2)  
		{  
			if((p[i]<p[i+1])^(sol[0]<sol[1])) swap(sol[0],sol[1]);  
			res+=SegCircleArea(c,p[i],sol[0]);  
			res+=cross(sol[1]-c.c,sol[0]-c.c)/2.0;  
			res+=SegCircleArea(c,sol[1],p[i+1]);  
		}  
	}  
	return fabs(res);  
}
int main()
{
	Point t,p[MAX];
	Circle c;
	int n,i;
	double x,y,h,x1,y1,r;
	while(~scanf("%lf%lf%lf",&x,&y,&h))
	{
		scanf("%lf%lf%lf",&x1,&y1,&r);
		h=sqrt(2*h/10);
		t=Point(h*x1+x,h*y1+y);
		c=Circle(t,r);
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			p[i].input();
		}
		printf("%.2lf\n",PolyCiclrArea(c,p,n));
	}
	return 0;
}