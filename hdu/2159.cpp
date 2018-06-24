////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-27 20:07:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2159
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1652KB
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
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 100000+10
using namespace std;
typedef long long ll;
int dp[110][110];
int main()
{
    int n,m,k,s,a[110],b[110],i,j,f; 
    while(cin>>n>>m>>k>>s)
    {
		for(i=1;i<=k;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
		}
		mem(dp,0);
		for(i=1;i<=k;i++)//i种怪 
		{
			for(j=1;j<=s;j++)//杀j只 
			{
				for(f=b[i];f<=m;f++)//使用f忍耐度
				{
					dp[j][f]=max(dp[j][f],dp[j-1][f-b[i]]+a[i]);
				} 
			}
		}
		if(dp[s][m]<n)
		{
			puts("-1");
			continue;
		}
		for(i=1;i<=m;i++)
		{
			if(dp[s][i]>=n) break;
		}
		cout<<m-i<<endl;
	}
    return 0;
}