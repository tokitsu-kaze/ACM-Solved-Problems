////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-17 20:17:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1558
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1640KB
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
};
struct line
{
	point s,e;
	void input()
	{
		s.input();
		e.input();
	}
}l[MAX];
int pre[MAX],cnt[MAX],n;
void init()
{
	for(int i=0;i<MAX;i++)
	{
		pre[i]=i;
		cnt[i]=1;
	}
}
int find(int x)
{
	if(pre[x]!=x) pre[x]=find(pre[x]);
	return pre[x];
}
void merge(int a,int b)
{
	int ra,rb;
	ra=find(a);
	rb=find(b);
	if(ra!=rb)
	{
		cnt[rb]+=cnt[ra];
		pre[ra]=rb;
	}
}
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
	int t,n,i,j,q,k;
	char op;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			k=1;
			init();
			for(i=0;i<n;i++)
			{
				getchar();
				scanf("%c",&op);
				if(op=='P')
				{
					l[k].input();
					for(j=1;j<k;j++)
					{
						if(inter(l[j],l[k]))
						{
							merge(j,k);
						}
					}
					k++;
				}
				else if(op=='Q')
				{
					scanf("%d",&q);
					printf("%d\n",cnt[find(q)]);
				}
			}
			if(t) puts("");
		}
	}
	return 0;
}