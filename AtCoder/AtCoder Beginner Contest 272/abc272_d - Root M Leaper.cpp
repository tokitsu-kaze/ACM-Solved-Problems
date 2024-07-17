#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int sqr(int x){return x*x;}
struct node{int x,y;};
vector<int> dx,dy;
int dis[405][405],n;
void bfs(int x,int y)
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
		for(i=0;i<dx.size();i++)
		{
			node nex=t;
			nex.x+=dx[i];
			nex.y+=dy[i];
			if(nex.x<1||nex.x>n||nex.y<1||nex.y>n) continue;
			if(dis[nex.x][nex.y]>dis[t.x][t.y]+1)
			{
				dis[nex.x][nex.y]=dis[t.x][t.y]+1;
				q.push(nex);
			}
		}
	}
}
int main()
{
	int m,i,j;
	scanf("%d%d",&n,&m);
	dx.clear();
	dy.clear();
	for(i=-n;i<=n;i++)
	{
		for(j=-n;j<=n;j++)
		{
			if(sqr(i)+sqr(j)==m)
			{
				dx.push_back(i);
				dy.push_back(j);
			}
		}
	}
	bfs(1,1);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(dis[i][j]==INF) dis[i][j]=-1;
			printf("%d%c",dis[i][j]," \n"[j==n]);
		}
	}
	return 0;
}
