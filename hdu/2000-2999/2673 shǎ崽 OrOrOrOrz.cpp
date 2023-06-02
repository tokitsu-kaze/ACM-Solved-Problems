////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-18 20:22:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2673
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:1604KB
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
#define eps 1e-12
#define MAX 100000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
    int n,i,j,a[10010];
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		for(i=0,j=n-1;i<n&&j>=i;i++,j--)
		{
			if(i==j)
			{
				printf(" %d",a[i]);
				break;
			}
			if(!i) printf("%d %d",a[j],a[i]);
			else printf(" %d %d",a[j],a[i]);
		}
		puts("");
    }
    return 0;
}
