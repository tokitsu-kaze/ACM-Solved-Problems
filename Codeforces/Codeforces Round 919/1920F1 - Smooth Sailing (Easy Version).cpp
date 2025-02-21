#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int dir2[8][2]={0,1,1,0,0,-1,-1,0,1,1,1,-1,-1,1,-1,-1};
string mp[MAX];
vector<int> dis[MAX],vis[MAX],tag[MAX];
char s[MAX];
int n,m;
void bfs0()
{
	int i,j,x,y;
	queue<pair<int,int>> q;
	for(i=0;i<n;i++) dis[i]=vector<int>(m,INF);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mp[i][j]=='v')
			{
				dis[i][j]=0;
				q.push({i,j});
			}
		}
	}
	while(!q.empty())
	{
		auto t=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			x=t.first+dir[i][0];
			y=t.second+dir[i][1];
			if(x<0 || x>=n || y<0 || y>=m) continue;
			if(dis[x][y]>dis[t.first][t.second]+1)
			{
				dis[x][y]=dis[t.first][t.second]+1;
				q.push({x,y});
			}
		}
	}
}
int bfs1()
{
	int i,j,x,y;
	queue<pair<int,int>> q;
	for(i=0;i<n;i++) tag[i]=vector<int>(m,0);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mp[i][j]=='#')
			{
				tag[i][j]=1;
				q.push({i,j});
			}
		}
	}
	while(!q.empty())
	{
		auto t=q.front();
		q.pop();
		for(i=0;i<8;i++)
		{
			x=t.first+dir2[i][0];
			y=t.second+dir2[i][1];
			if(x<0 || x>=n || y<0 || y>=m) return 0;
			if(tag[x][y]) continue;
			if(vis[x][y]) continue;
			q.push({x,y});
			tag[x][y]=1;
		}
	}
	return 1;
}
int ck(int k,int x,int y)
{
	if(dis[x][y]<k) return 0;
	if(mp[x][y]=='#') return 0;
	int i,j,d;
	queue<pair<int,int>> q;
	for(i=0;i<n;i++) vis[i]=vector<int>(m,0);
	q.push({x,y});
	vis[x][y]=1;
	while(!q.empty())
	{
		auto t=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			x=t.first+dir[i][0];
			y=t.second+dir[i][1];
			if(x<0 || x>=n || y<0 || y>=m) continue;
			if(vis[x][y] || mp[x][y]=='#') continue;
			if(dis[x][y]<k) continue;
			q.push({x,y});
			vis[x][y]=1;
		}
	}
	return bfs1();
}
int main()
{
	int q,i,x,y,l,r,mid;
	scanf("%d%d%d",&n,&m,&q);
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		mp[i]=string(s);
	}
	bfs0();
	while(q--)
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		l=0;
		r=n+m;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid+1,x,y)) l=mid+1;
			else r=mid;
		}
		printf("%d\n",l);
	}
	return 0;
}
