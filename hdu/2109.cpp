////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-16 16:44:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2109
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1564KB
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
	int n,i,a[111],b[111],cnt1,cnt2;
	while(~scanf("%d",&n)&&n)
	{
		mem(a,0);
		mem(b,0);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
		}
		sort(a,a+n);
		sort(b,b+n);
		cnt1=cnt2=0;
		for(i=0;i<n;i++)
		{
			if(a[i]>b[i]) cnt1+=2;
			else if(a[i]==b[i])
			{
				cnt1++;
				cnt2++;
			}
			else if(a[i]<b[i]) cnt2+=2;
		}
		printf("%d vs %d\n",cnt1,cnt2);
	}
    return 0;
}