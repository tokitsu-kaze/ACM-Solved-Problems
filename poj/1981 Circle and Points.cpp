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
Point midseg(Point a, Point b){return (a+b)/2;}
double VectorAngle(Vector v){return atan2(v.y,v.x);}
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
Circle GetCircle(Point p1,Point p2,double r)
{ 
	Circle res;
    Point mid=midseg(p1,p2);  
    double angle=atan2(p1.x-p2.x,p2.y-p1.y);
    double d=sqrt(r*r-dist(p1,mid)*dist(p1,mid));  
    res=Circle(Point(mid.x+d*cos(angle),mid.y+d*sin(angle)),r);
    return res;
}
int main()
{
	int t,n,i,j,k,ans;
	Point p[311];
	while(~scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
		{
			p[i].input();
		}
		ans=1;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(sgn(dist(p[i],p[j])-2)>0) continue;
				Circle c=GetCircle(p[i],p[j],1);
				int cnt=0;
				for(k=0;k<n;k++)
				{
					if(sgn(1-dist(p[k],c.c))>=0) cnt++;
				}
				ans=max(ans,cnt);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}