#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
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
	bool merge(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(sz[x]>sz[y]) swap(x,y);
		pre[x]=y;
		sz[y]+=sz[x];
		return 1;
	}
}dsu;
struct Kruskal
{
	#define type int
	#define inf INF
	struct edge{int x,y;type w;};
	vector<edge> e;
	void init(){e.clear();}
	void add_edge(int a,int b,type w){e.push_back({a,b,w});}
	type work(int n)
	{
		int i,cnt;
		type res=0;
		dsu.init(n);
		sort(e.begin(),e.end(),[&](edge x,edge y){
			return x.w<y.w;
		});
		for(auto &it:e)
		{
			if(dsu.merge(it.x,it.y)) res+=it.w;
		}
		cnt=0;
		for(i=1;i<=n;i++) cnt+=dsu.find(i)==i;
		if(cnt!=1) return inf; // no connect
		return res;
	}
	#undef type
	#undef inf
}krsk;
int main()
{
	int k,n,i,j,x;
	scanf("%d%d",&k,&n);
	krsk.init();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&x);
			if(i<j&&x) krsk.add_edge(i,j,x);
		}
		krsk.add_edge(n+1,i,k);
	}
	printf("%d\n",krsk.work(n+1));
	return 0;
}

