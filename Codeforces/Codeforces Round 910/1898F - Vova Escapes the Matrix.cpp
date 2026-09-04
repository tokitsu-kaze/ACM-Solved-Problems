#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
char mp[MAX][MAX];
int dis[MAX][MAX][2],n,m,dir[4][2]={0,1,1,0,0,-1,-1,0};
int vis[MAX][MAX];
pair<int,int> be[MAX][MAX][2];
struct node{int x,y,f;};
void bfs(vector<node> &s)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			dis[i][j][0]=dis[i][j][1]=INF;
			be[i][j][0]=be[i][j][1]={-1,-1};
			vis[i][j]=0;
		}
	}
	queue<node> q;
	for(auto &it:s)
	{
		dis[it.x][it.y][0]=0;
		be[it.x][it.y][0]={it.x,it.y};
		q.push({it.x,it.y,0});
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
			if(nex.x<1 || nex.x>n || nex.y<1 || nex.y>m)
			{
				vis[t.x][t.y]=1;
				continue;
			}
			if(mp[nex.x][nex.y]=='#') continue;
			if(dis[nex.x][nex.y][0]>dis[t.x][t.y][t.f]+1)
			{
				if(be[nex.x][nex.y][0]!=be[t.x][t.y][t.f])
				{
					dis[nex.x][nex.y][1]=dis[nex.x][nex.y][0];
					be[nex.x][nex.y][1]=be[nex.x][nex.y][0];
				}
				dis[nex.x][nex.y][0]=dis[t.x][t.y][t.f]+1;
				be[nex.x][nex.y][0]=be[t.x][t.y][t.f];
				q.push({nex.x,nex.y,0});
			}
			else
			{
				if(dis[nex.x][nex.y][1]>dis[t.x][t.y][t.f]+1
				&& be[nex.x][nex.y][0]!=be[t.x][t.y][t.f])
				{
					dis[nex.x][nex.y][1]=dis[t.x][t.y][t.f]+1;
					be[nex.x][nex.y][1]=be[t.x][t.y][t.f];
					q.push({nex.x,nex.y,1});
				}
			}
		}
	}
}
int ds[MAX][MAX];
int main()
{
	int T,i,j,out_cnt,cnt,x,y,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
		cnt=0;
		vector<node> s;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(mp[i][j]=='V')
				{
					x=i;
					y=j;
					s.push_back({i,j,0});
					bfs(s);
				}
				if(mp[i][j]=='.') cnt++;
			}
		}
		s.clear();
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(vis[i][j]) s.push_back({i,j,0});
				ds[i][j]=dis[i][j][0];
			}
		}
//		for(auto &it:s) printf("%d %d\n",it.x,it.y);
		bfs(s);
		out_cnt=s.size();
		if(out_cnt==0)
		{
			printf("%d\n",cnt);
			continue;
		}
		if(out_cnt==1)
		{
			printf("%d\n",cnt-dis[x][y][0]);
			continue;
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
//				printf("%d %d %d %d\n",i,j,dis[i][j][0],dis[i][j][1]);
				if(mp[i][j]=='#') continue;
				if(ds[i][j]==INF || dis[i][j][0]==INF || dis[i][j][1]==INF) continue;
				ans=max(ans,cnt-(ds[i][j]+dis[i][j][0]+dis[i][j][1]));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
先判断类型。一类就全堵上。二类就是最短路。
三类就是有2个出口，是一个三叉形状。
枚举x，起点走到x，再从x分别走到两个出口。
从出口倒着，维护不同起点的次短路即可。

维护的时候，会不会出现
a,b,c,d
a>c，b<<d
a+b<c+d
每个出口的最短路只有1个，不可能出现绕路的情况。
所以这么组合不如选最优的 b+c。
*/
