////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-06 22:35:53
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2571
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:1780KB
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
#define MAX 100000+10
using namespace std;
typedef long long ll;
int main()
{
    int t,n,m,a[25][1010],dp[25][1010],i,j,k;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n>>m;
			mem(a,0);
			mem(dp,0);
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=m;j++)
				{
					scanf("%d",&a[i][j]);
				}
			}
			for(i=0;i<n;i++)
			{
				dp[i][0]=-INF;
			}
			for(i=0;i<m;i++)
			{
				dp[0][i]=-INF;
			}
			dp[1][0]=dp[0][1]=0;
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=m;j++)
				{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
					for(k=2;k<=m;k++)
					{
						if(j%k==0) dp[i][j]=max(dp[i][j],dp[i][j/k]);
					}
					dp[i][j]+=a[i][j];
				}
			}
			cout<<dp[n][m]<<endl;
		}
	} 
    return 0;
}
