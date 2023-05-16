////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-15 10:44:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1086
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1596KB
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
	point(double a,double b)
	{
		x=a;
		y=b;
	}
	point operator -(const point &b)const
	{
		return point(x-b.x,y-b.y);
	}
	double operator ^(const point&b)const
	{
		return x*b.y-b.x*y;
	}
};
struct line
{
	point s,e;
}l[MAX];
int sgn(double x)
{
	if(fabs(x)<eps) return 0;
	if(x>0) return 1;
	else return -1;
}
bool inter(line a,line b)
{
	return
	max(a.s.x,a.e.x)>=min(b.s.x,b.e.x)&&
	max(b.s.x,b.e.x)>=min(a.s.x,a.e.x)&&
	max(a.s.y,a.e.y)>=min(b.s.y,b.e.y)&&
	max(b.s.y,b.e.y)>=min(a.s.y,a.e.y)&&
	sgn((b.s-a.e)^(a.s-a.e))*sgn((b.e-a.e)^(a.s-a.e))<=0&&
	sgn((a.s-b.e)^(b.s-b.e))*sgn((a.e-b.e)^(b.s-b.e))<=0;
}
int main()
{
	int n,i,j,cnt;
	double x1,y1,x2,y2;
	while(~scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf",&l[i].s.x,&l[i].s.y,&l[i].e.x,&l[i].e.y);
		}
		cnt=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(inter(l[i],l[j])) cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}