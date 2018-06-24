////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-02 21:18:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2153
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1580KB
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
#define MAX 10000+10
using namespace std;
typedef long long ll;
int main()
{
	int n,i,j;
	while(cin>>n&&n)
	{
		if(n==1)
		{
			printf("%3d\n",1);
			continue;
		}
		for(i=1;i<=n;i++)
		{
			printf("%3d",i);
		}
		puts("");
		for(i=1;i<=n-2;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(j==1) printf("%3d",n*4-4-i+1);
				else if(j==n) printf("%3d",n+i);
				else printf("   ");
			}
			puts("");
		}
		for(i=0;i<n;i++)
		{
			printf("%3d",n*4-4-i-n+2);
		}
		puts("");
	}
    return 0;
}