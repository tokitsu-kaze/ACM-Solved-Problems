////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-06-05 15:11:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1978
////Problem Title: 
////Run result: Accept
////Run time:358MS
////Run memory:1772KB
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
const int MAX=1000000+10;
const ll mod=10000;
int n,m,mp[111][111],dp[111][111];
int check(int x,int y)
{
	if(x<1||y<1||x>n||y>m) return 0;
	return 1;
}
int dfs(int x,int y)
{
	int i,j;
	if(dp[x][y]>=0) return dp[x][y];
	dp[x][y]=0;
	for(i=0;i<=mp[x][y];i++)
	{
		for(j=0;i+j<=mp[x][y];j++)
		{
			if((i+j)&&check(x+i,y+j))
			{
				dp[x][y]+=dfs(x+i,y+j);
				dp[x][y]%=mod;
			}
		}
	}
	return dp[x][y];
}
int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		mem(mp,0);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&mp[i][j]);
				dp[i][j]=-1;
			}
		}
		dp[n][m]=1;
		int ans=dfs(1,1)%mod;
		printf("%d\n",ans);
	}
	return 0;
} 