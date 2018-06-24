////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-23 22:24:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2546
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:5592KB
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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,(b),sizeof(a))
#define PI acos(-1.0)
#define MAX 200000+10
using namespace std;
typedef long long ll;
int dp[1010][1010];
int main()
{ 
	int n,m,i,j,a[1010];
	while(cin>>n&&n)
	{
		mem(a,0);
		mem(dp,0);
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		cin>>m;
		sort(a+1,a+n+1);
		if(m<5)
		{
			cout<<m<<endl;
			continue;
		}
		for(i=1;i<n;i++)
		{
			for(j=m-5;j>=0;j--)
			{
				if(j>=a[i]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]+a[i]);
				else dp[i][j]=dp[i-1][j];
			}
		}
		cout<<m-dp[n-1][m-5]-a[n]<<endl;
	}
    return 0;
}