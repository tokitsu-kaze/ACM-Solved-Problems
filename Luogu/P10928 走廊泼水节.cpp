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
int main()
{
	int T,n,i,a,b,c;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		vector<edge> e;
		for(i=1;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			e.push_back({a,b,c});
		}
		sort(e.begin(),e.end(),[](edge x,edge y){
			return x.w<y.w;
		});
		dsu.init(n);
		ans=0;
		for(auto &it:e)
		{
			a=dsu.find(it.x);
			b=dsu.find(it.y);
			ans+=(1LL*dsu.sz[a]*dsu.sz[b]-1)*(it.w+1);
			dsu.merge(a,b);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
