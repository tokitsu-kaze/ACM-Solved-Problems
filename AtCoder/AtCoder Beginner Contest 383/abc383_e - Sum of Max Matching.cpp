#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
const int mod=998244353;
int cnt[MAX],now;
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
		if(1LL*cnt[x]*cnt[y]<0) now=min(abs(cnt[x]),abs(cnt[y]));
		else now=0;
		pre[x]=y; // x -> y
		sz[y]+=sz[x];
		cnt[y]+=cnt[x];
		return 1;
	}
}dsu;
struct Kruskal
{
	#define type ll
	struct edge{int x,y;type w;};
	vector<edge> e;
	void init(){e.clear();}
	void add_edge(int a,int b,type w){e.push_back({a,b,w});}
	void work(int n)
	{
		int i,cnt;
		type res=0;
		dsu.init(n);
		sort(e.begin(),e.end(),[&](edge x,edge y){
			return x.w<y.w;
		});
		for(auto &it:e)
		{
			if(dsu.merge(it.x,it.y)) res+=it.w*now;
		}
		printf("%lld\n",res);
	}
	#undef type
}krsk;
int main()
{
	int n,m,k,i,a,b,c,x;
	scanf("%d%d%d",&n,&m,&k);
	krsk.init();
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		krsk.add_edge(a,b,c);
	}
	for(i=1;i<=k;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	for(i=1;i<=k;i++)
	{
		scanf("%d",&x);
		cnt[x]--;
	}
	krsk.work(n);
	return 0;
}
