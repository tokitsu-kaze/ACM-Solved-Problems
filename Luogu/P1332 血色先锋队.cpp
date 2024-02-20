#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
struct node{int x,y;};
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int n,m;
int dis[505][505];
void bfs(vector<node> tmp)
{
	int i;
	memset(dis,0x3f,sizeof dis);
	queue<node> q;
	for(auto &it:tmp)
	{
		q.push(it);
		dis[it.x][it.y]=0;
	}
	while(!q.empty())
	{
		auto t=q.front();
		q.pop();
		for(i=0;i<4;i++)
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
	int i,j,a,b,x,y;
	scanf("%d%d%d%d",&n,&m,&a,&b);
	vector<node> tmp;
	while(a--)
	{
		scanf("%d%d",&x,&y);
		tmp.push_back({x,y});
	}
	bfs(tmp);
	while(b--)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",dis[x][y]);
	}
	return 0;
}
