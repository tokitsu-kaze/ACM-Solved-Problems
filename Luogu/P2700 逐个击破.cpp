#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
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
struct edge{int x,y,w;};
bool vis[MAX];
int main()
{
	int n,k,i,a,b,c;
	ll ans;
	scanf("%d%d",&n,&k);
	dsu.init(n);
	for(i=1;i<=n;i++) vis[i]=0;
	for(i=1;i<=k;i++)
	{
		scanf("%d",&a);
		a++;
		vis[a]=1;
	}
	vector<edge> e;
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		a++;
		b++;
		e.push_back({a,b,c});
	}
	sort(e.begin(),e.end(),[](edge x,edge y){
		return x.w>y.w;
	});
	ans=0;
	for(auto &it:e)
	{
		if(vis[dsu.find(it.x)] && vis[dsu.find(it.y)]) ans+=it.w;
		if(vis[dsu.find(it.x)] || vis[dsu.find(it.y)])
		{
			dsu.merge(it.x,it.y);
			vis[dsu.find(it.x)]=1;
		}
		else dsu.merge(it.x,it.y);
	}
	printf("%lld\n",ans);
	return 0;
}
