////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-24 12:35:10
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1248
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1636KB
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
int dp[10010],val[]={150,200,350};
int main()
{ 
	int t,m,i,j;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>m;
			mem(dp,0);
			for(i=0;i<3;i++)
			{
				for(j=val[i];j<=m;j++)
				{
					dp[j]=max(dp[j],dp[j-val[i]]+val[i]);
				}
			}
			cout<<m-dp[m]<<endl;
		}
	}
    return 0;
}