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
const int MAX=1000000+10;
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
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}  
bool operator <(Point a,Point b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
bool operator ==(Point a,Point b){return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;}
double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double length(Vector a){return sqrt(dot(a,a));}
double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}
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
bool OnSeg(Point p, Point p1, Point p2)
{  
	return sgn(cross(p1-p,p2-p))==0&&sgn(dot(p1-p,p2-p))<=0;
}
int JudgePointInPolygon(Point p,vector<Point> poly)
{
	int cnt,n,k,d1,d2;
	cnt=0;
	n=poly.size();
	for(int i=0;i<n;i++)
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
int JudgeInclude(vector<Point> p,vector<Point> q)
{
	int n,m,i;
	n=p.size();
	m=q.size();
	for(i=0;i<n;i++)
	{
		if(JudgePointInPolygon(p[i],q)) return 1;
	}
	for(i=0;i<m;i++)
	{
		if(JudgePointInPolygon(q[i],p)) return 1;
	}
	return 0;
}
bool JudgeSegInter(Point a,Point b,Point c,Point d)
{
	double t1,t2,t3,t4;
	t1=cross(b-a,c-a);
	t2=cross(b-a,d-a);
	t3=cross(d-c,a-c);
	t4=cross(d-c,b-c);
	return sgn(t1)*sgn(t2)<0&&sgn(t3)*sgn(t4)<0;
}
int JudgeInter(vector<Point> p,vector<Point> q)
{
	int n,m,i,j;
	n=p.size();
	m=q.size();
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(JudgeSegInter(p[i],p[(i+1)%n],q[j],q[(j+1)%m])) return 1;
		}
	}
	return 0;
}
double DisPointToSeg(Point p,Point a,Point b)
{
	if(a==b) return length(p-a);
	Vector v1,v2,v3;
	v1=b-a;
	v2=p-a;
	v3=p-b;
	if(sgn(dot(v1,v2))<0) return length(v2);
	else if(sgn(dot(v1,v3))>0) return length(v3);
	else return fabs(cross(v1,v2))/length(v1);
}
double DisSegToSeg(Point a,Point b,Point c,Point d)
{
	return min(min(DisPointToSeg(a,c,d),DisPointToSeg(b,c,d))
	,min(DisPointToSeg(c,a,b),DisPointToSeg(d,a,b)));
}
double RC_Dis(vector<Point> p,vector<Point> q)
{  
    int i,j,k,n,m;
    n=p.size();
    m=q.size();
    j=k=0;
    for(i=0;i<n;i++)
    {
        if(p[i].y-p[k].y<-eps) k=i;
    }
    for(i=0;i<m;i++)
    {
        if(q[i].y-q[j].y>eps) j=i;
    }
    double temp,ans=1e99;
    for(i=0;i<n;i++)
    { 
        while((temp=cross(p[(k+1)%n]-p[k],q[(j+1)%m]-p[k])-cross(p[(k+1)%n]-p[k],q[j]-p[k]))>eps) j=(j+1)%m;  
        if(temp<-eps) ans=min(ans,DisPointToSeg(q[j],p[k],p[(k+1)%n])); 
        else ans=min(ans,DisSegToSeg(p[k],p[(k+1)%n],q[j],q[(j+1)%m]));  
        k=(k+1)%n;
    }  
    return ans;  
}  
int main()
{
	int n,m,i,flag;
	double ans;
	while(~scanf("%d%d",&n,&m))
	{
		vector<Point> p,q,resp,resq;
		Point t;
		for(i=0;i<n;i++)
		{
			t.input();
			p.push_back(t);
		}
		for(i=0;i<m;i++)
		{
			t.input();
			q.push_back(t);
		}
		if(n==1&&m==1)
        {
            printf("%.4lf\n",dist(p[0],q[0]));
            continue;
        }
		resp=graham(p);
		resq=graham(q);
		flag=JudgeInter(resp,resq);
		if(flag)
		{
			puts("0.0000");
			continue;
		}
		flag=JudgeInclude(resp,resq);
		if(flag)
		{
			puts("0.0000");
			continue;
		}
		ans=RC_Dis(resp,resq);
		printf("%.4lf\n",ans);
	}
	return 0;
}