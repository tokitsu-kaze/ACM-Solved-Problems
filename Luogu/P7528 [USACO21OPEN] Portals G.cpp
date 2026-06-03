#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
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
struct node{int w,a,b,c,d;}e[MAX];
int main()
{
	int n,i,ans;
	scanf("%d",&n);
	dsu.init(2*n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d%d",&e[i].w,&e[i].a,&e[i].b,&e[i].c,&e[i].d);
		dsu.merge(e[i].a,e[i].b);
		dsu.merge(e[i].c,e[i].d);
	}
	sort(e+1,e+1+n,[](node x,node y){
		return x.w<y.w;
	});
	ans=0;
	for(i=1;i<=n;i++)
	{
		if(dsu.merge(e[i].a,e[i].c)) ans+=e[i].w;
	}
	printf("%d\n",ans);
	return 0;
}
/*
2n个点2n条边，每个点恰好出现2次，说明最终连成的图是若干个简单环。
发现操作就是可以把两个简单环连起来。类似求mst，从小到大贪心即可。
*/
