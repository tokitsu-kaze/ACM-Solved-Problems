////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-04 18:18:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2680
////Problem Title: 
////Run result: Accept
////Run time:374MS
////Run memory:5588KB
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
int flag[1011];
int dis[1011];
int n;
struct node
{
	int num,v;
	friend bool operator<(node a,node b)
	{
		if(a.v==b.v) return a.num<b.num;
		return a.v>b.v;
	}
};
void dijkstra(int s)
{
	int i,pre;
	node t;
	priority_queue<node> q;
	t.num=s;
	t.v=0;
	dis[s]=0;
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
				t.num=i;
				t.v=dis[i];
				q.push(t);
			}
		}
	}
}
int main()
{
	int m,s,i,j,p,q,t,w,a,ans;
	while(cin>>n>>m>>s)
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
			scanf("%d%d%d",&p,&q,&t);
			if(edge[q][p]>t) edge[q][p]=t;
		}
		dijkstra(s);
		ans=INF;
		cin>>w;
		while(w--)
		{
			scanf("%d",&a);
			ans=min(ans,dis[a]);
		}
		if(ans==INF) puts("-1");
		else cout<<ans<<endl;
	}
    return 0; 
}