////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-16 14:46:10
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1071
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1604KB
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
int main()
{
	int t;
	double x1,y1,x2,y2,x3,y3;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
			printf("%.2f\n",(y1-y3)*(x3-x2)-(y1-y3)*(pow(x3-x1,3)-pow(x2-x1,3))/(3.0*pow(x3-x1,2))+(y3-y2)*(x3-x2)/2.0);
		}
	}
	return 0;
}
