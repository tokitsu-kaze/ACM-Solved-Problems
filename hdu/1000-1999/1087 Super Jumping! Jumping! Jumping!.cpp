////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-18 18:10:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1087
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1668KB
//////////////////System Comment End//////////////////
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
int main()
{
	int n,i,j,a[1111],dp[1111],ans;
	while(~scanf("%d",&n)&&n)
	{
		mem(a,0);
		mem(dp,0);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		ans=-1;
		for(i=0;i<n;i++)
		{
			int p=-1,v=0;
			for(j=0;j<i;j++)
			{
				if(dp[j]>v&&a[j]<a[i])
				{
					p=j;
					v=dp[j];
				}
			}
			if(p==-1) dp[i]+=a[i];
			else dp[i]=v+a[i];
			ans=max(ans,dp[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
