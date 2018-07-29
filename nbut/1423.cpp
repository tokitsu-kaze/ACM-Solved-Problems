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
int main()
{
	int t,n,i,j,mp[111][111],dp[111][111];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		mem(mp,0);
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		mem(dp,0);
		for(i=n-1;i>=0;i--)
		{
			for(j=0;j<=i;j++)
			{
				dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+mp[i][j];
			}
		}
		printf("%d\n",dp[0][0]);
	}
	return 0;
}