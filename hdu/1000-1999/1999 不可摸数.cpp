////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-05 13:07:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1999
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:5476KB
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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int sum[MAX];
int main()
{
	int n,t,i,j,ans[1111],m;
	mem(ans,0);
	mem(sum,0);
	m=MAX/2;
	for(i=1;i<=m;i++)
	{
		for(j=i+i;j<=MAX;j+=i)
		{
			sum[j]+=i;
		}
	}
	for(i=1;i<=MAX;i++)
	{
		if(sum[i]<=1000) ans[sum[i]]=1;
	}
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			if(ans[n]) puts("no");
			else puts("yes");
		}
	}
	return 0;
}