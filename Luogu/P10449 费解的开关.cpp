#include<bits/stdc++.h>
using namespace std;
const int N=5;
struct node
{
	int a[N][N];
};
int cal(node x)
{
	int i,j,res;
	res=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(x.a[i][j]==0) continue;
			res|=(1<<(i*N+j));
		}
	}
	return res;
}
void gao(node &x,int i,int j)
{
	x.a[i][j]^=1;
	if(i-1>=0) x.a[i-1][j]^=1;
	if(i+1<N) x.a[i+1][j]^=1;
	if(j-1>=0) x.a[i][j-1]^=1;
	if(j+1<N) x.a[i][j+1]^=1;
}
char dis[(1<<26)+5];
void bfs(node x)
{
	int i,j;
	queue<node> q;
	q.push(x);
	dis[cal(x)]=0;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		int xid=cal(x);
		if(dis[xid]>=6) break;
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				node nex=x;
				gao(nex,i,j);
				int id=cal(nex);
				if(dis[id]!=-1) continue;
				dis[id]=dis[xid]+1;
				q.push(nex);
			}
		}
	}
}
int main()
{
	int T,i,j;
	node tmp;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			tmp.a[i][j]=1;
		}
	}
	memset(dis,-1,sizeof dis);
	bfs(tmp);
	scanf("%d",&T);
	while(T--)
	{
		node x;
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				scanf("%1d",&x.a[i][j]);
			}
		}
		printf("%d\n",dis[cal(x)]);
	}
	return 0;
}
