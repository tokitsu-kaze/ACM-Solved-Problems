////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-04 10:36:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1789
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1576KB
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
const int MAX=100+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
struct node
{
	int d,s;
}a[1111];
bool cmp(node a,node b)
{
	return a.s>b.s;
}
int main()
{
	int t,n,i,j,sum,flag[1111],tag;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				scanf("%d",&a[i].d);
			}
			for(i=0;i<n;i++)
			{
				scanf("%d",&a[i].s);
			}
			sort(a,a+n,cmp);
			sum=0;
			mem(flag,0);
			for(i=0;i<n;i++)
			{
				tag=0;
				for(j=a[i].d;j>0;j--)
				{
					if(!flag[j])
					{
						flag[j]=1;
						tag=1;
						break;
					}
				}
				if(!tag) sum+=a[i].s;
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}