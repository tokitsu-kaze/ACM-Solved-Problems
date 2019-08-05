////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-07 10:30:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1589
////Problem Title: 
////Run result: Accept
////Run time:280MS
////Run memory:4248KB
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
const int MAX=50000+10;
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
double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}
double dist2(Point a,Point b){return dot(a-b,a-b);}
double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
Point p1[MAX],temp[MAX];
bool cmpxy(Point a,Point b)
{
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
bool cmpy(Point a,Point b)
{
	return a.y<b.y;
}
double ClosestPair(int l,int r)
{
	int mid,i,j,k;
	double d,d1,d2,d3;
	d=INF;
	if(l==r) return d;
	if(l+1==r) return dist(p1[l],p1[r]);
	mid=(l+r)>>1;
	d1=ClosestPair(l,mid);
	d2=ClosestPair(mid+1,r);
	d=min(d1,d2);
	k=0;
	for(i=l;i<=r;i++)
	{
		if(fabs(p1[mid].x-p1[i].x)<=d) temp[k++]=p1[i];
	}
	sort(temp,temp+k,cmpy);
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k&&temp[j].y-temp[i].y<d;j++)
		{
			d3=dist(temp[i],temp[j]);
			if(d>d3) d=d3;
		}
	}
	return d;
}
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
	int n,i,cas=1;
	double ansmin,ansmax;
	while(~scanf("%d",&n)&&n)
	{
		vector<Point> p,res;
		for(i=0;i<n;i++)
		{
			p1[i].input();
			p.push_back(p1[i]);
		}
		sort(p1,p1+n,cmpxy);
		ansmin=ClosestPair(0,n-1);
		res=graham(p);
		ansmax=RC_FarthestPair(res);
		printf("Case %d:\n",cas++);
		printf("Distance of the nearest couple is %.3lf\n",ansmin);
		printf("Distance of the most distant couple is %.3lf\n",sqrt(ansmax));
		puts("");
	}
	return 0;
}
