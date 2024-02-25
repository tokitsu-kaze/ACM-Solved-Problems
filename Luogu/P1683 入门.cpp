#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=20+10;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
struct node{int x,y;};
char mp[MAX][MAX];
int n,m,sx,sy,vis[MAX][MAX];
int bfs()
{
	int i,cnt;
	memset(vis,0,sizeof vis);
	queue<node> q;
	q.push({sx,sy});
	vis[sx][sy]=1;
	cnt=1;
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			node nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			if(nex.x<1||nex.y<1||nex.x>n||nex.y>m) continue;
			if(mp[nex.x][nex.y]=='#') continue;
			if(!vis[nex.x][nex.y])
			{
				vis[nex.x][nex.y]=1;
				cnt++;
				q.push(nex);
			}
		}
	}
	return cnt;
}
int main()
{
	int i,j;
	scanf("%d%d",&n,&m);
	swap(n,m);
	for(i=1;i<=n;i++)
	{
		scanf("%s",mp[i]+1);
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]=='@')
			{
				sx=i;
				sy=j;
			}
		}
	}
	printf("%d\n",bfs());
	return 0;
}
