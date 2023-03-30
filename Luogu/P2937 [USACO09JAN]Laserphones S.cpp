#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
struct node
{
	int x,y,v,d;
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
}be,en;
char mp[105][105];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int n,m,dis[105][105][5];
int bfs()
{
	int i;
	node x,nex;
	priority_queue<node> q;
	memset(dis,0x3f,sizeof dis);
	be.v=0;
	be.d=-1;
	q.push(be);
	for(i=0;i<4;i++) dis[be.x][be.y][i]=0;
	while(!q.empty())
	{
		x=q.top();
		q.pop();
		for(i=0;i<4;i++)
		{
			nex=x;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			nex.d=i;
			if(nex.x<0||nex.x>=n||nex.y<0||nex.y>=m) continue;
			if(mp[nex.x][nex.y]=='*') continue;
			if(x.d!=-1 && x.d!=nex.d)
			{
				if((x.d+1)%4==nex.d || (x.d-1+4)%4==nex.d) nex.v++;
				else if((x.d+2)%4==nex.d || (x.d-2+4)%4==nex.d) nex.v+=2;
			}
			if(nex.v<dis[nex.x][nex.y][nex.d])
			{
				dis[nex.x][nex.y][nex.d]=nex.v;
				q.push(nex);
			}
		}
	}
	int ans=INF;
	for(i=0;i<4;i++) ans=min(ans,dis[en.x][en.y][i]);
	if(ans==INF) ans=-1;
	return ans;
}
int main()
{
	int i,j;
	scanf("%d%d",&m,&n);
	be={-1,-1};
	for(i=0;i<n;i++)
	{
		scanf("%s",mp[i]);
		for(j=0;j<m;j++)
		{
			if(mp[i][j]=='C')
			{
				if(be.x==-1) be={i,j};
				else en={i,j};
			}
		}
	}
	printf("%d\n",bfs());
	return 0;
}
