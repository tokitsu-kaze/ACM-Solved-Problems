#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
struct node{int lx,ly,rx,ry,f,res;};
int p,q;
bool vis[105][105][2];
int ck(int x,int y)
{
	if(x==0||y==0) return 1;
	return x+q>=y;
}
int bfs(int x,int y,int f)
{
	int i,j;
	node t,nex;
	memset(vis,0,sizeof vis);
	queue<node> q;
	q.push({x,y,0,0,0,0});
	vis[x][y][0]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t.lx==0) return t.res;
		if(!t.f)
		{
			for(i=0;i<=min(p,t.lx);i++)
			{
				for(j=0;j<=t.ly && i+j<=p;j++)
				{
					if(i+j==0) continue;
					nex=t;
					nex.lx-=i;
					nex.ly-=j;
					nex.rx+=i;
					nex.ry+=j;
					nex.f^=1;
					nex.res++;
					if(!ck(nex.lx,nex.ly)) continue;
					if(vis[nex.lx][nex.ly][nex.f]) continue;
					q.push(nex);
					vis[nex.lx][nex.ly][nex.f]=1;
				}
			}
		}
		else
		{
			for(i=0;i<=min(p,t.rx);i++)
			{
				for(j=0;j<=t.ry && i+j<=p;j++)
				{
					nex=t;
					nex.lx+=i;
					nex.ly+=j;
					nex.rx-=i;
					nex.ry-=j;
					nex.f^=1;
					nex.res++;
					if(!ck(nex.rx,nex.ry)) continue;
					if(vis[nex.lx][nex.ly][nex.f]) continue;
					q.push(nex);
					vis[nex.lx][nex.ly][nex.f]=1;
				}
			}
		}
	}
	return -1;
}
int main()
{
	int x,y;
	scanf("%d%d%d%d",&x,&y,&p,&q);
	printf("%d\n",bfs(x,y,0));
	return 0;
}

