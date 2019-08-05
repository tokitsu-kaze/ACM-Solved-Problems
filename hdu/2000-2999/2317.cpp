////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-02 21:51:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2317
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1584KB
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
typedef long long ll;
int main()
{
	int t,r,e,c;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>r>>e>>c;
			if(e-c>r) puts("advertise");
			else if(e-c==r) puts("does not matter");
			else if(e-c<r) puts("do not advertise");
		}
	}
    return 0;
}