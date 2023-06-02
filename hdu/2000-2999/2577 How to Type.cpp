////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-17 21:52:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2577
////Problem Title: 
////Run result: Accept
////Run time:0MS
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
const double eps=1e-6;
const int MAX=100000+10;
const ll mod=1e6;
int main()
{
	int t,dp[111][2],len,i;
	char a[111];
	while(~scanf("%d",&t))
	{
		getchar();
		while(t--)
		{
			mem(a,0);
			scanf("%s",a+1);
			mem(dp,0);
			len=strlen(a+1);
			dp[0][0]=1;
			dp[0][1]=0;
			for(i=1;i<=len;i++)
			{
				if(a[i]>='A'&&a[i]<='Z')
				{
					dp[i][0]=min(dp[i-1][0]+1,dp[i-1][1]+2);
					dp[i][1]=min(dp[i-1][0]+2,dp[i-1][1]+2);
				}
				else
				{
					dp[i][1]=min(dp[i-1][0]+2,dp[i-1][1]+1);
					dp[i][0]=min(dp[i-1][0]+2,dp[i-1][1]+2);
				}
			}
			printf("%d\n",min(dp[len][0]+1,dp[len][1]));
		}
	}
	return 0;
}
