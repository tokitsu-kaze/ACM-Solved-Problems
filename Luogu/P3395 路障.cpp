#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=1e3+10;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
struct node{int x,y;};
int x[2*MAX],y[2*MAX],n,tot;
int mp[MAX][MAX],vis[MAX][MAX];
int bfs(int sx,int sy)
{
	int i,sz,cnt;
	memset(vis,0,sizeof vis);
	queue<node> q;
	q.push({sx,sy});
	vis[sx][sy]=1;
	cnt=0;
	while(!q.empty())
	{
		sz=q.size();
		while(sz--)
		{
			node t=q.front();
			q.pop();
			if(t.x==n&&t.y==n) return 1;
			for(i=0;i<4;i++)
			{
				node nex=t;
				nex.x+=dir[i][0];
				nex.y+=dir[i][1];
				if(nex.x<1||nex.y<1||nex.x>n||nex.y>n) continue;
				if(mp[nex.x][nex.y]||vis[nex.x][nex.y]) continue;
				q.push(nex);
				vis[nex.x][nex.y]=1;
			}
		}
		cnt++;
		if(cnt<=tot) mp[x[cnt]][y[cnt]]=1;
	}
	return 0;
}
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		tot=2*n-2;
		for(i=1;i<=tot;i++) scanf("%d%d",&x[i],&y[i]);
		memset(mp,0,sizeof mp);
		if(bfs(1,1)) puts("Yes");
		else puts("No");
	}
	return 0;
}
