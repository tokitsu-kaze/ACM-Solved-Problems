////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-07 17:16:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1203
////Problem Title: 
////Run result: Accept
////Run time:15MS
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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 10000+10
using namespace std;
typedef long long ll;
int main()
{
    int n,m,i,j,a[MAX];
    double b[MAX],dp[MAX];
	while(cin>>n>>m&&(n+m))
	{
		fill(dp,dp+MAX,1);
		mem(a,0);
		mem(b,0);
		for(i=0;i<m;i++)
		{
			scanf("%d%lf",&a[i],&b[i]);
		}
		for(i=0;i<m;i++)
		{
			for(j=n;j>=a[i];j--)
			{
				dp[j]=min(dp[j],dp[j-a[i]]*(1-b[i]));
			}
		}
		printf("%.1lf%%\n",(1-dp[n])*100);
	} 
    return 0;
}
