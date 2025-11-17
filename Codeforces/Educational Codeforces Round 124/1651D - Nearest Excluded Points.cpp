#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int x,y,id;}res[MAX];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int x[MAX],y[MAX];
int ck(int x,int y)
{
	if(abs(x)>1e6) return 0;
	if(abs(y)>1e6) return 0;
	return 1;
}
int main()
{
	int n,i,j,nx,ny;
	scanf("%d",&n);
	map<pair<int,int>,int> mp,vis;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		mp[{x[i],y[i]}]=i;
	}
	queue<node> q;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<4;j++)
		{
			nx=x[i]+dir[j][0];
			ny=y[i]+dir[j][1];
			if(!ck(nx,ny)) continue;
			if(mp.count({nx,ny})) continue;
			res[i]={nx,ny,i};
			q.push({x[i],y[i],i});
			vis[{x[i],y[i]}]=1;
		}
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
			if(!ck(nex.x,nex.y)) continue;
			if(!mp.count({nex.x,nex.y})) continue;
			if(vis.count({nex.x,nex.y})) continue;
			res[mp[{nex.x,nex.y}]]=res[t.id];
			nex.id=mp[{nex.x,nex.y}];
			vis[{nex.x,nex.y}]=1;
			q.push(nex);
		}
	}
	for(i=1;i<=n;i++) printf("%d %d\n",res[i].x,res[i].y);
	return 0;
}

