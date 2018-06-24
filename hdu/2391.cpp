////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-28 15:13:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2391
////Problem Title: 
////Run result: Accept
////Run time:1263MS
////Run memory:9632KB
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
const int MAX=1e3+10;
const ll mod=1e9+6;
int dp[MAX][MAX],mp[MAX][MAX];
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
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1])+mp[i][j];
			}
		}
		printf("Scenario #%d:\n",cas++);
		printf("%d\n",dp[n][m]);
		puts("");
	}
	return 0;
} 