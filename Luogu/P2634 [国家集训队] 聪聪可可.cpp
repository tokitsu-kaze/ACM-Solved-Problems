#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e4+10;
int fz;
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
	type d[MAX],del[MAX];
	int totd,totdel;
	void get_dis(int x,int fa,type h)
	{
		d[++totd]=h;
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(to==fa||vis[to]) continue;
			get_dis(to,x,h+it.w);
		}
	}
	void cal(int x)
	{
		int i,j,cnt[3];
		memset(cnt,0,sizeof cnt);
		cnt[0]=1;
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(vis[to]) continue;
			totd=0;
			get_dis(to,x,it.w);
			for(i=1;i<=totd;i++) fz+=cnt[(3-d[i]%3)%3];
			for(i=1;i<=totd;i++) cnt[d[i]%3]++;
		}
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
		divide(rt);
	}
	#undef type
}tdv;
int main()
{
	int n,i,a,b,c,fm,g;
	scanf("%d",&n);
	tdv.init(n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		tdv.add_edge(a,b,c);
		tdv.add_edge(b,a,c);
	}
	fz=0;
	tdv.work();
	fm=n*n;
	fz=2*fz+n;
	g=__gcd(fz,fm);
	fz/=g;
	fm/=g;
	printf("%d/%d\n",fz,fm);
	return 0;
}

