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
const int MAX=1000+10;
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
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
Point OrthoCenter(Point a,Point b,Point c)
{  
    double c1,c2,d;
    Point p1,p2;
    p1=c-b;
    c1=0;
    p2=c-a;
    c2=dot(b-a,p2);
    d=cross(p1,p2);
    return Point(a.x+(c1*p2.y-c2*p1.y)/d,a.y+(p1.x*c2-p2.x*c1)/d);  
} int main()
{
	int t;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			Point a,b,c,res;
			a.input();
			b.input();
			c.input();
			res=OrthoCenter(a,b,c);
			printf("%.4lf %.4lf\n",res.x+eps,res.y+eps);
		}
	}
	return 0;
}