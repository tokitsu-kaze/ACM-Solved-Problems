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
int mp[1111][1111];
int dis[1111];
int flag[1111];
int n;
struct node
{
	int n,v;
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
};
void dijkstra()
{
	int i;
	node t,now;
	priority_queue<node>q;
	t.n=1;
	t.v=0;
	dis[1]=0;
	q.push(t);
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(flag[t.n]) continue;
		flag[t.n]=1;
		for(i=1;i<=n;i++)
		{
			if(mp[t.n][i]<INF&&dis[i]>dis[t.n]+mp[t.n][i])
			{
				dis[i]=dis[t.n]+mp[t.n][i];
				now.n=i;
				now.v=dis[i];
				q.push(now);
			}
		}
	}
}
int main()
{
	int t,a,b,c;
	while(~scanf("%d%d",&t,&n))
	{
		mem(mp,0x3f);
		mem(dis,0x3f);
		mem(flag,0);
		while(t--)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(mp[a][b]>c) mp[a][b]=mp[b][a]=c;
		}
		dijkstra();
		printf("%d\n",dis[n]);
	}
	return 0;
}