#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Disjoint_Set_Union
{
	int pre[MAX],sz[MAX],mn[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
			sz[i]=1;
			mn[i]=2e9;
		}
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int x,int y,int w,bool dir=false)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(!dir && sz[x]>sz[y]) swap(x,y);
		pre[x]=y; // x -> y
		sz[y]+=sz[x];
		mn[y]=min({mn[y],mn[x],w});
		return 1;
	}
}dsu;
struct edge{int x,y,w;}e[MAX];
int main()
{
	int T,n,m,i,j,ans,x,y,w;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d",&x,&y,&w);
			e[i]={x,y,w};
		}
		sort(e+1,e+1+m,[](edge a,edge b){
			return a.w<b.w;
		});
		dsu.init(n);
		ans=2e9;
		for(i=1;i<=m;i++)
		{
			dsu.merge(e[i].x,e[i].y,e[i].w);
			if(dsu.find(1)==dsu.find(n)) ans=min(ans,e[i].w+dsu.mn[dsu.find(1)]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
