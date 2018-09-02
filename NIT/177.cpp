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
const ll mod=1e9+7;
int dp[5][MAX],ans[MAX];
void init()
{
	int i;
	mem(dp,0);
	mem(ans,0);
	dp[0][1]=1;
	dp[1][1]=1;
	ans[1]=dp[0][1]+dp[1][1];
	for(i=2;i<MAX;i++)
	{
		
		dp[0][i]=(dp[1][i-1]+dp[1][i-2])%mod;
		dp[1][i]=(dp[0][i-1]+dp[0][i-2])%mod;
		ans[i]=(dp[0][i]+dp[1][i])%mod;
	}
}
int main()
{
	int t,n;
	init();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
	return 0;
}