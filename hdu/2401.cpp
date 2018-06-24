////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-17 16:39:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2401
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1564KB
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
int main()
{
	int n,w,d,s,a;
	while(~scanf("%d%d%d%d",&n,&w,&d,&s))
	{
		a=n*(n-1)/2*w;
		if(a-s==0) printf("%d\n",n);
		else printf("%d\n",(a-s)/d);
	}
	return 0;
}