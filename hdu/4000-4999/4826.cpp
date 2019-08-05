////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-28 15:51:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4826
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:1776KB
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
const int MAX=1e2+10;
const ll mod=1e9+6;
int dp[MAX][MAX],mp[MAX][MAX];
int dp1[MAX],dp2[MAX];
int main()
{
	int t,cas,n,m,i,j;
	scanf("%d",&t);
	cas=1;
	while(t--)
	{
		scanf("%d%d",&n,&m);
		mem(mp,0);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		mem(dp,0);
		mem(dp1,-0x3f);
		mem(dp2,-0x3f);
		for(i=1;i<=n;i++)
		{
			dp[i][1]=dp[i-1][1]+mp[i][1];
		}
		for(j=2;j<=m;j++)
		{
			
			for(i=1;i<=n;i++)
			{
				dp1[i]=max(dp[i][j-1],dp1[i-1])+mp[i][j];
			}
			for(i=n;i>=1;i--)
			{
				dp2[i]=max(dp[i][j-1],dp2[i+1])+mp[i][j];
			}
			for(i=1;i<=n;i++)
			{
				dp[i][j]=max(dp1[i],dp2[i]);
			}
		}
		printf("Case #%d:\n",cas++);
		printf("%d\n",dp[1][m]);
	}
	return 0;
} 