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
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);} 
bool operator <(Point a,Point b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
bool operator ==(Point a,Point b){return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;}
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double dist2(Point a,Point b){return dot(a-b,a-b);}
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
double RC_FarthestPair(vector<Point> p)
{  
	int n,i,j,k;
	n=p.size();
	if(n==1) return 0;
	if(n==2) return dist2(p[0],p[1]);
	double temp,res=0;
	k=1;
    for(j=1;j<n;j++)
	{  
		for(i=0;i<n;i++)
		{  
			while(cross(p[i]-p[(i+j)%n],p[(k+1)%n]-p[k])<0) k=(k+1)%n;  
			temp=max(dist2(p[j],p[i]),dist2(p[j],p[k]));  
			res=max(res,temp);  
		}  
	}  
    return res;
}
int main()
{
	int n,i;
	double ans;
	while(~scanf("%d",&n))
	{
		Point t;
		vector<Point> p,res;
		for(i=0;i<n;i++)
		{
			t.input();
			p.push_back(t);
		}
		res=graham(p);
		ans=RC_FarthestPair(res);
		printf("%.0lf\n",ans);
	}
	return 0;
}
/*
4
0 0
1 0
2 0
-1 0
ans=9
*/
