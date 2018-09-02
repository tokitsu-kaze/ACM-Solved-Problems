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
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,m,t,w[111],v[111],i,j,dp[111][1111];
	while(~scanf("%d",&n))
	{
		scanf("%d%d",&m,&t);
		for(i=1;i<=t;i++)
		{
			scanf("%d%d",&w[i],&v[i]);
		}
		mem(dp,0);
		for(i=1;i<=t;i++)
		{
			for(j=n;j>=0;j--)
			{
				if(j>=w[i]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
				else dp[i][j]=dp[i-1][j];
			}
		}
		printf("%d",dp[t][n]);
		if(dp[t][n]>m) puts(" yes");
		else puts(" no");
	}
	return 0;
}