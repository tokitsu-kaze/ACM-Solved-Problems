#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e4+15;
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
struct node{int a,b,w;}a[12][MAX];
int c[12],id[12],n,k,pos[12];
ll ans;
void dfs(int x,int tot,ll now)
{
	if(now>=ans) return;
	if(x==k+1)
	{
		int i,j,cnt,p;
		dsu.init(n+k);
		for(i=0;i<=k;i++) pos[i]=1;
		cnt=n-1;
		id[0]=0;
		while(1)
		{
			p=id[0];
			for(i=1;i<=tot;i++)
			{
				if(pos[id[i]]>n) continue;
				if(a[id[i]][pos[id[i]]].w<a[p][pos[p]].w) p=id[i];
			}
			if(a[p][pos[p]].w==INF) break;
			if(dsu.merge(a[p][pos[p]].a,a[p][pos[p]].b)) now+=a[p][pos[p]].w;
            if(now>=ans) return;
			pos[p]++;
		}
		ans=min(ans,now);
		return;
	}
	dfs(x+1,tot,now);
	id[tot+1]=x;
	dfs(x+1,tot+1,now+c[x]);
}
int main()
{
	int m,i,j,u,v,w;
	scanf("%d%d%d",&n,&m,&k);
	vector<node> e;
	while(m--)
	{
		scanf("%d%d%d",&u,&v,&w);
		e.push_back({u,v,w});
	}
	sort(e.begin(),e.end(),[](node x,node y){
		return x.w<y.w;
	});
	dsu.init(n);
	j=0;
	ans=0;
	for(auto &it:e)
	{
		if(dsu.merge(it.a,it.b))
		{
			ans+=it.w;
			a[0][++j]=it;
		}
	}
	assert(j==n-1);
	a[0][n]={-1,-1,INF};
	for(i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j].w);
			a[i][j].a=n+i;
			a[i][j].b=j;
		}
		sort(a[i]+1,a[i]+1+n,[](node x,node y){
			return x.w<y.w;
		});
		a[i][n+1]={-1,-1,INF};
	}
	dfs(1,0,0);
	printf("%lld\n",ans);
	return 0;
}
