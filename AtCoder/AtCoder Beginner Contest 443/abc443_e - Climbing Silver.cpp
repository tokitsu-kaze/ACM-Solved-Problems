#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3000+10;
struct node{int x,y;};
int dir[3][2]={-1,-1,-1,0,-1,1};
char mp[MAX][MAX],ans[MAX];
int vis[MAX][MAX],n,visy[MAX],cnt[MAX][MAX];
int ck(node a)
{
	if(a.x<1 || a.x>n || a.y<1 ||a.y>n) return 0;
	return 1;
}
void modify(node t)
{
	int i;
	if(visy[t.y]) return;
	visy[t.y]=1;
	if(cnt[t.x+1][t.y]==0)
	{
		for(i=t.x+1;i;i--)
		{
			if(mp[i][t.y]=='#') mp[i][t.y]='.';
		}
	}
}
void bfs(int x,int y)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++) vis[i][j]=0;
	}
	for(j=1;j<=n;j++) visy[j]=0;
	queue<node> q;
	q.push({x,y});
	vis[x][y]=1;
	modify({x,y});
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		for(i=0;i<3;i++)
		{
			node nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			if(!ck(nex)) continue;
			modify(nex);
			if(mp[nex.x][nex.y]=='#') continue;
			if(!vis[nex.x][nex.y])
			{
				vis[nex.x][nex.y]=1;
				q.push(nex);
			}
		}
	}
}
int main()
{
	int T,x,y,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&y);
		for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
		for(i=0;i<=n;i++) cnt[n+1][i]=0;
		for(i=n;i;i--)
		{
			for(j=1;j<=n;j++)
			{
				if(mp[i][j]=='#') cnt[i][j]=1;
				else cnt[i][j]=0;
				cnt[i][j]+=cnt[i+1][j];
			}
		}
		x=n;
		bfs(x,y);
		for(j=1;j<=n;j++) ans[j]='0'+vis[1][j];
		ans[n+1]='\0';
		puts(ans+1);
	}
	return 0;
}
