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
const double eps=1e-8;
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
double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}
double fgcd(double x,double y)
{
	return y<1e-2?x:fgcd(y,fmod(x,y));
}
int main()
{
	double a,b,c,p,s,r,g;
	double a1,a2,a3;
	Point p1,p2,p3;
	while(~scanf("%lf%lf",&p1.x,&p1.y))
	{
		p2.input();
		p3.input();
		a=dist(p1,p2);
		b=dist(p1,p3);
		c=dist(p2,p3);
		p=(a+b+c)/2;
		s=sqrt(p*(p-a)*(p-b)*(p-c));
		r=a*b*c/4/s;
		a1=acos(1-a*a/(2*r*r));
		a2=acos(1-b*b/(2*r*r));
		a3=2*PI-a1-a2;
		g=fgcd(a1,fgcd(a2,a3));
		printf("%.6lf\n",r*r*sin(g)*PI/g);
	}
	return 0;
}