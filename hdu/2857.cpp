////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-02 22:29:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2857
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1620KB
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
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=100000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
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
struct Line
{  
	Point p;
	Vector v;
	double ang;
	double a,b,c;
	Line(){}
	Line(Point a,Vector b)
	{
		p=a;
		v=b;
		ang=atan2(v.y,v.x);
		LineGeneralEquation();
	}
	void twopoint(Point a,Point b)
	{
		p=a;
		v=b-a;
		ang=atan2(v.y,v.x);
		LineGeneralEquation();
	}
	void LineGeneralEquation()
	{
		Point p1,p2;
		p1=p;
		p2=p+v;
		a=p2.y-p1.y;  
		b=p1.x-p2.x;  
		c=-a*p1.x-b*p1.y;
	}
};
Point PointSymmetryLine(Point p,Line l)
{
	Point res;
	double k,a,b,c;
	a=l.a;
	b=l.b;
	c=l.c;
	k=-2*(a*p.x+b*p.y+c)/(a*a+b*b);
	res.x=p.x+k*a;
	res.y=p.y+k*b;
	return res;
}
double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
Point PointOfLineInter(Line a,Line b)
{
	Vector u=a.p-b.p;
	double t=cross(b.v,u)/cross(a.v,b.v);
	return a.p+a.v*t;
}
int main()
{
	int t;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			Point a,b,c,d,ans;
			Line l1,l2;
			a.input();
			b.input();
			l1.twopoint(a,b);
			c.input();
			c=PointSymmetryLine(c,l1);
			d.input();
			l2.twopoint(c,d);
			ans=PointOfLineInter(l1,l2);
			printf("%.3lf %.3lf\n",ans.x,ans.y);
		}
	}
	return 0;
}