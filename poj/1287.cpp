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
#define MAX 50000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int n,ans;
int mp[111][111];
int dis[111];
int flag[111];
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
	priority_queue<node>q;
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
			if(!flag[i]&&dis[i]>mp[t.n][i])
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
	int m,a,b,c;
	while(~scanf("%d",&n)&&n)
	{
		mem(mp,0x3f);
		mem(dis,0x3f);
		mem(flag,0);
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(mp[a][b]>c) mp[a][b]=mp[b][a]=c;
		}
		ans=0;
		prim(1);
		printf("%d\n",ans);
	}
	return 0;
}