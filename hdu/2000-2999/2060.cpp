////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-05 17:02:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2060
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
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 100000+10
using namespace std;
typedef long long ll;
int main()
{
    int t,n,a,b;
    while(cin>>t)
    {
		while(t--)
		{
			cin>>n>>a>>b;
			if(n>6) a=a+(n-6)*8+27;
			else a=a+(15-n)*n/2;
			if(a>=b) puts("Yes");
			else puts("No");
		}
	}
    return 0;
}
