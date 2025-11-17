#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3000+10;
int cnt[MAX][MAX],dis[MAX][MAX];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
struct node{int x,y;};
int main()
{
	int n,m,k,i,j,x,y;
	ll ans;
	scanf("%d%d%d",&n,&m,&k);
	memset(cnt,0,sizeof cnt);
	memset(dis,0x3f,sizeof dis);
	queue<node> q;
	for(i=1;i<=k;i++)
	{
		scanf("%d%d",&x,&y);
		dis[x][y]=0;
		cnt[x][y]=4;
		q.push({x,y});
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
			if(nex.x<1||nex.x>n||nex.y<1||nex.y>m) continue;
			cnt[nex.x][nex.y]++;
			if(cnt[nex.x][nex.y]==2)
			{
				if(dis[nex.x][nex.y]>dis[t.x][t.y]+1)
				{
					dis[nex.x][nex.y]=dis[t.x][t.y]+1;
					q.push(nex);
				}
			}
		}
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(cnt[i][j]<2) continue;
			ans+=dis[i][j];
		}
	}
	printf("%lld\n",ans);
	return 0;
}
