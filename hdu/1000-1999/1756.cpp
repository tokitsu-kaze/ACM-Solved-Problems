////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-27 20:00:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1756
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1600KB
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
bool OnSeg(Point p,Point p1,Point p2)
{
	return sgn(cross(p1-p,p2-p))==0&&sgn(dot(p1-p,p2-p))<0;
}
int isPointInPolygon(Point p,vector<Point> poly)
{
	int cnt,n,k,d1,d2,i;
	cnt=0;
	n=poly.size();
	for(i=0;i<n;i++)
	{
		if(OnSeg(p,poly[i],poly[(i+1)%n])) return -1;
		k=sgn(cross(poly[(i+1)%n]-poly[i],p-poly[i]));
		d1=sgn(poly[i].y-p.y);
		d2=sgn(poly[(i+1)%n].y-p.y);
		if(k>0&&d1<=0&&d2>0) cnt++;
		if(k<0&&d2<=0&&d1>0) cnt--;
	} 
	if(cnt) return 1;
	else return 0;
}
int main()
{
	int n,k,i;
	double a,b;
	while(~scanf("%d",&n))
	{
		vector<Point> poly;
		Point p;
		for(i=0;i<n;i++)
		{
			p.input();
			poly.push_back(p);
		}
		scanf("%d",&k);
		while(k--)
		{
			scanf("%lf%lf",&a,&b);
			if(isPointInPolygon(Point(a,b),poly)) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}