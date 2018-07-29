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
const ll mod=1e4;
struct node
{
	int x,y;
}pre[111][111];
int main()
{
	int t,n,i,j,mp[111][111],dp[111][111],cnt[111][111];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		mem(mp,0);
		mem(cnt,0);
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				scanf("%d",&mp[i][j]);
				if(i==n-1) cnt[i][j]=1;
			}
		}
		mem(dp,0);
		mem(pre,0);
		for(i=n-1;i>=0;i--)
		{
			for(j=0;j<=i;j++)
			{
				if(dp[i+1][j]>dp[i+1][j+1])
				{
					dp[i][j]=dp[i+1][j]+mp[i][j];
					cnt[i][j]=cnt[i+1][j];
					pre[i][j].x=i+1;
					pre[i][j].y=j;
				}
				else if(dp[i+1][j]<dp[i+1][j+1])
				{
					dp[i][j]=dp[i+1][j+1]+mp[i][j];
					cnt[i][j]=cnt[i+1][j+1];
					pre[i][j].x=i+1;
					pre[i][j].y=j+1;
				}
				else
				{
					dp[i][j]=dp[i+1][j]+mp[i][j];
					cnt[i][j]=cnt[i+1][j]+1;
				}
			}
		}
		printf("%d\n",dp[0][0]);
		if(cnt[0][0]>1) puts("There are several solutions!");
		else
		{
			printf("(0, 0)");
			node temp=pre[0][0];
			while(temp.x+temp.y)
			{
				printf(" -> (%d, %d)",temp.x,temp.y);
				temp=pre[temp.x][temp.y];
			}
			puts("");
		}
	}
	return 0;
}