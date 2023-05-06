#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=300+10;
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
struct Kruskal
{
	#define type int
	#define inf INF
	struct edge
	{
		int x,y;
		type w;
	};
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
		if(cnt!=1) return inf;
		return res;
	}
	#undef type
	#undef inf
}krsk;
int main()
{
	int n,i,j,w;
	scanf("%d",&n);
	krsk.init();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&w);
		krsk.add_edge(i,n+1,w);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&w);
			if(i!=j) krsk.add_edge(i,j,w);
		}
	}
	printf("%d\n",krsk.work(n+1));
	return 0;
}
