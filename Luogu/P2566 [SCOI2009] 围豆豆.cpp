#include <bits/stdc++.h>
using namespace std;
struct node{int x,y,s,v;} a[12];
char mp[12][12];
int v[12],n,m,d,dir[4][2]={0,1,1,0,0,-1,-1,0};
int dp[12][12][(1<<9)+5],val[(1<<9)+5];
int cal(node pre,node nex,int now)
{
	int i;
	int res=now;
	if(pre.x==nex.x) return res;
	for(i=0;i<d;i++)
	{
		if(nex.y<=a[i].y) continue;
		if((pre.x==a[i].x&&nex.x<a[i].x)||
		   (pre.x<a[i].x&&nex.x==a[i].x))
		{
			res^=(1<<i);
		}
	}
	return res;
}
int bfs(int sx,int sy)
{
	int i,res;
	node t,nex;
	memset(dp,-0x3f,sizeof dp);
	queue<node> q;
	q.push({sx,sy,0,0});
	dp[sx][sy][0]=0;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
//		printf("%d %d %d %d\n",t.x,t.y,t.s,t.v);
		for(i=0;i<4;i++)
		{
			nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			if(nex.x<0||nex.x>=n||nex.y<0||nex.y>=m) continue;
			if(mp[nex.x][nex.y]!='0') continue;
			nex.s=cal(t,nex,t.s);
			nex.v=t.v-val[t.s]+val[nex.s]-1;
			if(dp[nex.x][nex.y][nex.s]<nex.v)
			{
				dp[nex.x][nex.y][nex.s]=nex.v;
				q.push(nex);
			}
		}
	}
	res=0;
	for(i=0;i<(1<<d);i++)
	{
		res=max(res,dp[sx][sy][i]);
//		printf("%d %d %d %d\n",sx,sy,i,res);
	}
	return res;
}
int main()
{
	int i,j,ans;
	scanf("%d%d",&n,&m);
	scanf("%d",&d);
	for(i=0;i<d;i++) scanf("%d",&v[i]);
	for(i=0;i<n;i++) scanf("%s",mp[i]);
	ans=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mp[i][j]>='1'&&mp[i][j]<='9')
			{
				a[mp[i][j]-'1'].x=i;
				a[mp[i][j]-'1'].y=j;
			}
		}
	}
	memset(val,0,sizeof val);
	for(i=0;i<(1<<d);i++)
	{
		for(j=0;j<d;j++)
		{
			if((i>>j)&1) val[i]+=v[j];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mp[i][j]!='0') continue;
			ans=max(ans,bfs(i,j));
		}
	}
	printf("%d\n",ans);
	return 0;
}
