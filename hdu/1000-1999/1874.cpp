////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-05 10:25:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1874
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1704KB
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
#define MAX 10000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int edge[211][211];
int dis[211];
int flag[211];
int n;
void spfa(int s)
{
	int i,now;
	queue<int> q;
	q.push(s);
	flag[s]=1;
	dis[s]=0;
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		flag[now]=0;
		for(i=0;i<n;i++)
		{
			if(dis[i]>dis[now]+edge[now][i])
			{
				dis[i]=dis[now]+edge[now][i];
				if(!flag[i])
				{
					q.push(i);
					flag[i]=1;
				}
			}
		}
	}
}
int main()
{
    int m,i,j,s,e,a,b,c;
    while(cin>>n>>m)
    {
        for(i=0;i<n;i++)
        {
			flag[i]=0;
			dis[i]=INF;
			for(j=0;j<n;j++)
			{
				if(i==j) edge[i][j]=0;
				else edge[i][j]=INF;
			}
		}
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(edge[a][b]>c) edge[a][b]=edge[b][a]=c;
		}
		cin>>s>>e;
		spfa(s);
		if(dis[e]==INF) puts("-1");
		else cout<<dis[e]<<endl;
    }
    return 0;
}