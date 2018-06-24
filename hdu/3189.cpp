////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-15 09:27:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3189
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1568KB
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
const int MAX=100000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int ans[1111],lim;
void init()
{
	int i,j,cnt;
	mem(ans,0);
	lim=0;
	for(i=1;i<=1000;i++)
	{
		cnt=0;
		for(j=1;j<=sqrt(i);j++)
		{
			if(i%j==0)
			{
				if(j!=i/j) cnt+=2;
				else cnt++;
			}
		}
		ans[i]=cnt;
		lim=max(lim,cnt);
	}
}
int main()
{
	int t,n,flag;
	init();
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			if(n>lim)
			{
				puts("-1");
				continue;
			}
			flag=0;
			for(int i=1;i<=1000;i++)
			{
				if(ans[i]==n)
				{
					printf("%d\n",i);
					flag=1;
					break;
				}
			}
			if(!flag) puts("-1");
		}
	}
	return 0;
}