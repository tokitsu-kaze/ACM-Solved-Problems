////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-28 18:15:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1723
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1680KB
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
const double eps=1e-6;
const int MAX=400000+10;
const ll mod=1e9+6;
int main()
{
	ll n,m,i,j,dp[33];
	while(~scanf("%lld%lld",&n,&m)&&n+m)
	{
		mem(dp,0);
		dp[1]=1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(i+j<=n)
				{
					dp[i+j]+=dp[i];
				}
			}
		}
		printf("%lld\n",dp[n]);
	}
	return 0;
} 