////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-05 22:04:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4717
////Problem Title: 
////Run result: Accept
////Run time:858MS
////Run memory:1608KB
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
const int MAX=300+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
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
}p[MAX],v[MAX];
typedef Point Vector;
Vector operator +(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}  
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}  
Vector operator *(Vector a,double p){return Vector(a.x*p,a.y*p);}  
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}
int n;
double cal(double t)
{
	int i,j;
	double res=0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			res=max(res,dist(p[i]+v[i]*t,p[j]+v[j]*t));
		}
	}
	return res;
}
int main()
{
	int t,i,cas;
	double l,r,lm,rm,tl,tr;
	while(~scanf("%d",&t))
	{
		cas=1;
		while(t--)
		{
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				p[i].input();
				v[i].input();
			}
			l=0;
			r=1000000;
			while(r-l>eps)  
			{  
				rm=(l+r)/2;  
				lm=(rm+r)/2;
				tl=cal(lm);
				tr=cal(rm);
				if(tr<=tl) r=lm;
				else l=rm;
		    }
		    printf("Case #%d: %.2lf %.2lf\n",cas++,l,cal(l));
		}
	}
	return 0;
}