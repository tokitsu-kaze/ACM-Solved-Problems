////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-01 10:15:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1007
////Problem Title: 
////Run result: Accept
////Run time:967MS
////Run memory:4748KB
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
Point operator -(Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
double dot(Point a,Point b){return a.x*b.x+a.y*b.y;}
double dis(Point a,Point b){return sqrt(dot(a-b,a-b));}
Point p[MAX],temp[MAX];
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
	if(l+1==r) return dis(p[l],p[r]);
	mid=(l+r)>>1;
	d1=ClosestPair(l,mid);
	d2=ClosestPair(mid+1,r);
	d=min(d1,d2);
	k=0;
	for(i=l;i<=r;i++)
	{
		if(fabs(p[mid].x-p[i].x)<=d) temp[k++]=p[i];
	}
	sort(temp,temp+k,cmpy);
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k&&temp[j].y-temp[i].y<d;j++)
		{
			d3=dis(temp[i],temp[j]);
			if(d>d3) d=d3;
		}
	}
	return d;
}
int main()
{
	int n,i;
	while(~scanf("%d",&n)&&n)
	{
		mem(p,0);
		for(i=0;i<n;i++)
		{
			p[i].input();
		}
		sort(p,p+n,cmpxy);
		printf("%.2lf\n",ClosestPair(0,n-1)/2);
	}
	return 0;
}