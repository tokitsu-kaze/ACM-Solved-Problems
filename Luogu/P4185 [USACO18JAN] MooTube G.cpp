#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
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
struct edge{int a,b,w;}e[MAX];
struct query{int k,x,id;}qst[MAX];
int ans[MAX];
int main()
{
	int n,q,i,j;
	scanf("%d%d",&n,&q);
	for(i=1;i<n;i++) scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].w);
	sort(e+1,e+n,[](edge x,edge y){
		return x.w>y.w;
	});
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&qst[i].k,&qst[i].x);
		qst[i].id=i;
	}
	sort(qst+1,qst+1+q,[](query x,query y){
		return x.k>y.k;
	});
	dsu.init(n);
	for(i=1,j=1;i<=q;i++)
	{
		while(j<n && e[j].w>=qst[i].k)
		{
			dsu.merge(e[j].a,e[j].b);
			j++;
		}
		ans[qst[i].id]=dsu.sz[dsu.find(qst[i].x)]-1;
	}
	for(i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}

