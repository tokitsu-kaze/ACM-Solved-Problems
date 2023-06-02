////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-06-09 17:20:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2191
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1676KB
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
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-9;
const int MAX=100000+10;
const ll mod=10000;
struct node
{
	int v,w,n;
}a[111];
int main()
{
	int t,n,m,i,j,dp[111];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d",&a[i].v,&a[i].w,&a[i].n);
		}
		mem(dp,0);
		for(i=1;i<=m;i++)
		{
			for(j=n;j>=a[i].v;j--)
			{
				int temp=1;
				while(temp*a[i].v<=j&&temp<=a[i].n) 
				{
					dp[j]=max(dp[j],dp[j-temp*a[i].v]+temp*a[i].w);
					temp++;
				}
			}
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}