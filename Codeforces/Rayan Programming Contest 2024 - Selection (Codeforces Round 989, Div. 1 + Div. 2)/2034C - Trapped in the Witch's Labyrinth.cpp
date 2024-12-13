#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
char mp[1010][1010];
int vis[1010][1010],out[1010][1010];
int n,m,dir[4][2]={0,1,1,0,0,-1,-1,0};
void dfs(int x,int y)
{
	if(x<1||x>n||y<1||y>m)
	{
		out[x][y]=1;
		return;
	}
	if(vis[x][y]) return;
	vis[x][y]=1;
	int nx,ny;
	nx=x;
	ny=y;
	if(mp[x][y]=='U') nx=x-1;
	else if(mp[x][y]=='D') nx=x+1;
	else if(mp[x][y]=='L') ny=y-1;
	else if(mp[x][y]=='R') ny=y+1;
	if(mp[x][y]!='?')
	{
		dfs(nx,ny);
		if(out[nx][ny]) out[x][y]=1;
	}
}
int main()
{
	int T,i,j,k,x,y,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
		if(n==1 && m==1)
		{
			puts("0");
			continue;
		}
		for(i=0;i<=n+1;i++)
		{
			for(j=0;j<=m+1;j++)
			{
				vis[i][j]=out[i][j]=0;
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				dfs(i,j);
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(mp[i][j]!='?') continue;
				out[i][j]=1;
				for(k=0;k<4;k++)
				{
					x=i+dir[k][0];
					y=j+dir[k][1];
					if(x<1||x>n||y<1||y>m) continue;
					if(!out[x][y]) out[i][j]=0;
				}
			}
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				ans+=!out[i][j];
//				cout<<i<<" "<<j<<" "<<out[i][j]<<endl;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
