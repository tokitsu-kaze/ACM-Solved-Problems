////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-03 16:19:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1176
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:6688KB
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
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 100000+10
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
int dp[MAX][13];
int main()
{
    int n,i,j,t,x,m;
    while(cin>>n&&n)
    {
		m=0;
		mem(dp,0);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&t);
			dp[t][x+1]++;
			if(t>m) m=t;
		}
		for(i=m-1;i>=0;i--)
		{
			for(j=1;j<=11;j++)
			{
				dp[i][j]+=max(max(dp[i+1][j],dp[i+1][j+1]),dp[i+1][j-1]);
			}
		}
		cout<<dp[0][6]<<endl;
	}
    return 0;
}
