#include<bits/stdc++.h>
using namespace std;
struct node{int x,y;};
int dir[12][2]={2,1,1,2,-2,1,-1,2,2,-1,1,-2,-1,-2,-2,-1,
					  2,2,2,-2,-2,2,-2,-2};
const int n=100;
const int m=100;
int dis[105][105];
int bfs(int x,int y)
{
	int i;
	memset(dis,0x3f,sizeof dis);
	queue<node> q;
	q.push({x,y});
	dis[x][y]=0;
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		if(t.x==1&&t.y==1) return dis[1][1];
		for(i=0;i<12;i++)
		{
			node nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			if(nex.x>n||nex.x<1||nex.y>m||nex.y<1) continue;
			if(dis[nex.x][nex.y]>dis[t.x][t.y]+1)
			{
				dis[nex.x][nex.y]=dis[t.x][t.y]+1;
				q.push(nex);
			}
		}
	}
	return -1;
}
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	printf("%d\n",bfs(x,y));
	scanf("%d%d",&x,&y);
	printf("%d\n",bfs(x,y));
	return 0;
}
