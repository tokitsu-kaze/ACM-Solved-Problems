#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll dp[MAX],sum[MAX];
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
	bool merge(int x,int y,ll w)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(sz[x]>sz[y]) swap(x,y);
		ll dpx,dpy;
		dpx=dp[x];
		dpy=dp[y];
		dp[y]=min(sum[x]+max(w,dpy),sum[y]+max(w,dpx));
		pre[x]=y;
		sz[y]+=sz[x];
		sum[y]+=sum[x];
		return 1;
	}
}dsu;
struct node{int x,y,w;};
int a[MAX],b[MAX];
int main()
{
	int T,i,n,m,x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
			dp[i]=b[i];
			sum[i]=b[i];
		}
		vector<node> e;
		while(m--)
		{
			scanf("%d%d",&x,&y);
			e.push_back({x,y,max(a[x],a[y])});
		}
		sort(e.begin(),e.end(),[](node x,node y){
			return x.w<y.w;
		});
		dsu.init(n);
		for(auto &it:e) dsu.merge(it.x,it.y,it.w);
		printf("%lld\n",dp[dsu.find(1)]);
	}
	return 0;
}
