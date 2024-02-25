#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=1e3+10;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
struct node{int x,y;};
char mp[MAX][MAX];
int n,sx,sy,tx,ty,dis[MAX][MAX];
int bfs()
{
	int i;
	memset(dis,0x3f,sizeof dis);
	queue<node> q;
	q.push({sx,sy});
	dis[sx][sy]=0;
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			node nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			if(nex.x<1||nex.y<1||nex.x>n||nex.y>n) continue;
			if(mp[nex.x][nex.y]=='1') continue;
			if(dis[t.x][t.y]+1<dis[nex.x][nex.y])
			{
				dis[nex.x][nex.y]=dis[t.x][t.y]+1;
				q.push(nex);
			}
		}
	}
	return dis[tx][ty];
}
int main()
{
	int t,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	printf("%d\n",bfs());
	return 0;
}
