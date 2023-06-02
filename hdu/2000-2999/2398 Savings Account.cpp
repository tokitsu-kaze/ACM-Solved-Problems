////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-09 22:05:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2398
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
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=1e6+10;
const ll mod=1e9+7;
int main()
{
	int n;
	double a,b,c;
	while(~scanf("%lf%lf%lf",&a,&b,&c))
	{
		n=0;
		while(a<c)
		{
			n++;
			a+=a*b/100.0;
		}
		printf("%d\n",n);
	}
	return 0;
}