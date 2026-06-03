#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int a[12],b[12],k,n,m,ok;
int vis[12][12];
int mark(int x,int y,int lenx,int leny,int f)
{
	int i,j;
	if(f==1)
	{
		for(i=0;i<lenx;i++)
		{
			for(j=0;j<leny;j++)
			{
				if(x+i>n || y+j>m) return 0;
				if(vis[x+i][y+j]) return 0;
			}
		}
	}
	for(i=0;i<lenx;i++)
	{
		for(j=0;j<leny;j++)
		{
			vis[x+i][y+j]+=f;
		}
	}
	return 1;
}
void dfs(int id,int need,int ret)
{
	int i,j;
	if(ok) return;
	if(need>ret) return;
	if(id==k)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(!vis[i][j]) return;
			}
		}
		ok=1;
		return;
	}
	ret-=a[id]*b[id];
	dfs(id+1,need,ret);
	for(i=1;i<=n-a[id]+1;i++)
	{
		for(j=1;j<=m-b[id]+1;j++)
		{
			if(vis[i][j]) continue;
			if(mark(i,j,a[id],b[id],1))
			{
				dfs(id+1,need-a[id]*b[id],ret);
				mark(i,j,a[id],b[id],-1);
			}
		}
	}
	for(i=1;i<=n-b[id]+1;i++)
	{
		for(j=1;j<=m-a[id]+1;j++)
		{
			if(vis[i][j]) continue;
			if(mark(i,j,b[id],a[id],1))
			{
				dfs(id+1,need-a[id]*b[id],ret);
				mark(i,j,b[id],a[id],-1);
			}
		}
	}
}
int main()
{
	int i,j,sum;
	scanf("%d%d%d",&k,&n,&m);
	sum=0;
	for(i=0;i<k;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		sum+=a[i]*b[i];
	}
	for(i=0;i<k;i++)
	{
		for(j=0;j<k-1;j++)
		{
			if(a[j]*b[j]<a[j+1]*b[j+1])
			{
				swap(a[j],a[j+1]);
				swap(b[j],b[j+1]);
			}
		}
	}
	memset(vis,0,sizeof vis);
	ok=0;
	dfs(0,n*m,sum);
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
/*
7 10 10
3 3
4 4
2 3
2 5
5 5
5 5
5 5
*/
