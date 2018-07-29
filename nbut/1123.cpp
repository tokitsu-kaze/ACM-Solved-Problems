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
#include <ctime>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const ll mod=1e9+7;
const int MAX=100000+10; //MAX为数组大小
ll dp[4010];
int main()
{
	ll a,b,i,j,ans;
	mem(dp,0);
	for(i=2;i<=4000;i++)
	{
		if(i%2) dp[i]=dp[i-1]+(i-1)/2;
		else dp[i]=dp[i-1]+i/2;
	}
	while(~scanf("%I64d%I64d",&a,&b))
	{
		printf("%I64d\n",dp[a]*dp[b]);
	}
	return 0;
}