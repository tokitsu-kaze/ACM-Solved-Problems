////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-15 13:06:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2647
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1964KB
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
int in_degree[MAX];
int n,cnt,sum[MAX];
int head[MAX];
struct node
{
	int next,to,w;
}mp[EDGE];
void topsort()
{
	int i,t,to;
	queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(!in_degree[i])
		{
			q.push(i);
			sum[i]=888;
		}
	}
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		cnt++;
		for(i=head[t];i!=-1;i=mp[i].next)
		{
			to=mp[i].to;
			in_degree[to]--;
			if(!in_degree[to])
			{
				q.push(to);
				sum[to]=sum[t]+1;
			}
		}
	}
}
int main()
{
	int m,i,a,b,ans;
	while(~scanf("%d%d",&n,&m))
	{
		fill(head+1,head+1+n,-1);
		mem(in_degree,0);
		mem(sum,0);
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			mp[i].to=a;
			mp[i].next=head[b];
			head[b]=i;
			in_degree[a]++;
		}
		cnt=0;
		topsort();
		if(cnt!=n)
		{
			puts("-1");
			continue;
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			ans+=sum[i];
		}
		printf("%d\n",ans);
	}
    return 0;
}