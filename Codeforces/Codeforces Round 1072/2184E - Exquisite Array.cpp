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
int a[MAX],id[MAX];
ll ans[MAX];
ll cal(int x)
{
	ll sz=dsu.sz[dsu.find(x)];
	return sz*(sz-1)/2;
}
int main()
{
	int T,n,k,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			id[i]=i;
			ans[i]=0;
		}
		sort(id+1,id+n,[&](int x,int y){
			return abs(a[x]-a[x+1])<abs(a[y]-a[y+1]);
		});
		dsu.init(n);
		for(i=n-1;i;i--)
		{
			k=abs(a[id[i]]-a[id[i]+1]);
			ans[k]-=cal(id[i]);
			ans[k]-=cal(id[i]+1);
			dsu.merge(id[i],id[i]+1);
			ans[k]+=cal(id[i]);
		}
		for(i=n-1;i;i--) ans[i]+=ans[i+1];
		for(i=1;i<=n-1;i++) printf("%lld%c",ans[i]," \n"[i==n-1]);
	}
	return 0;
}
