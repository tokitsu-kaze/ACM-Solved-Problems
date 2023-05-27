////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-13 22:03:44
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2108
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1636KB
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
const int MAX=10000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
struct point
{
	int x,y;
	int operator^(const point &b)const
	{
		return x*b.y-y*b.x;
	}
}a[MAX];
int main()
{
	int n,i,x[MAX],y[MAX],flag;
	while(~scanf("%d",&n)&&n)
	{
		mem(x,0);
		mem(y,0);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
		}
		x[n]=x[0];
		y[n]=y[0];
		x[n+1]=x[1];
		y[n+1]=y[1];
		n+=2;
		for(i=0;i<n-1;i++)
		{
			a[i].x=x[i+1]-x[i];
			a[i].y=y[i+1]-y[i];
		}
		flag=0;
		for(i=1;i<n-1&&!flag;i++)
		{
			if((a[i-1]^a[i])<0)
			{
				flag=1;
				break;
			}
		}
		if(flag) puts("concave");
		else puts("convex");
	}
	return 0;
}