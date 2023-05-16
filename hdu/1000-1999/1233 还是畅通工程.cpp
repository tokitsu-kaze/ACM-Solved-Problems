////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-05 17:03:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1233
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:1668KB
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
#define MAX 1000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int mp[111][111];
int flag[111];
int dis[111];
int n;
struct node
{
	int num,v;
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
};
void prim()
{
	int i,ans=0;
	priority_queue<node>q;
	node now,next;
	now.num=1;
	now.v=0;
	q.push(now);
	while(!q.empty())
	{
		now=q.top();
		q.pop();
		if(flag[now.num]) continue;
		flag[now.num]=1;
		ans+=now.v;
		for(i=1;i<=n;i++)
		{
			if(!flag[i]&&dis[i]>mp[now.num][i])
			{
				dis[i]=mp[now.num][i];
				next.num=i;
				next.v=dis[i];
				q.push(next);
			}
		}
	}
	cout<<ans<<endl;
}
int main()
{
    int a,b,c,i;
    while(cin>>n&&n)
    {
		mem(flag,0);
		mem(dis,0x3f);
		mem(mp,0x3f);
		for(i=0;i<n*(n-1)/2;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(mp[a][b]>c) mp[a][b]=mp[b][a]=c;
		}
		prim();
    }
    return 0;
}