#include <bits/stdc++.h>
using namespace std;
int m,n,bt[105][11];
struct node{int a[10],v;};
int cal(node x)
{
	int i,j,res;
	res=0;
	for(i=0;i<n;i++)
	{
		if(x.a[i]) res|=(1<<i);
	}
	return res;
}
int vis[1024];
int bfs()
{
	int i,j,xid,nexid;
	node x,nex;
	memset(vis,0,sizeof vis);
	for(i=0;i<n;i++) x.a[i]=1;
	x.v=0;
	queue<node> q;
	q.push(x);
	vis[cal(x)]=1;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		xid=cal(x);
		if(xid==0) return x.v;
		for(i=0;i<m;i++)
		{
			nex=x;
			for(j=0;j<n;j++)
			{
				if(bt[i][j]==1)
				{
					if(nex.a[j]==1) nex.a[j]=0;
				}
				else if(bt[i][j]==-1)
				{
					if(nex.a[j]==0) nex.a[j]=1;
				}
			}
			nexid=cal(nex);
			if(vis[nexid]) continue;
			nex.v++;
			q.push(nex);
			vis[nexid]=1;
		}
	}
	return -1;
}
int main()
{
	int i,j;
	node x;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&bt[i][j]);
		}
	}
	printf("%d\n",bfs());
	return 0;
}
