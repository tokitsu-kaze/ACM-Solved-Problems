#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
struct node{int x,y,d;} pre[MAX][MAX][4];
int vis[MAX][MAX][4];
char mp[MAX][MAX];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int n,m;
const string tmp="RDLU";
int bfs(int sx,int sy,int tx,int ty)
{
	int i;
	node t,nex;
	queue<node> q;
	q.push({sx,sy,-1});
	memset(vis,0,sizeof vis);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
//		printf("%d %d %d\n",t.x,t.y,t.d);
		if(t.x==tx && t.y==ty)
		{
			puts("Yes");
			string res="";
			while(!(t.x==sx && t.y==sy))
			{
//				printf("%d %d %d\n",t.x,t.y,t.d);
				res+=tmp[t.d];
				t=pre[t.x][t.y][t.d];
			}
			reverse(res.begin(),res.end());
			cout<<res<<"\n";
			return 1;
		}
		for(i=0;i<4;i++)
		{
			if(mp[t.x][t.y]=='o')
			{
				if(i!=t.d) continue;
			}
			if(mp[t.x][t.y]=='x')
			{
				if(i==t.d) continue;
			}
			nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			nex.d=i;
			if(nex.x<1||nex.x>n||nex.y<1||nex.y>m) continue;
			if(vis[nex.x][nex.y][nex.d]) continue;
			if(mp[nex.x][nex.y]=='#') continue;
			q.push(nex);
			vis[nex.x][nex.y][nex.d]=1;
			pre[nex.x][nex.y][nex.d]=t;
		}
	}
	return 0;
}
int main()
{
	int i,j,sx,sy,tx,ty;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]=='S')
			{
				sx=i;
				sy=j;
			}
			if(mp[i][j]=='G')
			{
				tx=i;
				ty=j;
			}
		}
	}
	if(!bfs(sx,sy,tx,ty)) puts("No");
	return 0;
}
