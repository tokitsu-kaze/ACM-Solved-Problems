////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-27 20:47:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2202
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:3104KB
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
vector<Point> graham(vector<Point> p)
{  
	int n,m,k,i;
	sort(p.begin(), p.end());  
	p.erase(unique(p.begin(), p.end()), p.end());
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
		while(m>k&&cross(res[m-1]-res[m-2],p[i]-res[m-2])<=0)m--;  
	    res[m++]=p[i];  
	}  
	if(n>1) m--;  
	res.resize(m);
	return res;
}
double calarea(Point c,Point b,Point a){return cross(b-a,c-a);}
int main()
{
	int n,i,j,k,m;
	double a,b,ans;
	while(~scanf("%d",&n))
	{
		vector<Point> poly,res;
		Point p;
		for(i=0;i<n;i++)
		{
			p.input();
			poly.push_back(p);
		}
		res=graham(poly);
		m=res.size();
		ans=0;
		for(i=0;i<m;i++)
		{
			for(j=i+1;j<m+1;j++)
			{
				for(k=j+1;k<m+2;k++)
				{
					ans=max(ans,fabs(calarea(res[i],res[j%m],res[k%m])));
				}
			}
		}
		printf("%.2lf\n",ans/2);
	}
	return 0;
}