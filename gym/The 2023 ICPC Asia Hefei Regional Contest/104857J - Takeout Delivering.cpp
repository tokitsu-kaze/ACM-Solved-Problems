#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=3e5+10;
struct Disjoint_Set_Union
{
	int pre[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++) pre[i]=i;
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int a,int b)
	{
		int ra,rb;
		ra=find(a);
		rb=find(b);
		if(ra!=rb)
		{
			pre[ra]=rb;
			return 1;
		}
		return 0;
	}
}dsu;
struct node{int x,w;};
vector<node> mp[MAX];
int v1[MAX],v2[MAX];
void dfs(int x,int fa,int *v)
{
	for(auto &it:mp[x])
	{
		if(it.x==fa) continue;
		v[it.x]=max(v[x],it.w);
		dfs(it.x,x,v);
	}
}
struct Kruskal
{
	#define type int
	#define inf INF
	struct edge{int x,y;type w;};
	vector<edge> e;
	void init(){e.clear();}
	void add_edge(int a,int b,type w){e.push_back({a,b,w});}
	void work(int n)
	{
		sort(e.begin(),e.end(),[&](edge x,edge y){
			return x.w<y.w;
		});
		dsu.init(n);
		for(int i=0;i<=n;i++)
		{
			mp[i].clear();
			v1[i]=v2[i]=0;
		}
		for(auto &it:e)
		{
			if(dsu.merge(it.x,it.y))
			{
				mp[it.x].push_back({it.y,it.w});
				mp[it.y].push_back({it.x,it.w});
			}
		}
		dfs(1,0,v1);
		dfs(n,0,v2);
//		for(int i=1;i<=n;i++) printf("%d %d %d\n",i,v1[i],v2[i]);
		int ans=2e9;
		for(auto &it:e)
		{
			if(it.x>it.y) swap(it.x,it.y);
			if(it.x==1&&it.y==n) ans=min(ans,it.w);
			if(v1[it.x]<=it.w&&v2[it.y]<=it.w) ans=min(ans,max(v1[it.x],v2[it.y])+it.w);
			if(v2[it.x]<=it.w&&v1[it.y]<=it.w) ans=min(ans,max(v2[it.x],v1[it.y])+it.w);
	//		printf("%d\n",ans);
		}
		printf("%d\n",ans);
	}
	#undef type
	#undef inf
}krsk;
int main()
{
	int n,m,i,a,b,c;
	scanf("%d%d",&n,&m);
	krsk.init();
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		krsk.add_edge(a,b,c);
	}
	krsk.work(n);
	return 0;
}
