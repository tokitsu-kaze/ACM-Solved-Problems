////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-01-22 14:29:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2134
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
#include <cctype>
#include <climits>
#include <map>
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 1000000+10
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
int main()
{
    double r,s;
    while(~scanf("%lf",&r))
    {
		if(r==0) break;
		s=r*r*PI;
		printf("%.3lf %.3lf\n",sqrt(s/3/PI),sqrt(2*s/3/PI));
	}
    return 0;
}