////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-19 15:57:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5074
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1696KB
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
const int MAX=40000+10;
const ll mod=1e6;
int dp[111][55];
int mp[55][55];
int main()
{
	int t,n,m,i,j,k,a[111];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		mem(dp,0);
		mem(mp,0);
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		mem(a,0);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=1;i<n;i++)
		{
			if(a[i-1]>0&&a[i]>0)
			{
				dp[i][a[i]]=dp[i-1][a[i-1]]+mp[a[i-1]][a[i]];
			}
			else if(a[i-1]<0&&a[i]>0)
			{
				for(j=1;j<=m;j++)
				{
					dp[i][a[i]]=max(dp[i][a[i]],dp[i-1][j]+mp[j][a[i]]);
				}
			}
			else if(a[i-1]>0&&a[i]<0)
			{
				for(j=1;j<=m;j++)
				{
					dp[i][j]=dp[i-1][a[i-1]]+mp[a[i-1]][j];
				}
			}
			else if(a[i-1]<0&&a[i]<0)
			{
				for(j=1;j<=m;j++)
				{
					for(k=1;k<=m;k++)
					{
						dp[i][j]=max(dp[i][j],dp[i-1][k]+mp[k][j]);
					}
				}
			}
		}
		printf("%d\n",*max_element(dp[n-1]+1,dp[n-1]+1+m));
	}
	return 0;
}