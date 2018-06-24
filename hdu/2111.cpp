////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-16 16:58:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2111
////Problem Title: 
////Run result: Accept
////Run time:0MS
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
#define MAX 10000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
//typedef __int64 ll;
typedef long long ll;
struct node
{
	int p,m;
}a[111];
int cmp(node a,node b)
{
	return a.p>b.p;
}
int main()
{
	int v,n,i,sum;
	while(~scanf("%d",&v)&&v)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].p,&a[i].m);
		}
		sort(a,a+n,cmp);
		sum=0;
		for(i=0;i<n;i++)
		{
			if(v>=a[i].m)
			{
				sum+=a[i].p*a[i].m;
				v-=a[i].m;
			}
			else
			{
				sum+=v*a[i].p;
				v=0;
			}
			if(!v) break;
		}
		printf("%d\n",sum);
	}
    return 0;
}