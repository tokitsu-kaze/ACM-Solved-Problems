#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
struct Dijkstra
{
	#define type int
	const type inf=INF;
	struct node
	{
		int id;
		type v;
		friend bool operator <(node a,node b){return a.v>b.v;}
	};
	static const int N=3605;
	vector<node> mp[N];
	type dis[N];
	int n,vis[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type v){mp[x].push_back({y,v});}
	void work(int s)
	{
		int i,to;
		type w;
		priority_queue<node> q;
		for(i=0;i<=n;i++)
		{
			dis[i]=inf;
			vis[i]=0;
		}
		dis[s]=0;
		q.push({s,type(0)});
		while(!q.empty())
		{
			node t=q.top();
			q.pop();
			if(vis[t.id]) continue;
			vis[t.id]=1;// this node has already been extended
			for(auto &it:mp[t.id])
			{
				to=it.id;
				w=it.v;
				if(dis[to]>dis[t.id]+w)
				{
					dis[to]=dis[t.id]+w;
					if(!vis[to]) q.push({to,dis[to]}); 
				}
			}
		}
	}
	#undef type
}dij;
struct node{int x,y;};
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int mp[33][33],n,m;
int dis[33][33];
int get_id(int x,int y,int d)
{
	return (x-1)*m+y+n*m*d;
}
int ck(int x,int y)
{
	if(x<1||y<1||x>n||y>m) return 1;
	if(!mp[x][y]) return 1;
	return 0;
}
void bfs(int x,int y)
{
	int i;
	node t,nex;
	queue<node> q;
	memset(dis,0x3f,sizeof dis);
	q.push({x,y});
	dis[x][y]=0;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			if(ck(nex.x,nex.y)) continue;
			if(dis[nex.x][nex.y]>dis[t.x][t.y]+1)
			{
				dis[nex.x][nex.y]=dis[t.x][t.y]+1;
				q.push(nex);
			}
		}
	}
}
int main()
{
	int i,j,k,l,q,x,y,nx,ny,ex,ey,sx,sy,tx,ty,ans;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&mp[i][j]);
		}
	}
	dij.init(n*m*4);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(!mp[i][j]) continue;
			mp[i][j]=0;
			for(k=0;k<4;k++)
			{
				x=i+dir[k][0];
				y=j+dir[k][1];
				if(ck(x,y)) continue;
				bfs(x,y);
				for(l=0;l<4;l++)
				{
					nx=i+dir[l][0];
					ny=j+dir[l][1];
					if(ck(nx,ny)) continue;
					if(dis[nx][ny]==INF) continue;
					dij.add_edge(get_id(i,j,k),
								 get_id(nx,ny,(l+2)%4),
								 dis[nx][ny]+1);
				}
			}
			mp[i][j]=1;
		}
	}
	while(q--)
	{
		scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
		if(sx==tx&&sy==ty)
		{
			puts("0");
			continue;
		}
		ans=INF;
		mp[sx][sy]=0;
		bfs(ex,ey);
		mp[sx][sy]=1;
		for(i=0;i<4;i++)
		{
			x=sx+dir[i][0];
			y=sy+dir[i][1];
			if(ck(x,y)) continue;
			dij.work(get_id(sx,sy,i));
			for(j=0;j<4;j++)
			{
				ans=min(ans,dis[x][y]+dij.dis[get_id(tx,ty,j)]);
			}
		}
		if(ans==INF) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
