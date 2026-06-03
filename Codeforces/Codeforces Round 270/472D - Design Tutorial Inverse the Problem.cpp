#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
const int LIMT=1e9;
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
struct node{int to,w;};
struct Kruskal
{
	#define type int
	#define inf INF
	struct edge{int x,y;type w;};
	vector<edge> e;
	void init(){e.clear();}
	void add_edge(int a,int b,type w){e.push_back({a,b,w});}
	int work(int n,vector<node> *mp)
	{
		int i,cnt;
		type res=0;
		dsu.init(n);
		sort(e.begin(),e.end(),[&](edge x,edge y){
			return x.w<y.w;
		});
		for(auto &it:e)
		{
			if(dsu.merge(it.x,it.y))
			{
				if(it.w==0) return 0;
				res+=it.w;
				mp[it.x].push_back({it.y,it.w});
				mp[it.y].push_back({it.x,it.w});
			}
		}
		cnt=0;
		for(i=1;i<=n;i++) cnt+=dsu.find(i)==i;
		if(cnt!=1) return 0; // no connect
		return 1;
	}
	#undef type
	#undef inf
}krsk;
vector<node> mp[MAX];
int a[MAX][MAX],ok;
void dfs(int x,int fa,int be,int h)
{
	if(h!=a[be][x]) ok=0;
	for(auto &it:mp[x])
	{
		int to=it.to;
		int w=it.w;
		if(to==fa) continue;
		dfs(to,x,be,h+w);
	}
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	krsk.init();
	for(i=1;i<=n;i++)
	{
		a[i][i]=0;
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			krsk.add_edge(i,j,a[i][j]);
		}
	}
	ok=krsk.work(n,mp);
	for(i=1;i<=n;i++) dfs(i,0,i,0);
	if(ok) puts("YES");
	else puts("NO");
	return 0;
}
