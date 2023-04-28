#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
struct node{int x,y;}pre[1010][1010];
char mp[1010][1010];
int n,m,dir[4][2]={0,1,1,0,0,-1,-1,0};
int dis[1010][1010];
void bfs()
{
	int i,j;
	node now,nex;
	memset(dis,0x3f,sizeof dis);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			pre[i][j]={-1,-1};
		}
	}
	queue<node> q;
	assert(mp[1][1]!='*');
	q.push({1,1});
	dis[1][1]=0;
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			nex=now;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			if(nex.x<1 || nex.x>n || nex.y<1 ||nex.y>m) continue;
			if(mp[nex.x][nex.y]=='*') continue;
			if(dis[now.x][now.y]+1<dis[nex.x][nex.y])
			{
				dis[nex.x][nex.y]=dis[now.x][now.y]+1;
				pre[nex.x][nex.y]=now;
				q.push(nex);
			}
		}
	}
	vector<node> res;
	now={n,m};
	while(now.x!=-1)
	{
		res.push_back(now);
		now=pre[now.x][now.y];
	}
	reverse(res.begin(),res.end());
	for(auto &it:res) printf("%d %d\n",it.x,it.y);
}
int main()
{
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	bfs();
	return 0;
}
