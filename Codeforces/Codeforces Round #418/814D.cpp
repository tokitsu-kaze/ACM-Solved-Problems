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
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-9;
const int MAX=1000000+10;
const ll mod=10000;
int sgn(double x)
{
	if(fabs(x)<eps) return 0;
	return x>0?1:-1;
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
bool operator ==(Point a,Point b){return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;}
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double length(Vector a){return sqrt(dot(a,a));}
double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}
struct Circle  
{  
    Point c;  
    double r,s;
    Circle(){}  
    Circle(Point a,double b)
    {
		c=a;
		r=b;
		s=PI*r*r;
	}
}a[1111];
int check(Circle a,Circle b)
{
	if(a.r>b.r) return 0;
	if(sgn(dist(a.c,b.c)-a.r-b.r)>=0) return 0;
	return 1;
}
int main()
{
	int n,i,j,cnt;
	Point p;
	double r,ans;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			p.input();
			scanf("%lf",&r);
			a[i]=Circle(p,r);
		}
		ans=0;
		for(i=0;i<n;i++)
		{
			cnt=0;
			for(j=0;j<n;j++)
			{
				if(i!=j)
				{
					if(check(a[i],a[j])) cnt++;
				}
			}
			if(cnt<=1||cnt%2) ans+=a[i].s;
			else ans-=a[i].s;
		}
		printf("%.8lf\n",ans);
	}
	return 0;
}