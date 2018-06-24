////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-02 21:35:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2440
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1620KB
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
const int MAX=100000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int sgn(double x)
{
	if(abs(x)<eps) return 0;
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
Vector operator -(Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
bool operator <(Point a,Point b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
bool operator ==(Point a,Point b){return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;}
double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
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
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}
pair<Point,double> fermat(vector<Point> p)
{  
	Point s;  
	double t=0,ds,dz,ans;  
	int i,j,k,n,flag,dir[4][2]={0,1,0,-1,1,0,-1,0};
	s=Point(0,0);
	n=p.size();
	for(i=0;i<n;i++)
	{  
		t+=fabs(p[i].x)+fabs(p[i].y);  
		s.x+=p[i].x;  
		s.y+=p[i].y;  
	}
	s.x/=n;  
	s.y/=n;  
	flag=0;  
	while(t>eps)  
	{  
		for(k=0;k<10;t/=2,k++)
		{
			for(i=0;i<4;i++)  
			{
				Point z;
				z.x=s.x+dir[i][0]*t;  
				z.y=s.y+dir[i][1]*t;  
				ds=dz=0;  
				for(j=0;j<n;j++)
				{  
					ds+=dist(s,p[j]);
					dz+=dist(z,p[j]);
				}  
				if(ds>dz)  
				{  
					s=z;
					ans=dz;
					flag=1;  
				} 
			}
		}
	}  
	if(!flag) ans=ds;  
	pair<Point,double> res;
	res=make_pair(s,ans);
	return res;
}
int main()
{
	int t,n,i;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			vector<Point> p,res;
			Point a;
			for(i=0;i<n;i++)
			{
				a.input();
				p.push_back(a);
			}
			res=graham(p);
			pair<Point,double> pr;
			pr=fermat(res);
			printf("%.0lf\n",pr.second);
			if(t) puts("");
		}
	}
	return 0;
}