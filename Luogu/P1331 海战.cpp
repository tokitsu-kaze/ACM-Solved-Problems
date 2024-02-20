#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
char mp[1005][1005];
int flag[1005][1005],n,m;
void dfs(int x,int y)
{
	if(x<1||y<1||x>n||y>m) return;
	if(mp[x][y]=='.'||flag[x][y]) return;
	flag[x][y]=1;
	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x,y-1);
}
int ck(int x,int y)
{
	int i,j,cnt=0;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			if(x+i>n||y+j>m) return 0;
			cnt+=mp[x+i][y+j]=='#';
		}
	}
	return cnt==3;
}
int main()
{
	int i,j,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	memset(flag,0,sizeof flag);
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(ck(i,j))
			{
				ans=-1;
				break;
			}
			if(mp[i][j]=='.'||flag[i][j]) continue;
			ans++;
			dfs(i,j);
		}
		if(ans==-1) break;
	}
	if(ans==-1) puts("Bad placement.");
	else printf("There are %d ships.\n",ans);
	return 0;
}
