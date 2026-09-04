#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=300+10;
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
		int i,cnt;
		type res;
		dsu.init(n);
		sort(e.begin(),e.end(),[&](edge x,edge y){
			return x.w<y.w;
		});
		res=cnt=0;
		for(auto &it:e)
		{
			if(dsu.merge(it.x,it.y))
			{
				cnt++;
				res=it.w;
			}
		}
		printf("%d %d\n",cnt,res);
	}
	#undef type
	#undef inf
}krsk;
int main()
{
	int n,m,a,b,c;
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
