#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{int x,y;};
ll mp[2010][2010];
int n,m,dir[4][2]={0,1,1,0,0,-1,-1,0};
int vis[2010][2010];
int bfs(int x,int y)
{
	int i,sz,res;
	ll g=0;
	queue<node> q;
	q.push({x,y});
	g=mp[x][y];
	vis[x][y]=1;
	res=0;
	while(!q.empty())
	{
		if(g==1) return res;
		res++;
		sz=q.size();
		while(sz--)
		{
			node now=q.front();
			q.pop();
			for(i=0;i<4;i++)
			{
				node nex=now;
				nex.x+=dir[i][0];
				nex.y+=dir[i][1];
				if(nex.x<1 || nex.x>n || nex.y<1 || nex.y>m) continue;
				if(vis[nex.x][nex.y]) continue;
				vis[nex.x][nex.y]=1;
				q.push(nex);
				g=__gcd(g,mp[nex.x][nex.y]);
			}
		}
	}
	return -1;
}
int main()
{
	int i,j,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&mp[i][j]);
			vis[i][j]=0;
		}
	}
	scanf("%d%d",&x,&y);
	printf("%d\n",bfs(x,y));
	return 0;
}
