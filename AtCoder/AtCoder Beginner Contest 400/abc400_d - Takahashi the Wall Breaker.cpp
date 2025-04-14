#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
struct node
{
	int x,y,v;
	friend bool operator <(node a,node b)
	{
		return a.v>b.v;
	}
};
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int n,m,sx,sy,ex,ey;
char mp[MAX][MAX];
int dis[MAX][MAX];
int bfs()
{
	int i;
	priority_queue<node> q;
	memset(dis,0x3f,sizeof dis);
	dis[sx][sy]=0;
	q.push({sx,sy,0});
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
//		cout<<t.x<<" "<<t.y<<" "<<t.v<<endl;
		for(i=0;i<4;i++)
		{
			node nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			if(nex.x<1 || nex.x>n || nex.y<1 || nex.y>m) continue;
			if(mp[nex.x][nex.y]=='.')
			{
				if(dis[nex.x][nex.y]>t.v)
				{
					dis[nex.x][nex.y]=t.v;
					nex.v=dis[nex.x][nex.y];
					q.push(nex);
					
				}
			}
			else
			{
				if(dis[nex.x][nex.y]>t.v+1)
				{
					dis[nex.x][nex.y]=t.v+1;
					nex.v=dis[nex.x][nex.y];
					q.push(nex);
				}
				nex.x+=dir[i][0];
				nex.y+=dir[i][1];
				if(nex.x<1 || nex.x>n || nex.y<1 || nex.y>m) continue;
				if(dis[nex.x][nex.y]>t.v+1)
				{
					dis[nex.x][nex.y]=t.v+1;
					nex.v=dis[nex.x][nex.y];
					q.push(nex);
				}
			}
		}
	}
	return dis[ex][ey];
}
int main()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
	printf("%d\n",bfs());
	return 0;
}
/*
1 6
.####.
1 1 1 6
*/
