#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int mp[11][11],flag[11][11],tx,ty,ans,n,m;
void dfs(int x,int y)
{
	if(x<1||y<1||x>n||y>m) return;
	if(mp[x][y]) return;
	if(flag[x][y]) return;
	if(x==tx&&y==ty)
	{
		ans++;
		return;
	}
	flag[x][y]=1;
	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x,y-1);
	flag[x][y]=0;
}
int main()
{
	int k,i,x,y,sx,sy;
	scanf("%d%d%d",&n,&m,&k);
	memset(mp,0,sizeof mp);
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	while(k--)
	{
		scanf("%d%d",&x,&y);
		mp[x][y]=1;
	}
	ans=0;
	memset(flag,0,sizeof flag);
	dfs(sx,sy);
	printf("%d\n",ans);
	return 0;
}
