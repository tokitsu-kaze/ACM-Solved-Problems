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
#define mem(a,b) memset(a,(b),sizeof(a))
#define PI acos(-1.0)
#define MAX 200000+10
using namespace std;
typedef long long ll;
int main()
{
	int n,h[10010],dp[10010][2],i;
	while(cin>>n)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&h[i]);
		}
		mem(dp,0x3f);
		dp[0][0]=dp[0][1]=0;
		for(i=1;i<=n;i++)
		{
			dp[i][0]=min(dp[i-1][1],dp[i-1][0])+h[i];//走上来
			if(i==1) dp[i][1]=dp[i-1][1];
			else dp[i][1]=min(dp[i-1][0],dp[i-2][0]);//飞一下 
		}
		cout<<min(dp[n][0],dp[n][1])<<endl;
	}
    return 0;
}