#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Disjoint_Set_Union
{
	int pre[MAX],sz[MAX],v[MAX];
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
	int get_size(int x)
	{
		x=find(x);
		return sz[x];
	}
}dsu,dsutot;
int cal(int x)
{
	int tot=dsutot.get_size(x);
	int now=dsu.get_size(x);
	return min(now,tot-now);
}
int to[MAX];
int main()
{
	int n,q,i,a,b,ans;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) to[i]=0;
	dsu.init(n);
	dsutot.init(n);
	ans=0;
	while(q--)
	{
		scanf("%d%d",&a,&b);
		if(dsu.find(a)==dsu.find(b) || ans==-1)
		{
			ans=-1;
			puts("-1");
			continue;
		}
		ans-=cal(a);
		if(dsutot.find(a)!=dsutot.find(b)) ans-=cal(b);
		dsutot.merge(a,b);
		
		if(to[a]) dsu.merge(to[a],b);
		else to[a]=b;
		if(to[b]) dsu.merge(to[b],a);
		else to[b]=a;
		
		ans+=cal(a);
		
		printf("%d\n",ans);
	}
	return 0;
}
