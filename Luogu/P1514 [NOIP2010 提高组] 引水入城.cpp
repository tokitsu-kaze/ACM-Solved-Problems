#include <bits/stdc++.h>
using namespace std;
struct node{int l,r;};
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int n,m,mp[505][505],vis[505][505];
int l[505][505],r[505][505];
void dfs(int x,int y)
{
	if(vis[x][y]) return;
	vis[x][y]=1;
	int i,nx,ny;
	for(i=0;i<4;i++)
	{
		nx=x+dir[i][0];
		ny=y+dir[i][1];
		if(nx<1||nx>n||ny<1||ny>m) continue;
		if(mp[x][y]<=mp[nx][ny]) continue;
		dfs(nx,ny);
		l[x][y]=min(l[x][y],l[nx][ny]);
		r[x][y]=max(r[x][y],r[nx][ny]);
	}
}
int main()
{
	int i,j,cnt,now,ans,rmx;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&mp[i][j]);
		}
	}
	memset(vis,0,sizeof vis);
	memset(l,0x3f,sizeof l);
	memset(r,-1,sizeof r);
	for(j=1;j<=m;j++) l[n][j]=r[n][j]=j;
	for(j=1;j<=m;j++)
	{
		dfs(1,j);
	}
	cnt=0;
	for(j=1;j<=m;j++) cnt+=(vis[n][j]==0);
	if(cnt)
	{
		puts("0");
		printf("%d\n",cnt);
		return 0;
	}
	vector<node> res;
	for(j=1;j<=m;j++)
	{
		if(l[1][j]<=r[1][j]) res.push_back({l[1][j],r[1][j]});
	}
	sort(res.begin(),res.end(),[&](node a,node b){
		return a.l<b.l;
	});
	now=0;
	ans=0;
	i=0;
	while(now<m)
	{
		rmx=0;
		while(i<res.size()&&res[i].l<=now+1)
		{
			rmx=max(rmx,res[i].r);
			i++;
		}
		ans++;
		now=rmx;
	}
	puts("1");
	printf("%d\n",ans);
	return 0;
}
