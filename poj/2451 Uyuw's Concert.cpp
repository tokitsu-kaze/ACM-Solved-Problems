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
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}
Vector operator +(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}
Vector operator *(Vector a,double p){return Vector(a.x*p,a.y*p);}
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
};
double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
Point PointOfLineInter(Line a,Line b)
{
	Vector u=a.p-b.p;
	double t=cross(b.v,u)/cross(a.v,b.v);
	return a.p+a.v*t;
}
bool OnLeft(Line l,Point p){return cross(l.v,p-l.p)>0;}
bool hpicmp(Line a,Line b){return a.ang<b.ang;}
vector<Point> hpi(vector<Line> l)
{
	int n,i;
	n=l.size();
	sort(l.begin(),l.end(),hpicmp);
	int first,last;
	vector<Point> p(n);
	vector<Line> q(n);
	vector<Point> ans;
	q[first=last=0]=l[0];
	for(i=1;i<n;i++)
	{
		while(first<last&&!OnLeft(l[i],p[last-1])) last--;
		while(first<last&&!OnLeft(l[i],p[first])) first++;
		q[++last]=l[i];
		if(fabs(cross(q[last].v,q[last-1].v))<eps)
		{
			last--;
			if(OnLeft(q[last],l[i].p)) q[last]=l[i];
		}
		if(first<last) p[last-1]=PointOfLineInter(q[last-1],q[last]);
	}
	while(first<last&&!OnLeft(q[first],p[last-1])) last--;
	if(last-first<=1) return ans;
	p[last]=PointOfLineInter(q[last],q[first]);
	for(i=first;i<=last;i++)
	{
		ans.push_back(p[i]);
	}
	return ans;
}
double PolygonArea(vector<Point> p)
{
	int n,i;
	double res=0;
	n=p.size();
	for(i=0;i<n;i++)
	{
		res+=cross(p[i],p[(i+1)%n]);
	}
	return fabs(res/2);
}
int main()
{
	int n,i;
	const double side=10000.0;
	while(~scanf("%d",&n))
	{
		Point a,b;
		Line t;
		vector<Line> l;
		for(i=0;i<n;i++)
		{
			a.input();
			b.input();
			t.twopoint(a,b);
			l.push_back(t);
		}
		t.twopoint(Point(0,0),Point(side,0));
		l.push_back(t);
		t.twopoint(Point(side,0),Point(side,side));
		l.push_back(t);
		t.twopoint(Point(side,side),Point(0,side));
		l.push_back(t);
		t.twopoint(Point(0,side),Point(0,0));
		l.push_back(t);
		vector<Point> res;
		res=hpi(l);
		printf("%.1lf\n",PolygonArea(res));
	}
	return 0;
}