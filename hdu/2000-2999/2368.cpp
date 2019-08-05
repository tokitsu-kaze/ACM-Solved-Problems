////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-11 19:44:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2368
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1692KB
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
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1000000+10;
const ll mod=1e6;
int sgn(double x)
{  
	if(fabs(x)<eps) return 0;
	else return x>0?1:-1;  
}
int main()
{
	int r,cas=1;
	double h,w;
	while(~scanf("%d",&r)&&r)
	{
		scanf("%lf%lf",&h,&w);
		printf("Pizza %d ",cas++);
		if(sgn(2.0*r-sqrt(h*h+w*w))>=0) puts("fits on the table.");
		else puts("does not fit on the table.");
	}
	return 0;
}