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
double mp[1111][1111];
double dis[1111];
int flag[1111];
int n;
struct node
{
	int n;
	double v;
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
	q.push(t);
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(flag[t.n]) continue;
		flag[t.n]=1;
		for(i=1;i<=n;i++)
		{
			if(dis[i]>=max(dis[t.n],mp[t.n][i]))
			{
				dis[i]=max(dis[t.n],mp[t.n][i]);
				now.v=dis[i];
				now.n=i;
				q.push(now);
			}
		}
	}
}
int main()
{
	int x[211],y[211],cas=1,i,j;
	double a,b,c;
	while(~scanf("%d",&n)&&n)
	{
		mem(mp,0x3f);
		mem(flag,0);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
		}
		for(i=1;i<=n-1;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				a=x[j]-x[i];
				b=y[j]-y[i];
				c=sqrt(a*a+b*b);
				mp[i][j]=mp[j][i]=c;
			}
		}
		for(i=1;i<=n;i++)
		{
			dis[i]=mp[1][i];
		}
		dijkstra();
		printf("Scenario #%d\n",cas++);
		printf("Frog Distance = %.3f\n\n",dis[2]);
	}
	return 0;
}