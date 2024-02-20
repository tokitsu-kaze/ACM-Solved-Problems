#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
struct node{int x,y;};
int dir[8][2]={-1,2,-2,1,1,-2,2,-1,-1,-2,-2,-1,1,2,2,1};
int n,m;
int dis[405][405];
void bfs(int x,int y)
{
	int i;
	memset(dis,0x3f,sizeof dis);
	queue<node> q;
	q.push({x,y});
	dis[x][y]=0;
	while(!q.empty())
	{
		auto t=q.front();
		q.pop();
		for(i=0;i<8;i++)
		{
			auto nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			if(nex.x<1||nex.y<1||nex.x>n||nex.y>m) continue;
			if(dis[t.x][t.y]+1<dis[nex.x][nex.y])
			{
				dis[nex.x][nex.y]=dis[t.x][t.y]+1;
				q.push(nex);
			}
		}
	}
}
int main()
{
	int i,j,x,y;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	bfs(x,y);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(dis[i][j]==INF) dis[i][j]=-1;
			printf("%d%c",dis[i][j]," \n"[j==m]);
		}
	}
	return 0;
}
