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
const int MAX=100+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
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
Vector operator -(Point a,Point b){return Vector(a.x-b.x,a.y-b.y);}  
Vector operator *(Vector a,double p){return Vector(a.x*p,a.y*p);}  
Vector operator /(Vector a,double p){return Vector(a.x/p,a.y/p);}
bool operator <(Point a,Point b)
{  
  return a.x<b.x||(a.x==b.x&&a.y<b.y);  
}
bool operator ==(Point a,Point b)
{  
  return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;  
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
	void twopoint(Point a,Point b)
	{
		p=a;
		v=b-a;
		ang=atan2(v.y,v.x);
	}
};
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
int judgeLineInter(Line a,Line b)
{
	if(sgn(cross(a.v,b.v))==0)
	{
		if(sgn(cross(a.p-b.p,b.v))==0) return 0;
		else return 1;
	}
	else return 2;
}
Point PointOfLineInter(Line a,Line b)
{
	Vector u=a.p-b.p;
	double t=cross(b.v,u)/cross(a.v,b.v);
	return a.p+a.v*t;
}
int main()
{
	int n,i,t;
	Point a,b,c,d,ans;
	Line e,f;
	while(~scanf("%d",&n))
	{
		puts("INTERSECTING LINES OUTPUT");
		for(i=0;i<n;i++)
		{
			a.input();
			b.input();
			c.input();
			d.input();
			e.twopoint(a,b);
			f.twopoint(c,d);
			t=judgeLineInter(e,f);
			if(t==0) puts("LINE");
			else if(t==1) puts("NONE");
			else
			{
				ans=PointOfLineInter(e,f);
				printf("POINT %.2f %.2f\n",ans.x,ans.y); 
			}
		}
		puts("END OF OUTPUT");
	}
	return 0;
}
