////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-10 10:12:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 6024
////Problem Title: 
////Run result: Accept
////Run time:530MS
////Run memory:1808KB
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
const double eps=1e-12;
const int MAX=1e6+10;
const ll mod=1e9+7;
struct node
{
	ll pos,cost;
}a[3010];
bool operator<(node a,node b)
{
	return a.pos<b.pos;
}
int main()
{
	ll n,i,j,dis,pre,ans,dp[3010];
	while(~scanf("%lld",&n))
	{
		mem(a,0);
		scanf("%lld%lld",&a[1].pos,&a[1].cost);
		dis=0;
		for(i=2;i<=n;i++)
		{
			scanf("%lld%lld",&a[i].pos,&a[i].cost);
		}
		sort(a+1,a+1+n);
		mem(dp,0);
		dp[1]=a[1].cost;
		for(i=2;i<=n;i++)
		{
			dp[1]+=(a[i].pos-a[1].pos);
		}
		for(i=2;i<=n;i++)
		{
			for(j=1;j<i;j++)
			{
				if(j==1) dp[i]=dp[j]-(a[i].pos-a[j].pos)*(n-i+1)+a[i].cost;
				else dp[i]=min(dp[i],dp[j]-(a[i].pos-a[j].pos)*(n-i+1)+a[i].cost);
			}
		}
		printf("%lld\n",*min_element(dp+1,dp+1+n));
	}
	return 0;
}