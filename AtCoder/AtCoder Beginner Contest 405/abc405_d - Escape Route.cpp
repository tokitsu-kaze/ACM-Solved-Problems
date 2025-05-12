#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
struct node{int x,y;};
int n,m,dir[4][2]={0,1,1,0,0,-1,-1,0};
string tmp="<^>v";
char mp[MAX][MAX];
void bfs()
{
	int i,j;
	queue<node> q;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]=='E') q.push({i,j});
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
			if(nex.x<1||nex.x>n||nex.y<1||nex.y>m) continue;
			if(mp[nex.x][nex.y]!='.') continue;
			mp[nex.x][nex.y]=tmp[i];
			q.push(nex);
		}
	}
}
int main()
{
	int i,j,sx,sy;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	bfs();
	for(i=1;i<=n;i++)
	{
		mp[i][m+1]='\0';
		puts(mp[i]+1);
	}
	return 0;
}
