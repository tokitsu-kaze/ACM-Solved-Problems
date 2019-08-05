////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-17 21:22:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1791
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1732KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=3e4+10;
const ll mod=1e9+7;
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
bool operator ==(Point a,Point b){return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;}
Vector operator +(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}  
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}  
Vector operator *(Vector a,double p){return Vector(a.x*p,a.y*p);}  
Vector operator /(Vector a,double p){return Vector(a.x/p,a.y/p);}
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double length(Vector a){return sqrt(dot(a,a));}
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
Circle CircumscribedCircle(Point p1,Point p2,Point p3)
{  
	double bx=p2.x-p1.x,by=p2.y-p1.y;  
	double cx=p3.x-p1.x,cy=p3.y-p1.y;  
	double d=2*(bx*cy-by*cx);  
	double ex=(cy*(bx*bx+by*by)-by*(cx*cx+cy*cy))/d+p1.x;  
	double ey=(bx*(cx*cx+cy*cy)-cx*(bx*bx+by*by))/d+p1.y;  
	Point p=Point(ex,ey);
	return Circle(p,length(p1-p));
}
int main()
{
	int t,i;
	Point p[3];
	Circle c;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<3;i++)
		{
			p[i].input();
		}
		c=CircumscribedCircle(p[0],p[1],p[2]);
		if(p[0]==p[1]||p[0]==p[2]||p[1]==p[2]) printf("%.1lf %.1lf\n",(p[0].x+p[1].x+p[2].x)/2,(p[0].y+p[1].y+p[2].y)/2);
		else if(sgn(c.r)<=0) puts("No this position");
		else printf("%.1lf %.1lf\n",c.c.x,c.c.y);
	}
	return 0;
}
