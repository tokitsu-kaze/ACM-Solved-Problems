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
#include <set>
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define eps 1e-12
#define MAX 200+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
typedef long long ll;
int m,n,x[500*500+10],y[500*500+10],k;
int mp[511][511];
int ans[500*500+10];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
struct node
{
	int x,y;
	int lv;
	int tp;
	friend bool operator<(node a,node b)
	{
		if(a.lv==b.lv) return a.tp>b.tp;
		return a.lv>b.lv;
	}
};
int check(int x,int y)
{
	if(x<0||y<0||x>=m||y>=n||mp[x][y]==INF) return 0;
	return 1;
}
void bfs()
{
	int i,j,temp;
	node t,next;
	priority_queue<node> q;
	for(i=1;i<=k;i++)
	{
		t.x=x[i];
		t.y=y[i];
		t.lv=1;
		t.tp=i;
		q.push(t);
	}
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		temp=INF;
		for(i=0;i<4;i++)
		{
			next.x=t.x+dir[i][0];
			next.y=t.y+dir[i][1];
			next.tp=t.tp;
			next.lv=t.lv;
			if(check(next.x,next.y))
			{
				if(next.lv>=mp[next.x][next.y])
				{
					ans[next.tp]++;
					mp[next.x][next.y]=INF;
					q.push(next);
				}
				else
				{
					temp=min(temp,mp[next.x][next.y]);
				}
			}
		}
		if(temp!=INF)
		{
			t.lv=temp;
			q.push(t);
		}
	}
}
int main()
{
//	freopen("in.txt","r",stdin);	
	int i,j,qs,a;
    while(~scanf("%d%d",&m,&n))
    {
		mem(mp,0);
		mem(ans,0);
		mem(x,0);
		mem(y,0);
		k=0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&mp[i][j]);
				if(mp[i][j]>0)
				{
					x[mp[i][j]]=i;
					y[mp[i][j]]=j;
					k++;
					ans[mp[i][j]]++;
					mp[i][j]=INF;
				}
				else
				{
					mp[i][j]*=-1;
				}
			}
		}
		bfs();
		scanf("%d",&qs);
		while(qs--)
		{
			scanf("%d",&a);
			printf("%d\n",ans[a]);
		}
	}
    return 0;
}