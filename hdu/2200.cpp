////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-02 22:03:53
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2200
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1608KB
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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,(b),sizeof(a))
#define PI acos(-1.0)
#define MAX 10000+10
using namespace std;
typedef __int64 ll;
int main()
{
	ll n;
	while(cin>>n)
	{
		cout<<(n-2)*(1<<(n-1))+1<<endl;
	}
    return 0;
}