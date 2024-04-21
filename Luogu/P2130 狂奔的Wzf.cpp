#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
struct node{int x,y,v;};
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int bit[1010][1010],n,m,vis[1010][1010];
char mp[1010][1010];
int cal(int x1,int y1,int x2,int y2)
{
	return bit[x2][y2]-bit[x1-1][y2]-bit[x2][y1-1]+bit[x1-1][y1-1];
}
int bfs(int sx,int sy)
{
	int i,j;
	queue<node> q;
	q.push({sx,sy,0});
	vis[sx][sy]=1;
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		if(mp[t.x][t.y]=='#') return t.v;
		for(i=0;i<4;i++)
		{
			for(j=0;j<10;j++)
			{
				node nex=t;
				nex.x+=(1<<j)*dir[i][0];
				nex.y+=(1<<j)*dir[i][1];
				if(nex.x<1||nex.y<1||nex.x>n||nex.y>m) continue;
				if(cal(t.x,t.y,nex.x,nex.y)) continue;
				if(vis[nex.x][nex.y]) continue;
				vis[nex.x][nex.y]=1;
				nex.v++;
				q.push(nex);
			}
		}
	}
	return -1;
}
int main()
{
	int i,j;
	scanf("%d%d",&n,&m);
	memset(bit[0],0,sizeof bit[0]);
	for(i=1;i<=n;i++)
	{
		scanf("%s",mp[i]+1);
		bit[i][0]=0;
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]=='X') bit[i][j]=1;
			else bit[i][j]=0;
			bit[i][j]+=bit[i-1][j]+bit[i][j-1]-bit[i-1][j-1];
			vis[i][j]=0;
		}
	}
	printf("%d\n",bfs(1,1));
	return 0;
}
