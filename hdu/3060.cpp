////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-06-14 18:03:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3060
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1740KB
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
const double eps=1e-8;
const int MAX=500+10;
const ll mod=10000;
double minx,maxx,miny,maxy;
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
};
Point PointOfLineInter(Line a,Line b)
{
	Vector u=a.p-b.p;
	double t=cross(b.v,u)/cross(a.v,b.v);
	return a.p+a.v*t;
}
double PolygonArea(Point *p,int n)
{ 
	double res=0;
	for(int i=0;i<n;i++)
	{
		res+=cross(p[i],p[(i+1)%n]);  
	}
	return fabs(res/2);  
}
double CPIA(Point *a,Point *b,int na,int nb)
{
    Point p[MAX],q[MAX];
    int tn,sflag,eflag,i,j;
    a[na]=a[0];
	b[nb]=b[0];
	for(i=0;i<=nb;i++)
	{
		p[i]=b[i];
	}
    for(i=0;i<na&&nb>2;i++)
    {
        sflag=sgn(cross(a[i+1]-a[i],p[0]-a[i]));
        for(j=0,tn=0;j<nb;j++)
        {
            if(sflag>=0) q[tn++]=p[j];
            eflag=sgn(cross(a[i+1]-a[i],p[j+1]-a[i]));
            if((sflag^eflag)==-2) q[tn++]=PointOfLineInter(Line(a[i],a[i+1]-a[i]),Line(p[j],p[j+1]-p[j]));
       		sflag=eflag;
		}
        for(j=0;j<tn;j++)
        {
			p[j]=q[j];
		}
        nb=tn;
		p[nb]=p[0];
    }
    if(nb<3) return 0;
    return PolygonArea(p,nb);
}
double SPIA(Point *a,Point *b,int na,int nb)
{
    int i,j,temp1,temp2;
    Point t1[4],t2[4];
    double res=0;
    a[na]=t1[0]=a[0];
	b[nb]=t2[0]=b[0];
    for(i=2;i<na;i++)
    {
        t1[1]=a[i-1];
		t1[2]=a[i];
        temp1=sgn(cross(t1[1]-t1[0],t1[2]-t1[0]));
        if(temp1<0) swap(t1[1],t1[2]);
        for(j=2;j<nb;j++)
        {
            t2[1]=b[j-1];
			t2[2]=b[j];
            temp2=sgn(cross(t2[1]-t2[0],t2[2]-t2[0]));
            if(temp2<0) swap(t2[1],t2[2]);
            res+=CPIA(t1,t2,3,3)*temp1*temp2;
        }
    }
    return res;
}
int main()
{
	int n,m,i,cas=1;
	Point a[MAX],b[MAX];
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<n;i++)
		{
			a[i].input();
		}
		for(i=0;i<m;i++)
		{
			b[i].input();
		}
		double res=PolygonArea(a,n)+PolygonArea(b,m)-SPIA(a,b,n,m);
		printf("%.2lf\n",res);
	}
	return 0;
}