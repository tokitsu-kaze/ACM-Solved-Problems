////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-11 20:32:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5591
////Problem Title: 
////Run result: Accept
////Run time:62MS
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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define eps 1e-9
#define MAX 200+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
	int t,n;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			if(n%2) puts("1");
			else puts("0");
		}
	}
    return 0;
}