////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-09 12:31:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2529
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1600KB
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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 50000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
    double h,l,v;
    while(~scanf("%lf%lf%lf",&h,&l,&v)&&(h+l+v))
    {
		printf("%.2lf\n",-9.8*l*l/(2*v*v)-l*l/(2.0*(-9.8*l*l)/(v*v))+h);
	}
    return 0;
}