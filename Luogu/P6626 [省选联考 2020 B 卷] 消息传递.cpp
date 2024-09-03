#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct Q{int k,id;};
vector<Q> qst[MAX];
int ans[MAX];
struct tree_divide
{
	#define type int
	struct edge{int to;type w;};
	vector<edge> mp[MAX];
	bool vis[MAX];
	int sz[MAX],mx[MAX],sum,rt,n;
	void init(int _n)
	{
		int i;
		n=_n;
		for(i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int x,int y,type w){mp[x].push_back({y,w});}
	void get_centroid(int x,int fa)
	{
		sz[x]=1;
		mx[x]=0;
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(to==fa||vis[to]) continue;
			get_centroid(to,x);
			sz[x]+=sz[to];
			mx[x]=max(mx[x],sz[to]);
		}
		mx[x]=max(mx[x],sum-sz[x]);
		if(mx[x]<mx[rt]) rt=x;
	}
	void get_sz(int x,int fa)
	{
		sz[x]=1;
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(to==fa||vis[to]) continue;
			get_sz(to,x);
			sz[x]+=sz[to];
		}
	}
	Q qlist[MAX];
	type del[MAX];
	int totdel,totq;
	int cnt[MAX];
	void get_dis(int x,int fa,type h)
	{
		cnt[h]++;
		del[++totdel]=h;
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(to==fa||vis[to]) continue;
			get_dis(to,x,h+it.w);
		}
	}
	void get_qst(int x,int fa,int h,int sgn)
	{
		for(auto &it:qst[x])
		{
			if(it.k<h) continue;
			if(sgn==1) qlist[++totq]={it.k-h,it.id};
			ans[it.id]+=sgn*cnt[it.k-h];
		}
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(to==fa||vis[to]) continue;
			get_qst(to,x,h+it.w,sgn);
		}
	}
	void cal(int x)
	{
		int i,j;
		totq=0;
		for(auto &it:qst[x]) qlist[++totq]=it;
		totdel=0;
		del[++totdel]=0;
		cnt[0]++;
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(vis[to]) continue;
			get_qst(to,x,it.w,1);
			get_dis(to,x,it.w);
			get_qst(to,x,it.w,-1);
		}
		for(i=1;i<=totq;i++) ans[qlist[i].id]+=cnt[qlist[i].k];
		for(i=1;i<=totdel;i++) cnt[del[i]]=0;
	}
	void divide(int x)
	{
		vis[x]=1;
		cal(x);
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(vis[to]) continue;
			get_sz(to,-1);
			rt=0;
			mx[rt]=sum=sz[to];
			get_centroid(to,-1);
			divide(rt);
		}
	}
	void work()
	{
		int i;
		for(i=0;i<=n;i++) vis[i]=0;
		rt=0;
		mx[rt]=sum=n;
		get_centroid(1,-1);
		for(i=1;i<=n;i++) cnt[i]=0;
		divide(rt);
	}
	#undef type
}tdv;
/*
tdv.init(n);
tdv.add_edge(x,y,w)   // x -> y
tdv.work();
*/
int main()
{
	int T,n,m,i,a,b,x,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) qst[i].clear();
		tdv.init(n);
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			tdv.add_edge(a,b,1);
			tdv.add_edge(b,a,1);
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&k);
			qst[x].push_back({k,i});
			ans[i]=0;
		}
		tdv.work();
		for(i=1;i<=m;i++) printf("%d\n",ans[i]);
	}
	return 0;
}
/*
1
4 7
1 2
2 3
3 4
1 0
1 1
1 2
1 3
2 1
3 1
3 2
*/
