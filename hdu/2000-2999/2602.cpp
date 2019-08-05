////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-07 15:47:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2602
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:5596KB
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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 10000000+10
using namespace std;
typedef long long ll;
int dp[1010][1010];
int main()
{
    int t,v,n,vol[1010],val[1010],i,j;
	while(cin>>t)
	{
		while(t--)
		{ 
			cin>>n>>v;
			mem(dp,0);
			mem(vol,0);
			mem(val,0);
			for(i=1;i<=n;i++)
			{
				scanf("%d",&val[i]);
			}
			for(i=1;i<=n;i++)
			{
				scanf("%d",&vol[i]);
			}
			for(i=1;i<=n;i++)
			{
				for(j=0;j<=v;j++)
				{
					if(vol[i]<=j) dp[i][j]=max(dp[i-1][j],dp[i-1][j-vol[i]]+val[i]);
					else dp[i][j]=dp[i-1][j];
				}
			}
			cout<<dp[n][v]<<endl;
		}
	} 
    return 0;
}
