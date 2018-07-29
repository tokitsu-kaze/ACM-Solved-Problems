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
typedef double LD;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e3+10;
const ll mod=10000;
int main()
{
	int dp[1011],i,n;
	mem(dp,0);
	dp[2]=dp[3]=2;
	for(i=4;i<=1000;i++)
	{
		dp[i]=(dp[i-1]+2*dp[i-2])%mod;
	}
	while(~scanf("%d",&n)&&n)
	{
		printf("%d\n",dp[n]);
	}
	return 0;
}