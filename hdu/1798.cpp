////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-06-10 11:31:28
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1798
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1728KB
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
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}
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
double AreaOfCircleInterCircle(Circle c1,Circle c2)
{
	double d=dist(c1.c,c2.c);//计算圆心距
	if(sgn(d-(c1.r+c2.r))>=0||sgn(c1.r)==0||sgn(c2.r)==0) return 0;//相离、外切或有一圆半径为0
	else if(sgn(d-fabs(c1.r-c2.r))<=0)//内切或内含
	{  
		double r=min(c1.r,c2.r);
		return r*r*PI;  
	} 
	else//相交
	{
		double a,b,m,n,x,y;
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
	Circle c1,c2;
	Point p;
	double r;
	while(~scanf("%lf%lf%lf",&p.x,&p.y,&r))
	{
		c1=Circle(p,r);
		p.input();
		scanf("%lf",&r);
		c2=Circle(p,r);
		printf("%.3lf\n",AreaOfCircleInterCircle(c1,c2));
	}
	return 0;
}