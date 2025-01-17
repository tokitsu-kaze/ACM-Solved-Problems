#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
const int mod=1e9+7;
char mp[1010][1010];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
struct node{int x,y,d,v;};
bool vis[1010][1010][4];
int main()
{
	int n,m,i,j,sx,sy,ex,ey,x,y,d;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%s",mp[i]+1);
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]=='S')
			{
				sx=i;
				sy=j;
			}
			else if(mp[i][j]=='G')
			{
				ex=i;
				ey=j;
			}
			memset(vis[i][j],0,sizeof vis[i][j]);
		}
	}
	queue<node> q;
	for(i=0;i<4;i++)
	{
		x=sx+dir[i][0];
		y=sy+dir[i][1];
		if(x<1||y<1||x>n||y>m) continue;
		if(mp[x][y]=='#') continue;
		q.push({x,y,i,1});
		vis[x][y][i]=1;
	}
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		if(t.x==ex && t.y==ey)
		{
			printf("%d\n",t.v);
			return 0;
		}
		d=(t.d-1+4)%4;
		x=t.x+dir[d][0];
		y=t.y+dir[d][1];
		if(x<1||y<1||x>n||y>m) goto NEX;
		if(mp[x][y]=='#'||vis[x][y][d]) goto NEX;
		q.push({x,y,d,t.v+1});
		vis[x][y][d]=1;
NEX:;
		d=(t.d+1)%4;
		x=t.x+dir[d][0];
		y=t.y+dir[d][1];
		if(x<1||y<1||x>n||y>m) goto END;
		if(mp[x][y]=='#'||vis[x][y][d]) goto END;
		q.push({x,y,d,t.v+1});
		vis[x][y][d]=1;
END:;
	}
	puts("-1");
	return 0;
}
