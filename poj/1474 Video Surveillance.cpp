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
	else if(x>0) return 1;
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
	point operator -(const point &b)const
	{
		return point(x-b.x,y-b.y);
	}
	double operator *(const point &b)const
	{
		return x*b.x+y*b.y;
	}
}p[MAX];
struct line
{
	point s,e;
	double k;
	line(){}
	line(point a,point b)
	{
		s=a;
		e=b;
		k=atan2(e.y-s.y,e.x-s.x);
	}
	point operator &(const line &b)const
	{
		point res=s;
		double t=((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
		res.x+=(e.x-s.x)*t;
		res.y+=(e.y-s.y)*t;
		return res;
	}
}l[MAX];
bool hpicmp(line a,line b)
{
	if(fabs(a.k-b.k)>eps) return a.k<b.k;
	return ((a.s-b.s)^(b.e-b.s))<0;
}
line q[MAX];
point res[MAX];
int hpi(int n)
{
	int i,m,head,tail,resn;
	sort(l,l+n,hpicmp);
	m=1;
	for(i=1;i<n;i++)
	{
		if(fabs(l[i].k-l[i-1].k)>eps) l[m++]=l[i];
	}
	head=0;
	tail=1;
	q[0]=l[0];
	q[1]=l[1];
	resn=0;
	for(i=2;i<m;i++)
	{
		if(fabs((q[tail].e-q[tail].s)^(q[tail-1].e-q[tail-1].s))<eps
		||fabs((q[head].e-q[head].s)^(q[head+1].e-q[head+1].s))<eps) return resn;
		while(head<tail&&(((q[tail]&q[tail-1])-l[i].s)^(l[i].e-l[i].s))>eps)
		{
			tail--;
		}
		while(head<tail&&(((q[head]&q[head+1])-l[i].s)^(l[i].e-l[i].s))>eps)
		{
			head++;
		}
		q[++tail]=l[i];
	}
	while(head<tail&&(((q[tail]&q[tail-1])-q[head].s)^(q[head].e-q[head].s))>eps)
	{
		tail--;
	}
	while(head<tail&&(((q[head]&q[head+1])-q[tail].s)^(q[tail].e-q[tail].s))>eps)
	{
		head++;
	}
	if(tail<=head+1) return resn;
	for(i=head;i<tail;i++)
	{
		res[resn++]=q[i]&q[i+1];
	}
	if(head<tail-1) res[resn++]=q[head]&q[tail];
	return resn;
}
int main()
{
	int i,n,cas=1;;
	while(~scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
		{
			p[i].input();
		}
		p[n]=p[0];
		for(i=0;i<n;i++)
		{
			l[i]=line(p[i+1],p[i]);
		}
		printf("Floor #%d\n",cas++);
		if(hpi(n)) puts("Surveillance is possible.");
		else puts("Surveillance is impossible.");
		puts("");
	}
	return 0;
}