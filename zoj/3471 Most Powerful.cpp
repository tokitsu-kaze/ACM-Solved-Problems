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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=100+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int dp[1<<12];
int main()
{
	int i,j,k,n,mp[13][13],ans;
	while(~scanf("%d",&n)&&n)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		mem(dp,0);
		for(i=0;i<(1<<n);i++)
		{
			for(j=1;j<=n;j++)
			{
				if(!(i&(1<<j-1)))
				{
					for(k=1;k<=n;k++)
					{
						if(!(i&(1<<k-1))&&j!=k)
						{
							dp[i|(1<<k-1)]=max(dp[i|(1<<k-1)],dp[i]+mp[j][k]);
						}
					}
				}
			}
		}
		ans=-INF;
		for(i=1;i<(1<<n);i++)
		{
			ans=max(ans,dp[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}