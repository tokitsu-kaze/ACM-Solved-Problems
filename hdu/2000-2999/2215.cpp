////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-06 10:14:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2215
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1648KB
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
};
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
bool operator <(Point a,Point b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
bool operator ==(Point a,Point b){return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;}
vector<Point> graham(vector<Point> p)
{  
	int n,m,k,i;
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	n=p.size();
	m=0;
	vector<Point> res(n+1);  
	for(i=0;i<n;i++)
	{  
		while(m>1&&cross(res[m-1]-res[m-2],p[i]-res[m-2])<=0) m--;  
		res[m++]=p[i];  
	}  
	k=m;  
	for(i=n-2;i>=0;i--)
	{  
		while(m>k&&cross(res[m-1]-res[m-2],p[i]-res[m-2])<=0) m--;  
	    res[m++]=p[i];  
	}  
	if(n>1) m--;  
	res.resize(m);
	return res;
}
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
void MinDisWith2Point(Point pi,Point pj,int m,vector<Point> p)  
{  
	int k;
	center=MidSeg(pi,pj);  
	r=dist(pi,pj)/2;  
	for(k=0;k<m;k++)
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
void MinDisWithPoint(Point pi,int m,vector<Point> p)  
{
	center=MidSeg(pi,p[0]); 
	r=dist(pi,p[0])/2;  
	for(int j=1;j<m;j++)  
	{  
		if(dist(center, p[j])<=r) continue;  
		else MinDisWith2Point(pi,p[j],j,p);
	}  
}
int main()
{
	int n,i,m;
	while(~scanf("%d",&n)&&n)
	{
		vector<Point> p,res;
		Point t;
		for(i=0;i<n;i++)
		{
			t.input();
			p.push_back(t);
		}
		res=graham(p);
		m=res.size();
		if(m==1)
		{
			puts("0.50");
			continue;
		}
		r=dist(res[0],res[1])/2;
       	center=MidSeg(res[0],res[1]); 
       	for(i=2;i<m;i++)
		{  
			if(dist(center,res[i])<=r) continue;  
			else MinDisWithPoint(res[i],i,res);
		}
       	printf("%.2lf\n",r+0.5);
	}
	return 0;
}