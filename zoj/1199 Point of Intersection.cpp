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
double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
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
	Point getpoint(double a)
	{  
        return Point(c.x+cos(a)*r, c.y+sin(a)*r);  
	}  
};
int JudgeLineInter(Line a,Line b)
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
int CommonTangents(Circle c1,Circle c2, Point* a, Point* b)  
{  
	int cnt=0;  
	if(c1.r<c2.r)
	{
		swap(c1,c2);
		swap(a,b);
	}
	int d=(c1.c.x-c2.c.x)*(c1.c.x-c2.c.x)+(c1.c.y-c2.c.y)*(c1.c.y-c2.c.y);  
	int rd=c1.r-c2.r;  
	int rs=c1.r+c2.r;  
	if(d<rd*rd) return 0; //内含 
    double base=atan2(c2.c.y-c1.c.y,c2.c.x-c1.c.x);  
	if(d==0&&sgn(c1.r-c2.r)==0) return -1;//无线多条切线  
	if(d==rd*rd)//内切, 1条切线  
    {
		a[cnt]=c1.getpoint(base);
		b[cnt]=c2.getpoint(base);
		cnt++;  
		return 1;  
    }  
    //有外公切线  
	double ang=acos((c1.r-c2.r)/sqrt(d));  
	a[cnt]=c1.getpoint(base+ang);
	b[cnt]=c2.getpoint(base+ang);
	cnt++;  
	a[cnt]=c1.getpoint(base-ang);
	b[cnt]=c2.getpoint(base-ang);
	cnt++;  
/*	if(d==rs*rs)//一条内公切线  
	{  
		a[cnt]=c1.getpoint(base);
		b[cnt]=c2.getpoint(PI+base);
		cnt++;  
	}  
	else if(d>rs*rs)//两条内公切线  
	{  
		double ang=acos((c1.r+c2.r)/sqrt(d));  
		a[cnt]=c1.getpoint(base+ang);
		b[cnt]=c2.getpoint(PI+base+ang);
		cnt++;  
		a[cnt]=c1.getpoint(base-ang);
		b[cnt]=c2.getpoint(PI+base-ang);
		cnt++;  
	}  */
	//本题不考虑内公切线 
	return cnt;  
}
int main()
{
	int t;
	double r;
	Circle c1,c2;
	Point p,a[11],b[11];
	scanf("%d",&t);
	while(t--)
	{
		p.input();
		scanf("%lf",&r);
		c1=Circle(p,r);
		p.input();
		scanf("%lf",&r);
		c2=Circle(p,r);
		int res=CommonTangents(c1,c2,a,b);
		if(res<2) puts("Impossible.");
		else
		{
			Line l1,l2;
			l1.twopoint(a[0],b[0]);
			l2.twopoint(a[1],b[1]);
			if(JudgeLineInter(l1,l2)==2)
			{
				p=PointOfLineInter(l1,l2);
				printf("%.2lf %.2lf\n",p.x,p.y);
			}
			else puts("Impossible.");
		}
	}
	return 0;
}