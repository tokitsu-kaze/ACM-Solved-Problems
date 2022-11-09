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
}p[1111];
double dis(point a,point b)
{
	return sqrt((a-b)*(a-b));
}
double dis2(point a,point b,point c)
{
	double x,y,z,tp;
	x=dis(a,b);
	y=dis(b,c);
	z=dis(c,a);
	tp=(x+y+z)/2;
	return sqrt(tp*(tp-x)*(tp-y)*(tp-z))/z;
}
int main()
{
	int n,i;
	double ans;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			p[i].input();
		}
		p[n++]=p[0];
		p[n++]=p[1];
		ans=INF;
		for(i=1;i<n-1;i++)
		{
			ans=min(ans,dis(p[i-1],p[i])/2);
		}
		for(i=2;i<n;i++)
		{
			ans=min(ans,dis2(p[i-2],p[i-1],p[i]));
		}
		printf("%.10lf\n",ans);
	}
	return 0;
}