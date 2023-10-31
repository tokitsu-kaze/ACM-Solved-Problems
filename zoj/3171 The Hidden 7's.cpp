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
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
char a[100010];
int main()
{
	ll i,len,dp[11];
	while(~scanf("%s",a))
	{
		mem(dp,0);
		len=strlen(a);
		for(i=0;i<len;i++)
		{
			if(a[i]=='s'||a[i]=='S') dp[1]++;
			else if(a[i]=='e'||a[i]=='E')
			{
				dp[2]+=dp[1];
				dp[4]+=dp[3];
			}
			else if(a[i]=='v'||a[i]=='V') dp[3]+=dp[2];
			else if(a[i]=='n'||a[i]=='N') dp[5]+=dp[4];
		}
		printf("%lld\n",dp[5]);
	}
	return 0;
}