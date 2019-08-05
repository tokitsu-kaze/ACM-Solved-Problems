////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-02 19:12:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1162
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1736KB
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
}p[111];
int n,flag[111];
double mp[111][111],dis[111];
Point operator -(Point a,Point b){return Point(a.x-b.x,a.y-b.y);}
double dot(Point a,Point b){return a.x*b.x+a.y*b.y;}
double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}
struct node
{
	int n;
	double v;
	friend bool operator <(node a,node b)
	{
		return a.v>b.v;
	}
};
double prim()
{
	int i;
	double ans=0;
	node t,next;
	priority_queue<node> q;
	mem(flag,0);
	t.n=0;
	t.v=0;
	dis[0]=0;
	q.push(t);
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(flag[t.n]) continue;
		flag[t.n]=1;
		ans+=t.v;
		for(i=0;i<n;i++)
		{
			if(!flag[i]&&dis[i]>mp[t.n][i])
			{
				dis[i]=mp[t.n][i];
				next.n=i;
				next.v=dis[i];
				q.push(next);
			}
		}
	}
	return ans;
}
int main()
{
	int i,j;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			p[i].input();
		}
		for(i=0;i<n;i++)
		{
			dis[i]=INF;
			for(j=0;j<n;j++)
			{
				mp[i][j]=mp[j][i]=INF;
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				mp[i][j]=mp[j][i]=dist(p[i],p[j]);
			}
		}
		printf("%.2lf\n",prim());
	}
	return 0;
}