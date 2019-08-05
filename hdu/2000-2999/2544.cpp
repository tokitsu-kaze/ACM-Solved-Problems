////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-04 16:27:53
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1688KB
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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 10000+10
using namespace std;
typedef __int64 ll;
//typedef long long ll;
int n,m;
int edge[111][111];
int flag[111];
int dis[111];
struct node
{
	int num,v;
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
};
void dijstra(int s)
{
	int i,pre;
	priority_queue<node> q;
	node t;
	dis[s]=0;
	t.num=s;
	t.v=0;
	q.push(t);
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		pre=t.num;
		if(flag[pre]) continue;
		flag[pre]=1;
		for(i=2;i<=n;i++)
		{
			if(edge[pre][i]<INF&&dis[i]>dis[pre]+edge[pre][i])
			{
				dis[i]=dis[pre]+edge[pre][i];
				t.num=i;
				t.v=dis[i];
				q.push(t);
			}
		}
	}
}
int main()
{
	int i,j,a,b,c;
	while(cin>>n>>m&&(n+m))
	{
		for(i=1;i<=n;i++)
		{
			flag[i]=0;
			dis[i]=INF;
			for(j=1;j<=n;j++)
			{
				edge[i][j]=INF;
			}
		}
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			edge[a][b]=edge[b][a]=c;
		}
		dijstra(1);
		cout<<dis[n]<<endl;
	}
    return 0;
}