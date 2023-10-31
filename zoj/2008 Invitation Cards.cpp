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
#define INF 0x7fffffff//0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 1000000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
struct node
{
	int from,to,cost;
}mp[MAX];
int befo[MAX],aft[MAX];
int dis[MAX];
int flag[MAX];
int n,m;
void init()
{
	int i,j;
	for(i=0;i<=m;i++)
	{
		befo[i]=aft[i]=-1;
	}
}
void spfa(int s,int flag1)
{
	int i,now,to;
	queue<int> q;
	for(i=1;i<=n;i++)
	{
		dis[i]=INF;
		flag[i]=0;
	}
	q.push(s);
	flag[s]=1;
	dis[s]=0;
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		flag[now]=0;
		for(i=befo[now];i!=-1;i=aft[i])
		{
			if(flag1) to=mp[i].to;
			else to=mp[i].from;
			if(dis[to]>dis[now]+mp[i].cost)
			{
				dis[to]=dis[now]+mp[i].cost;
				if(!flag[to])
				{
					flag[to]=1;
					q.push(to);
				}
			}
			
		}
	}
}
int main()
{
    int t,i,sum;
    while(cin>>t)
    {
        while(t--)
        {
			cin>>n>>m;
			init();
			for(i=0;i<m;i++)
			{
				scanf("%d%d%d",&mp[i].from,&mp[i].to,&mp[i].cost);
				aft[i]=befo[mp[i].from];
				befo[mp[i].from]=i;
			}
			sum=0;
			spfa(1,1);
			for(i=2;i<=n;i++)
			{
				sum+=dis[i];
			}
			init();
			for(i=0;i<m;i++)
			{
				aft[i]=befo[mp[i].to];
				befo[mp[i].to]=i;
			}
			spfa(1,0);
			for(i=2;i<=n;i++)
			{
				sum+=dis[i];
			}
			cout<<sum<<endl;
		}
    }
    return 0;
}