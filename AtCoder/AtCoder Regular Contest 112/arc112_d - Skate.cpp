#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
struct Disjoint_Set_Union
{
	int pre[MAX],sz[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
			sz[i]=1;
		}
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int x,int y,bool dir=false)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(!dir && sz[x]>sz[y]) swap(x,y);
		pre[x]=y; // x -> y
		sz[y]+=sz[x];
		return 1;
	}
}dsu;
char mp[1010][1010];
int vis[2020];
int main()
{
	int n,m,i,j,cntn,cntm;
	scanf("%d%d",&n,&m);
	dsu.init(n+m);
	for(i=1;i<=n;i++)
	{
		scanf("%s",mp[i]+1);
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]=='#') dsu.merge(i,n+j);
		}
	}
	dsu.merge(1,n+1);
	dsu.merge(1,n+m);
	dsu.merge(n,n+1);
	dsu.merge(n,n+m);
	memset(vis,0,sizeof vis);
	cntn=0;
	for(i=1;i<=n;i++)
	{
		if(!vis[dsu.find(i)])
		{
			vis[dsu.find(i)]=1;
			cntn++;
		}
	}
	memset(vis,0,sizeof vis);
	cntm=0;
	for(i=n+1;i<=n+m;i++)
	{
		if(!vis[dsu.find(i)])
		{
			vis[dsu.find(i)]=1;
			cntm++;
		}
	}
	printf("%d\n",min(cntn,cntm)-1);
	return 0;
}
