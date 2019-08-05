////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-03 09:37:44
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2554
////Problem Title: 
////Run result: Accept
////Run time:358MS
////Run memory:1576KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <map>
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 1000000+10
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
int main()
{
    int n;
    while(cin>>n&&n)
    {
		n*(n+1)/2&1?puts("N"):puts("Y");
	}
    return 0;
}
