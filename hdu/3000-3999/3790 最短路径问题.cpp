////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-04 18:52:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3790
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:9680KB
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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 10000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int edge[1011][1011];
int val[1011][1011];
int flag[1011];
int dis[1011];
int cost[1011];
int n;
struct node
{
	int num,v,cost;
	friend bool operator<(node a,node b)
	{
		if(a.v==b.v) return a.cost>b.cost;
		return a.v>b.v;
	}
};
void dijkstra(int s)
{
	int i,pre,c;
	node t;
	priority_queue<node> q;
	t.num=s;
	t.v=0;
	t.cost=0;
	dis[s]=0;
	cost[s]=0;
	q.push(t);
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		pre=t.num;
		if(flag[pre]) continue;
		flag[pre]=1;
		for(i=1;i<=n;i++)
		{
			if(edge[pre][i]<INF&&dis[i]>dis[pre]+edge[pre][i])
			{
				dis[i]=dis[pre]+edge[pre][i];
				cost[i]=cost[pre]+val[pre][i];
				t.v=dis[i];
				t.cost=cost[i];
				t.num=i;
				q.push(t);
			}
			else if(edge[pre][i]<INF&&dis[i]==dis[pre]+edge[pre][i])
			{
				dis[i]=dis[pre]+edge[pre][i];
				cost[i]=cost[pre]+val[pre][i];
				t.v=dis[i];
				t.cost=cost[i];
				t.num=i;
				q.push(t);
			}
		}
	}
}
int main()
{
	int m,i,j,a,b,d,p,s,t;
	while(cin>>n>>m&&(n+m))
	{
		for(i=1;i<=n;i++)
		{
			flag[i]=0;
			dis[i]=INF;
			cost[i]=INF;
			for(j=1;j<=n;j++)
			{
				edge[i][j]=INF;
				val[i][j]=INF;
			}
		}
		while(m--)
		{
			scanf("%d%d%d%d",&a,&b,&d,&p);
			if(edge[a][b]>d)
			{
				edge[a][b]=edge[b][a]=d;
				val[a][b]=val[b][a]=p;
			}
			else if(edge[a][b]==d&&val[a][b]>p)
			{
				val[a][b]=val[b][a]=p;
			}
		}
		cin>>s>>t;
		dijkstra(s);
		cout<<dis[t]<<" "<<cost[t]<<endl;
	}
    return 0; 
}