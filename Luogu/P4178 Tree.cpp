#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=4e4+10;
ll ans;
int k;
struct Fenwick_Tree
{
	#define type int
	type bit[MAX],tmp[MAX];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) bit[i]=0;
	}
	void init(int _n,type *a)
	{
		n=_n;
		tmp[0]=0;
		for(int i=1;i<=n;i++)
		{
			tmp[i]=a[i];
			tmp[i]+=tmp[i-1];
			bit[i]=tmp[i]-tmp[i-lowbit(i)];
		}
	}
	int lowbit(int x){return x&(-x);}
	type get(int x)
	{
		type res=0;
		while(x)
		{
			res+=bit[x];
			x-=lowbit(x);
		}
		return res;
	}
	void upd(int x,type v)
	{
		while(x<=n)
		{
			bit[x]+=v;
			x+=lowbit(x);
		}
	}
	type ask(int l,int r)
	{
		if(l>r) return 0;
		if(l-1<=0) return get(r);
		return get(r)-get(l-1);
	}
	#undef type
}tr;
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
		if(h>k) return;
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
		int i,j,len,dep;
		totdel=0;
		tr.upd(1,1);
		del[++totdel]=1;
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(vis[to]) continue;
			totd=0;
			get_dis(to,x,it.w);
			for(i=1;i<=totd;i++) ans+=tr.ask(1,k-d[i]+1);
			for(i=1;i<=totd;i++)
			{
				del[++totdel]=d[i]+1;
				tr.upd(d[i]+1,1);
			}
		}
		for(i=1;i<=totdel;i++) tr.upd(del[i],-tr.ask(del[i],del[i]));
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
		tr.init(k+1);
		divide(rt);
	}
	#undef type
}tdv;
int main()
{
	int n,i,a,b,c;
	scanf("%d",&n);
	tdv.init(n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		tdv.add_edge(a,b,c);
		tdv.add_edge(b,a,c);
	}
	scanf("%d",&k);
	ans=0;
	tdv.work();
	printf("%lld\n",ans);
	return 0;
}

