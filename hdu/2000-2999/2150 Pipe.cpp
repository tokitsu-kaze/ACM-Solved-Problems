////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-17 20:47:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2150
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1696KB
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
	double operator *(const point &b)const
	{
		return x*b.x+y*b.y;
	}
	point operator -(const point &b)const
	{
		return point(x-b.x,y-b.y);
	}
}p[MAX][MAX];
struct line
{
	point s,e;
}l[MAX][MAX];
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
	int m,n,i,j,flag,k[MAX],i1,j1;
	while(~scanf("%d",&n))
	{
		mem(k,0);
		for(i=0;i<n;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				p[i][j].input();
			} 
			for(j=1;j<m;j++)
			{
				l[i][k[i]].s=p[i][j-1];
				l[i][k[i]].e=p[i][j];
				k[i]++;
			}
		}
		flag=0;
		for(i=0;i<n&&!flag;i++)
		{
			for(i1=0;i1<k[i]&&!flag;i1++)
			{
				for(j=i+1;j<n&&!flag;j++)
				{
					for(j1=0;j1<k[j]&&!flag;j1++)
					{
						if(inter(l[i][i1],l[j][j1])) flag=1;
					}
				}
			}
		}
		if(flag) puts("Yes");
		else puts("No");
	}
	return 0;
}