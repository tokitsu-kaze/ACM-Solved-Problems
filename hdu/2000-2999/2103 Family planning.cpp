////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-16 16:37:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2103
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1572KB
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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define eps 1e-9
#define MAX 10000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
	ll t,m,n,a,cnt,flag,ans,i;
	while(~scanf("%I64d",&t))
	{
		while(t--)
		{
			scanf("%I64d%I64d",&m,&n);
			flag=0;
			if(n>m)
			{
				cnt=n-m-1;
				for(i=0;i<m;i++)
				{
					scanf("%I64d",&a);
					if(flag) cnt++;
					if(a)
					{
						flag=1;
					}
				}
				for(i=0;i<n-m;i++)
				{
					scanf("%I64d",&a);
				}
			}
			else if(n<=m)
			{
				cnt=-1;
				for(i=0;i<n;i++)
				{
					scanf("%I64d",&a);
					if(flag) cnt++;
					if(a)
					{
						flag=1;
					}
				}
			}
			ans=0;
			for(i=0;i<=cnt;i++)
			{
				ans+=(1<<i);
			}
			if(cnt==-1) puts("0 RMB");
			else printf("%I64d0000 RMB\n",ans);
		}
	}
    return 0;
}