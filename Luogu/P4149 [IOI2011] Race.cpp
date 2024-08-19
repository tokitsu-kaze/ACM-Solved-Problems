#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
const int MAXQ=1e6+10;
int k,ans;
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
	pair<int,int> d[MAX];
	int totd;
	void get_dis(int x,int fa,type h,int dep)
	{
		if(h>k) return;
		d[++totd]={h,dep};
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(to==fa||vis[to]) continue;
			get_dis(to,x,h+it.w,dep+1);
		}
	}
	int del[MAX],totdel;
	int flag[MAXQ];
	void cal(int x)
	{
		int i,j,len,dep;
		flag[0]=0;
		totdel=0;
		for(auto &it:mp[x])
		{
			int to=it.to;
			if(vis[to]) continue;
			totd=0;
			get_dis(to,x,it.w,1);
			for(i=1;i<=totd;i++)
			{
				len=d[i].first;
				dep=d[i].second;
				if(k>=len) ans=min(ans,flag[k-len]+dep);
			}
			for(i=1;i<=totd;i++)
			{
				len=d[i].first;
				dep=d[i].second;
				del[++totdel]=len;
				flag[len]=min(flag[len],dep);
			}
		}
		for(i=1;i<=totdel;i++) flag[del[i]]=INF;
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
		for(i=0;i<MAXQ;i++) flag[i]=INF;
		rt=0;
		mx[rt]=sum=n;
		get_centroid(1,-1);
		divide(rt);
	}
	#undef type
}tdv;
int main()
{
	int n,i,a,b,c;
	scanf("%d%d",&n,&k);
	tdv.init(n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		a++;
		b++;
		tdv.add_edge(a,b,c);
		tdv.add_edge(b,a,c);
	}
	ans=INF;
	tdv.work();
	if(ans==INF) ans=-1;
	printf("%d\n",ans);
	return 0;
}

