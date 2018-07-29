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
const int MAX=40000+10;
const ll mod=1e6;
int dp[1111][1111];
int main()
{
	int lena,lenb,i,j;
	char a[1111],b[1111];
	while(~scanf("%s %s",a+1,b+1))
	{
		lena=strlen(a+1);
		lenb=strlen(b+1);
		mem(dp,0);
		for(i=1;i<=lena;i++)
		{
			for(j=1;j<=lenb;j++)
			{
				if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		printf("%d\n",dp[lena][lenb]);
	}
	return 0;
}