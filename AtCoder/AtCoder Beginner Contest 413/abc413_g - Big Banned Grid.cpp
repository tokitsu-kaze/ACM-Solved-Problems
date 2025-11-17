#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
struct node{int x,y;};
int dir[8][2]={0,1,1,0,0,-1,-1,0,1,1,1,-1,-1,1,-1,-1};
int x[MAX],y[MAX];
int main()
{
	int n,m,k,i,ok;
	map<pair<int,int>,int> mp,vis;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=k;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		mp[{x[i],y[i]}]=1;
	}
	ok=1;
	queue<node> q;
	vis.clear();
	for(i=2;i<=m;i++)
	{
		q.push({0,i});
		vis[{0,i}]=1;
	}
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		for(i=0;i<8;i++)
		{
			node nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			if(nex.x>n||nex.y<=0) ok=0;
			if(mp.count({nex.x,nex.y}))
			{
				if(!vis.count({nex.x,nex.y}))
				{
					q.push(nex);
					vis[{nex.x,nex.y}]=1;
				}
			}
		}
	}
	
	while(!q.empty()) q.pop();
	vis.clear();
	for(i=2;i<m;i++)
	{
		q.push({n+1,i});
		vis[{n+1,i}]=1;
	}
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		for(i=0;i<8;i++)
		{
			node nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			if(nex.y>m) ok=0;
			if(mp.count({nex.x,nex.y}))
			{
				if(!vis.count({nex.x,nex.y}))
				{
					q.push(nex);
					vis[{nex.x,nex.y}]=1;
				}
			}
		}
	}
	
	while(!q.empty()) q.pop();
	vis.clear();
	for(i=2;i<=n;i++)
	{
		q.push({i,0});
		vis[{i,0}]=1;
	}
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		for(i=0;i<8;i++)
		{
			node nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			if(nex.y>m||nex.x<=0) ok=0;
			if(mp.count({nex.x,nex.y}))
			{
				if(!vis.count({nex.x,nex.y}))
				{
					q.push(nex);
					vis[{nex.x,nex.y}]=1;
				}
			}
		}
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
/*
10 10 3
1 2
2 1
2 2

10 10 3
10 9
9 10
9 9
*/
