#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int mp[33][33],flag[33][33],n;
void dfs(int x,int y)
{
	if(x<0||y<0||x>n+1||y>n+1) return;
	if(mp[x][y]||flag[x][y]) return;
	flag[x][y]=1;
	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x,y-1);
}
int main()
{
	int i,j;
	scanf("%d",&n);
	memset(mp,0,sizeof mp);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&mp[i][j]);
		}
	}
	memset(flag,0,sizeof flag);
	dfs(0,0);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(!mp[i][j]&&!flag[i][j]) mp[i][j]=2;
			printf("%d%c",mp[i][j]," \n"[j==n]);
		}
	}
	return 0;
}
