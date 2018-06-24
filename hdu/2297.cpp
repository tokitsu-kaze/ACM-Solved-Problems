////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-26 22:20:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2297
////Problem Title: 
////Run result: Accept
////Run time:702MS
////Run memory:8384KB
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
	if(x>0) return 1;
	else return -1;
}
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
	point operator +(const point &b)const
	{
		return point(x+b.x,y+b.y);
	}
	point operator -(const point &b)const
	{
		return point(x-b.x,y-b.y);
	}
	double operator *(const point &b)const
	{
		return x*b.x+y*b.y;
	}
};
typedef point vec;
struct line
{
	point s,e;
	vec v;
	double ang;
	line(){}
	line(point a,vec b)
	{
		s=a;
		v=b;
		ang=atan2(v.y,v.x);
	}
	void twopoint(point a,point b)
	{
		s=a;
		e=b;
		v=e-s;
		ang=atan2(v.y,v.x);
	}
	point operator &(const line &b)const
	{
		point res=s;
		point u=s-b.s;
		double t=(b.v^u)/(v^b.v);
		res.x+=v.x*t;
		res.y+=v.y*t;
		return res;
	}
}l[MAX];
bool hpicmp(line a,line b)
{
	return a.ang<b.ang;
}
bool judge(line a,point b)
{
	return sgn(a.v^(b-a.s))>0;
}
point tp[MAX];
line q[MAX];
point res[MAX];
int hpi(int n)
{
	int i,head,tail,resn;
	mem(tp,0);
	mem(res,0);
	mem(q,0);
	sort(l,l+n,hpicmp);
	head=tail=0;
	q[0]=l[0];
	resn=0;
	for(i=1;i<n;i++)
	{
		while(head<tail&&!judge(l[i],tp[tail-1]))
		{
			tail--;
		}
		while(head<tail&&!judge(l[i],tp[head]))
		{
			head++;
		}
		q[++tail]=l[i];
		if(fabs(q[tail].v^q[tail-1].v)<eps)
		{
			tail--;
			if(judge(q[tail],l[i].s)) q[tail]=l[i];
		}
		if(head<tail) tp[tail-1]=q[tail-1]&q[tail];
	}
	while(head<tail&&!judge(q[head],tp[tail-1]))
	{
		tail--;
	}
	if(tail<=head+1) return 2;
	tp[tail]=q[tail]&q[head];
	for(i=head;i<=tail;i++)
	{
		res[resn++]=tp[i];
	}
	return resn;
}
int main()
{
	int t,i,n;
	double p,v;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				scanf("%lf%lf",&p,&v);
				l[i]=line(point(0,p),vec(1,v));
			}
			l[n++].twopoint(point(0,0),point(0,-INF));
			printf("%d\n",hpi(n)-1);
		}
	}
	return 0;
}
/*
2
1
2000000000 2000000000
3
1 1
2 3
3 2
*/