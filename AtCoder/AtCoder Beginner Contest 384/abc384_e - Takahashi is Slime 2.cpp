#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=4e5+10;
const int mod=998244353;
struct node
{
	int x,y;
	ll v;
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
};
int dir[4][2]={0,1,1,0,0,-1,-1,0};
bool vis[505][505];
ll mp[505][505];
int main()
{
	int n,m,bx,by,i,j,x,y;
	ll k,ans;
	scanf("%d%d%lld",&n,&m,&k);
	scanf("%d%d",&bx,&by);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&mp[i][j]);
			vis[i][j]=0;
		}
	}
	priority_queue<node> q;
	ans=mp[bx][by];
	vis[bx][by]=1;
	for(i=0;i<4;i++)
	{
		x=bx+dir[i][0];
		y=by+dir[i][1];
		if(x<1||x>n||y<1||y>m) continue;
		q.push({x,y,mp[x][y]});
		vis[x][y]=1;
	}
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
		if(t.v<(ans+k-1)/k) ans+=t.v;
		else break;
		for(i=0;i<4;i++)
		{
			x=t.x+dir[i][0];
			y=t.y+dir[i][1];
			if(x<1||x>n||y<1||y>m) continue;
			if(vis[x][y]) continue;
			q.push({x,y,mp[x][y]});
			vis[x][y]=1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
