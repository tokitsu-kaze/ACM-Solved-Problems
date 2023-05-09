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
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=50000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int sgn(int x)
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
Vector operator +(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}
double dot(Vector a,Vector b)
{
	return a.x*b.x+a.y*b.y;
}
double cross(Vector a,Vector b)
{
	return a.x*b.y-a.y*b.x;
}
struct Line
{
	Point p;
	Vector v;
	double ang;
	Line(){}
	Line(Point a,Point b)
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
};
bool SegInter(Point a,Point b,Point c,Point d)
{
	double t1,t2,t3,t4;
	t1=cross(b-a,c-a);
	t2=cross(b-a,d-a);
	t3=cross(d-c,a-c);
	t4=cross(d-c,b-c);
	return sgn(t1)*sgn(t2)<0&&sgn(t3)*sgn(t4)<0;
}
bool OnSeg(Point p,Point p1,Point p2)
{
	return sgn(cross(p1-p,p2-p))==0&&sgn(dot(p1-p,p2-p))<=0;
}
int main()
{
	int t,flag;
	double x1,y1,x2,y2;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			Point a,b,c,d,e,f;
			Line l,l1;
			e.input();
			f.input();
			if(e.x>f.x) swap(e,f);
			else if(e.x==f.x)
			{
				if(e.y>f.y) swap(e,f);
			}
			l.twopoint(e,f);
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			a=Point(min(x1,x2),min(y1,y2));
			b=Point(min(x1,x2),max(y1,y2));
			c=Point(max(x1,x2),max(y1,y2));
			d=Point(max(x1,x2),min(y1,y2));
			if(((e.x>=min(x1,x2)&&e.x<=max(x1,x2))&&(e.y>=min(y1,y2)&&e.y<=max(y1,y2)))
			||((f.x>=min(x1,x2)&&f.x<=max(x1,x2))&&(f.y>=min(y1,y2)&&f.y<=max(y1,y2))))
			{
				puts("T");
				continue;
			}
			flag=0;
			if(SegInter(l.p,l.v+l.p,a,b)||OnSeg(l.p,a,b)||OnSeg(l.v+l.p,a,b)||OnSeg(a,l.p,l.p+l.v)||OnSeg(b,l.p,l.p+l.v)) flag=1;
			if(SegInter(l.p,l.v+l.p,b,c)||OnSeg(l.p,b,c)||OnSeg(l.v+l.p,b,c)||OnSeg(b,l.p,l.p+l.v)||OnSeg(c,l.p,l.p+l.v)) flag=1;
			if(SegInter(l.p,l.v+l.p,c,d)||OnSeg(l.p,c,d)||OnSeg(l.v+l.p,c,d)||OnSeg(c,l.p,l.p+l.v)||OnSeg(d,l.p,l.p+l.v)) flag=1;
			if(SegInter(l.p,l.v+l.p,d,a)||OnSeg(l.p,d,a)||OnSeg(l.v+l.p,d,a)||OnSeg(d,l.p,l.p+l.v)||OnSeg(a,l.p,l.p+l.v)) flag=1;
			if(flag) puts("T");
			else puts("F");
		}
	}
	return 0;
} 