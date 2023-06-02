////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-16 08:50:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2682
////Problem Title: 
////Run result: Accept
////Run time:124MS
////Run memory:7120KB
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
#define MAX 1000000+10
#define EDGE 2000000+10//±ßµÄÌõÊý 
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int mp[611][611];
int dis[611];
int flag[611];
int n,prime[MAX],w[611],ans;
struct node
{
	int n,v;
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
};
void prim(int s)
{
	int i;
	node t,next;
	priority_queue<node> q;
	t.n=s;
	t.v=0;
	dis[s]=0;
	q.push(t);
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(flag[t.n]) continue;
		flag[t.n]=1;
		ans+=t.v;
		for(i=1;i<=n;i++)
		{
			if(mp[t.n][i]!=INF&&dis[i]>mp[t.n][i])
			{
				dis[i]=mp[t.n][i];
				next.n=i;
				next.v=dis[i];
				q.push(next);
			}
		}
	}
}
int main()
{
	int t,i,j,temp;
	mem(prime,0);
	prime[0]=prime[1]=1;
	temp=sqrt(1.0*MAX);
	for(i=2;i<=temp;i++)
	{
		if(!prime[i])
		{
			for(j=i+i;j<=MAX;j+=i)
			{
				prime[j]=1;
			}
		}
	}
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			mem(mp,0x3f);
			mem(dis,0x3f);
			mem(flag,0);
			mem(w,0);
			for(i=1;i<=n;i++)
			{
				scanf("%d",&w[i]);
			}
			for(i=1;i<=n-1;i++)
			{
				for(j=i+1;j<=n;j++)
				{
					if(!prime[w[i]]||!prime[w[j]]||!prime[w[i]+w[j]])
					{
						mp[i][j]=mp[j][i]=min(min(w[i],w[j]),abs(w[i]-w[j]));
					}
				}
			}
			ans=0;
			prim(1);
			if(dis[n]==INF) puts("-1");
			else printf("%d\n",ans);
		}
	}
    return 0;
}