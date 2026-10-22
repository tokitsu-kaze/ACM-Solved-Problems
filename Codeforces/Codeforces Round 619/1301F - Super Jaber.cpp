#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
struct node{int x,y;};
vector<node> pos[42],nowpos[42];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int n,m,k,dis[42][MAX][MAX],col[MAX][MAX];
void bfs(int c)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++) dis[c][i][j]=INF;
	}
	for(i=1;i<=k;i++)
	{
		if(i==c) continue;
		nowpos[i]=pos[i];
	}
	queue<node> q;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(col[i][j]==c)
			{
				q.push({i,j});
				dis[c][i][j]=0;
			}
		}
	}
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			node nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			if(nex.x<1 || nex.x>n || nex.y<1 || nex.y>m) continue;
			if(dis[c][nex.x][nex.y]>dis[c][t.x][t.y]+1)
			{
				dis[c][nex.x][nex.y]=dis[c][t.x][t.y]+1;
				q.push(nex);
			}
		}
		for(auto &nex:nowpos[col[t.x][t.y]])
		{
			if(dis[c][nex.x][nex.y]>dis[c][t.x][t.y]+1)
			{
				dis[c][nex.x][nex.y]=dis[c][t.x][t.y]+1;
				q.push(nex);
			}
		}
		nowpos[col[t.x][t.y]].clear();
	}
}
int main()
{
	int q,i,j,a,b,c,d,ans;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=k;i++) pos[i].clear();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&col[i][j]);
			pos[col[i][j]].push_back({i,j});
		}
	}
	for(i=1;i<=k;i++) bfs(i);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		ans=abs(c-a)+abs(d-b);
		for(i=1;i<=k;i++) ans=min(ans,dis[i][a][b]+dis[i][c][d]+1);
		printf("%d\n",ans);
	}
	return 0;
}
/*
要么直接走，要么至少使用一次传送。
预处理 (x,y) 走到颜色为 k 的格子的最短路。
枚举颜色，以该颜色所有点为起点，跑多源 bfs。
查询时，要么直接走，要么枚举中转颜色。
*/
