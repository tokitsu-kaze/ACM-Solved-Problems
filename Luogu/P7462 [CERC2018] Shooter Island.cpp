#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e6+10;
struct Disjoint_Set_Union
{
	int pre[MAX],sz[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
			sz[i]=1;
		}
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(sz[x]>sz[y]) swap(x,y);
		pre[x]=y;
		sz[y]+=sz[x];
		return 1;
	}
}dsu;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
const int n=50;
const int m=1e5;
bool vis[n+5][m+5];
int get_id(int x,int y)
{
	return (x-1)*m+y;
}
set<int> mp[55],now;
int main()
{
	int q,op,a,b,c,d,i,j,nx,ny;
	scanf("%d",&q);
	dsu.init(n*m);
	memset(vis,0,sizeof vis);
	now.clear();
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		for(j=1;j<=m;j++) mp[i].insert(j);
		mp[i].insert(INF);
		now.insert(i);
	}
	now.insert(INF);
	while(q--)
	{
		scanf("%d%d%d%d%d",&op,&a,&b,&c,&d);
		if(op==0)
		{
			auto x=now.lower_bound(min(a,c));
			for(;(*x)<=max(a,c);)
			{
				auto y=mp[*x].lower_bound(min(b,d));
				for(;(*y)<=max(b,d);y=mp[*x].erase(y))
				{
					for(i=0;i<4;i++)
					{
						nx=(*x)+dir[i][0];
						ny=(*y)+dir[i][1];
						if(nx<1||nx>n||ny<1||ny>m) continue;
						if(!vis[nx][ny]) continue;
						dsu.merge(get_id((*x),(*y)),get_id(nx,ny));
					}
					vis[*x][*y]=1;
				}
				if(mp[*x].size()==1) x=now.erase(x);
				else x++;
			}
		}
		else
		{
			if(a==c&&b==d&&!vis[a][b]) puts("0");
			else printf("%d\n",dsu.find(get_id(a,b))==dsu.find(get_id(c,d)));
		}
	}
	return 0;
}

