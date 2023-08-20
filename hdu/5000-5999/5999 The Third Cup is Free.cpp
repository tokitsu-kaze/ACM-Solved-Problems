////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-27 20:55:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5999
////Problem Title: 
////Run result: Accept
////Run time:3073MS
////Run memory:1992KB
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
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
    int t,n,i,a[100010],sum,j; 
    while(cin>>t)
    {
		for(j=1;j<=t;j++)
		{
			cin>>n;
			for(i=1;i<=n;i++)
			{
				scanf("%d",&a[i]);
			}
			sort(a+1,a+n+1,cmp);
			sum=0;
			for(i=1;i<=n;i++)
			{
				if(i%3==0) continue;
				sum+=a[i];
			}
			printf("Case #%d: %d\n",j,sum);
		}
	}
    return 0;
}