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
const ll mod=1e6;
struct node
{
	int a,b,v;
	void input()
	{
		scanf("%d%d%d",&a,&b,&v);
	}
}a[1111];
int dp[1111][1111];
int main()
{
	int n,k,i,j,ans;
	while(~scanf("%d%d",&n,&k))
	{
		mem(a,0);
		for(i=1;i<=n;i++)
		{
			a[i].input();
		}
		mem(dp,0);
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=k;j++)
			{
				if(j>=a[i].v) dp[i][j]=min(dp[i-1][j]+a[i].a,dp[i-1][j-a[i].v]+a[i].b);
				else dp[i][j]=dp[i-1][j]+a[i].a;
			}
		}
		printf("%d\n",dp[n][k]);
	}
	return 0;
}
/*
4 10
4 3 2
4 2 3
5 3 3
5 3 4

4 10
4 3 4
4 2 3
5 3 3
5 3 4
*/