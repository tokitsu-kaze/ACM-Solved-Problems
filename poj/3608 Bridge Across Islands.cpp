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
const double eps=1e-5;
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
	int n,m,i;
	double ans;
	while(~scanf("%d%d",&n,&m)&&n+m)
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
		resp=graham(p);
		resq=graham(q);
		ans=RC_Dis(p,q);
		printf("%.5f\n",ans);
	}
	return 0;
}
