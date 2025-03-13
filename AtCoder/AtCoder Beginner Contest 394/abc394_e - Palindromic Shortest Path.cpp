#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char mp[105][105];
int dis[105][105];
struct node{int l,r;};
void bfs(int n)
{
	int i,j;
	memset(dis,0x3f,sizeof dis);
	queue<node> q;
	for(i=1;i<=n;i++)
	{
		q.push({i,i});
		dis[i][i]=0;
		for(j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(mp[i][j]=='-') continue;
			q.push({i,j});
			dis[i][j]=1;
		}
	}
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(mp[i][t.l]=='-' || mp[t.r][j]=='-') continue;
				if(mp[i][t.l]!=mp[t.r][j]) continue;
				if(dis[i][j]>dis[t.l][t.r]+2)
				{
					dis[i][j]=dis[t.l][t.r]+2;
					q.push({i,j});
				}
			}
		}
	}
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	bfs(n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(dis[i][j]==INF) dis[i][j]=-1;
			printf("%d%c",dis[i][j]," \n"[j==n]);
		}
	}
	return 0;
}
