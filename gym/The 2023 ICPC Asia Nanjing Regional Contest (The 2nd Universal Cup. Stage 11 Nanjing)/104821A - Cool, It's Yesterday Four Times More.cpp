#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1000+10;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
struct node{int x,y;};
int n,m;
bool vis[MAX][MAX];
char mp[MAX][MAX];
vector<node> res;
void bfs(int x,int y)
{
	res.clear();
	queue<node> q;
	q.push({x,y});
	vis[x][y]=1;
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		res.push_back(t);
		for(int i=0;i<4;i++)
		{
			node nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			if(nex.x<1||nex.x>n||nex.y<1||nex.y>m) continue;
			if(mp[nex.x][nex.y]=='O' || vis[nex.x][nex.y]) continue;
			q.push(nex);
			vis[nex.x][nex.y]=1;
		}
	}
}
bool ck()
{
	int i,j,ok,dx,dy;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]=='O') continue;
			if(i==res[0].x && j==res[0].y) continue;
			ok=0;
			for(auto &it:res)
			{
				dx=it.x-res[0].x;
				dy=it.y-res[0].y;
				if(i+dx<1 || i+dx>n || j+dy<1 || j+dy>m)
				{
					ok=1;
					break;
				}
				if(mp[i+dx][j+dy]!=mp[it.x][it.y]) ok=1;
			}
			if(!ok) return 0;
		}
	}
	return 1;
}
int main()
{
	int T,i,j,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%s",mp[i]+1);
			for(j=1;j<=m;j++) vis[i][j]=0;
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(mp[i][j]=='O') continue;
				if(vis[i][j]) continue;
				bfs(i,j);
				if(ck()) ans+=res.size();
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
