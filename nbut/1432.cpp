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
	int i,ans,now;
	node t;
	priority_queue<node> q;
	t.num=1;
	t.v=0;
	dis[1]=0;
	q.push(t);
	ans=0;
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		now=t.num;
		if(flag[now]) continue;
		flag[now]=1;
		ans+=dis[now];
		for(i=1;i<=n;i++)
		{
			if(!flag[i]&&dis[i]>mp[now][i])
			{
				dis[i]=mp[now][i];
				t.num=i;
				t.v=dis[i];
				q.push(t);
			}
		}
	}
	cout<<ans<<endl;
}
int main()
{
    int i,j,t,a,b;
    while(cin>>n)
    {
		mem(flag,0);
		mem(dis,0x3f);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		cin>>t;
		while(t--)
		{
			scanf("%d%d",&a,&b);
			mp[a][b]=mp[b][a]=0;
		}
		prim();
    }
    return 0;
}