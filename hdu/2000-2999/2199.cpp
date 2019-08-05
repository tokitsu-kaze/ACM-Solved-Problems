////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-06 16:22:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2199
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1580KB
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
double cal(double x)
{
	return 8*x*x*x*x+7*x*x*x+2*x*x+3*x+6;
}
int main()
{
	int t;
	double x,y;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%lf",&y);
			double l,r,m,t;
			l=0;
			r=10000;
			while(r-l>eps)  
			{  
				m=(l+r)/2;
				t=cal(m);
				if(y-t>=eps) l=m;
				else r=m;
			}
			if(l>=eps&&l-100<=eps) printf("%.4lf\n",l);
			else puts("No solution!");
		}
	}
	return 0;
}