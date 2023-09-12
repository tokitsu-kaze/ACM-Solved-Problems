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
const int MAX=1e2+10;
const ll mod=1e9+6;
int main()
{
	char a[1111];
	int i,len,dp[6];
	while(~scanf("%s",a))
	{
		mem(dp,0);
		len=strlen(a);
		for(i=0;i<len;i++)
		{
			if(a[i]=='h')
			{
				dp[0]++;
			}
			else if(a[i]=='e')
			{
				dp[1]+=dp[0];
			}
			else if(a[i]=='i')
			{
				dp[2]+=dp[1];
				dp[4]+=dp[3];
			}
			else if(a[i]=='d')
			{
				dp[3]+=dp[2];
			}
			if(dp[4]) break;
		}
		if(dp[4]) puts("YES");
		else puts("NO");
	}
	return 0;
}