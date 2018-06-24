////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-09 12:43:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4716
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1572KB
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
    int i,n,t,cas;
    while(~scanf("%d",&t))
    {
		cas=1;
		while(t--)
		{
			scanf("%d",&n);
			printf("Case #%d:\n",cas++);
			n/=10;
			puts("*------------*");
			for(i=0;i<10-n;i++)
			{
				puts("|............|");
			}
			for(i=0;i<n;i++)
			{
				puts("|------------|");
			}
			puts("*------------*");
		}
	}
    return 0;
}