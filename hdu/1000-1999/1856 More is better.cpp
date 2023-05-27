////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-06 21:27:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1856
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:79852KB
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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 10000000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int pre[MAX],cnt[MAX];
void init()
{
	int i;
	for(i=1;i<=MAX;i++)
	{
		pre[i]=i;
		cnt[i]=1;
	}
}
int find(int x)
{
	if(pre[x]!=x) pre[x]=find(pre[x]);
	return pre[x];
}
void merge(int a,int b)
{
	int ta,tb;
	ta=find(a);
	tb=find(b);
	if(ta!=tb)
	{
		pre[ta]=tb;
		cnt[tb]+=cnt[ta];
	}
}
int main()
{
    int t,i,a,b,n,ans;
    while(~scanf("%d",&t))
    {
		if(!t)
		{
			puts("1");
			continue;
		}
		init();
		n=0;
		while(t--)
		{
			scanf("%d%d",&a,&b);
			n=max(n,max(a,b));
			merge(a,b);
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			ans=max(ans,cnt[i]);
		}
		printf("%d\n",ans);
	}
    return 0;
}