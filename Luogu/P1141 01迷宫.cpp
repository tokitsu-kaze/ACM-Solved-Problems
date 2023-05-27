#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+10;
struct node{int x,y;};
int dir[4][2]={0,1,1,0,0,-1,-1,0};
char mp[1005][1005];
int flag[1005][1005],n;
int ans[MAX];
bool check(int x,int y)
{
	if(x<1||x>n||y<1||y>n) return 0;
	return 1;
}
void bfs(int x,int y,int col)
{
	int i,res;
	node t,nex;
	queue<node> q;
	q.push({x,y});
	flag[x][y]=col;
	res=0;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		res++;
		for(int i=0;i<4;i++)
		{
			nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			if(!check(nex.x,nex.y)) continue;
			if(flag[nex.x][nex.y]) continue;
			if(mp[nex.x][nex.y]==mp[t.x][t.y]) continue;
			q.push(nex);
			flag[nex.x][nex.y]=col;
		}
	}
	ans[col]=res;
}
int main()
{
	int m,i,j,a,b,tot;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	memset(flag,0,sizeof flag);
	tot=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(flag[i][j]) continue;
			tot++;
			bfs(i,j,tot);
		}
	}
	while(m--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",ans[flag[a][b]]);
	}
	return 0;
}
