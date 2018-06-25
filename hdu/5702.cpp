////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-11 20:52:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5702
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
struct node
{
	char c[15];
	int v;
}a[15];
bool cmp(node a,node b)
{
	return a.v>b.v;
}
int main()
{
	int t,n,i;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				getchar();
				scanf("%s %d",a[i].c,&a[i].v);
			}
			sort(a,a+n,cmp);
			for(i=0;i<n;i++)
			{
				if(!i) printf("%s",a[i].c);
				else printf(" %s",a[i].c);
			}
			puts("");
		}
	}
    return 0;
}