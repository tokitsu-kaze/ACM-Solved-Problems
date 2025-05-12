#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
struct node{int x,y;};
char s[MAX];
vector<string> mp;
int n,m,dir[4][2]={0,1,1,0,0,-1,-1,0};
int cal(int x,int y)
{
	int i,nx,ny,cnt;
	cnt=0;
	for(i=0;i<4;i++)
	{
		nx=x+dir[i][0];
		ny=y+dir[i][1];
		if(nx<0||nx>=n||ny<0||ny>=m) continue;
		if(mp[nx][ny]=='.') cnt++;
	}
	return cnt;
}
void bfs()
{
	int i,j,x,y;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mp[i][j]=='L')
			{
				x=i;
				y=j;
			}
		}
	}
	queue<node> q;
	vector<vector<int>> vis(n,vector<int>(m,0));
	q.push({x,y});
	vis[x][y]=1;
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			node nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			if(nex.x<0||nex.x>=n||nex.y<0||nex.y>=m) continue;
			if(mp[nex.x][nex.y]!='.') continue;
			if(vis[nex.x][nex.y]) continue;
			if(cal(nex.x,nex.y)<2)
			{
				vis[nex.x][nex.y]=1;
				mp[nex.x][nex.y]='+';
				q.push(nex);
			}
		}
	}
}
int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		mp.clear();
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			mp.push_back(string(s));
		}
		bfs();
		for(auto &it:mp) puts(it.c_str());
	}
	return 0;
}
