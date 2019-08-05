////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-06 09:47:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3932
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1616KB
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
const int MAX=1000+10;
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
}p[MAX];
typedef Point Vector;
Vector operator +(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}  
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}  
Vector operator *(Vector a,double p){return Vector(a.x*p,a.y*p);}  
Vector operator /(Vector a,double p){return Vector(a.x/p,a.y/p);}
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}
double length(Vector a){return sqrt(dot(a,a));}
Point MidSeg(Point a, Point b){return (a+b)/2;}
double r;
Point center;
void CircumCircle(Point a,Point b,Point c)  
{  
	Point res;   
    double a1=b.x-a.x,b1=b.y-a.y,c1=(a1*a1+b1*b1)/2;  
    double a2=c.x-a.x,b2=c.y-a.y,c2=(a2*a2+b2*b2)/2;  
    double d=a1*b2-a2*b1;  
    res=Point(a.x+(c1*b2-c2*b1)/d,a.y+(a1*c2-a2*c1)/d);  
    center=res;  
}
void MinDisWith2Point(Point pi,Point pj,int m)  
{  
	int k;
	center=MidSeg(pi,pj);  
	r=dist(pi,pj)/2;  
	for(k=1;k<=m;k++)
	{  
		if(dist(center,p[k])<=r) continue; 
        double t=cross((pi-pj),(p[k]-pj));  
        if(t!=0)
		{
			CircumCircle(pi,pj,p[k]);  
			r=dist(center,pi);  
		}  
		else
		{
			double d1,d2,d3;
			d1=dist(pi,pj);
			d2=dist(pi,p[k]);  
			d3=dist(pj,p[k]);
			if(d1>=d2&&d1>=d3)
			{
				center=MidSeg(pi,pj);
				r=dist(pi,pj)/2;
			}
			else if(d2>=d1&&d2>=d3)  
			{
				center=MidSeg(pi,p[k]);  
				r=dist(pi,p[k])/2;  
			}  
			else  
			{  
				center=MidSeg(pj,p[k]);  
				r=dist(pj,p[k])/2;  
			}  
		}  
	}  
}  
void MinDisWithPoint(Point pi,int m)  
{
	center=MidSeg(pi,p[1]); 
	r=dist(pi,p[1])/2;  
	for(int j=2;j<=m;j++)  
	{  
		if(dist(center, p[j])<=r) continue;  
		else MinDisWith2Point(pi,p[j],j-1);
	}  
}
int main()
{
	int n,i;
	double x,y;
	while(~scanf("%lf%lf%d",&x,&y,&n))
	{
		for(i=1;i<=n;i++)
		{
			p[i].input();
		}
		if(n==1)  
        {  
            printf("(%.1lf,%.1lf).\n0.0\n",p[1].x,p[1].y);  
            continue;  
        }
		r=dist(p[1],p[2])/2;
       	center=MidSeg(p[1],p[2]); 
       	for(i=3;i<=n;i++)
		{  
			if(dist(center,p[i])<=r) continue;  
			else MinDisWithPoint(p[i],i-1);
		}
       	printf("(%.1lf,%.1lf).\n%.1lf\n",center.x,center.y,r);
	}
	return 0;
}