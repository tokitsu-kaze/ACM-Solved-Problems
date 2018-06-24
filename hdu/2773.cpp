////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-20 19:05:42
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2773
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1616KB
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
struct point
{
	double x,y;
	point(){}
	void input()
	{
		scanf("%lf%lf",&x,&y);
	}
	point(double a,double b)
	{
		x=a;
		y=b;
	}
	double operator ^(const point &b)const
	{
		return x*b.y-b.x*y;
	} 
	point operator -(const point &b)const
	{
		return point(x-b.x,y-b.y);
	}
	double operator *(const point &b)const
	{
		return x*b.x+y*b.y;
	}
}p1[MAX],p2[MAX];
struct line
{
	point s,e;
}l1[MAX],l2[MAX];
double dis(point a,point b)
{
	return sqrt((a-b)*(a-b));
}
point nearestptol(point pt,line lt)
{
	point res;
	double t=((pt-lt.s)*(lt.e-lt.s))/((lt.e-lt.s)*(lt.e-lt.s));
	if(t>=0&&t<=1)
	{
		res.x=lt.s.x+(lt.e.x-lt.s.x)*t;
		res.y=lt.s.y+(lt.e.y-lt.s.y)*t;
	}
	else
	{
		if(dis(pt,lt.s)<dis(pt,lt.e)) res=lt.s;
		else res=lt.e;
	}
	return res;
}
int main()
{
	int t,n1,n2,i,k1,k2,j;
	double ans;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n1);
			for(i=0;i<n1;i++)
			{
				p1[i].input();
			}
			p1[n1++]=p1[0];
			k1=0;
			for(i=1;i<n1;i++)
			{
				l1[k1].s=p1[i-1];
				l1[k1].e=p1[i];
				k1++;
			}
			scanf("%d",&n2);
			for(i=0;i<n2;i++)
			{
				p2[i].input();
			}
			p2[n2++]=p2[0];
			k2=0;
			for(i=1;i<n2;i++)
			{
				l2[k2].s=p2[i-1];
				l2[k2].e=p2[i];
				k2++;
			}
			ans=INF;
			for(i=0;i<n1-1;i++)
			{
				for(j=0;j<k2;j++)
				{
					ans=min(ans,dis(p1[i],nearestptol(p1[i],l2[j])));
				}
			}
			for(i=0;i<n2-1;i++)
			{
				for(j=0;j<k1;j++)
				{
					ans=min(ans,dis(p2[i],nearestptol(p2[i],l1[j])));
				}
			}
			printf("%lf\n",ans/2);
		}
	}
	return 0;
} 