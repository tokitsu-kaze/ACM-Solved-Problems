#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Fenwick_Tree
{
	#define type ll
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
		for(;x;x-=lowbit(x)) res+=bit[x];
		return res;
	}
	void upd(int x,type v)
	{
		for(;x<=n;x+=lowbit(x)) bit[x]+=v;
	}
	type ask(int l,int r)
	{
		if(l>r) return 0;
		if(l-1<=0) return get(r);
		return get(r)-get(l-1);
	}
	void clear(int x)
	{
		for(;x<=n;x+=lowbit(x)) bit[x]=0;
	}
	#undef type
}tr;
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
struct Kruskal_Tree
{
	#define type int
	struct edge{int x,y;type w;};
	vector<edge> e;
	void init(){e.clear();}
	void add_edge(int x,int y,type w){e.push_back({x,y,w});}
	int build_kruskal_tree(int n,vector<int> *mp,type *w)
	{
		int rt,x,y,i;
		for(i=1;i<=2*n-1;i++)
		{
			mp[i].clear();
			w[i]=0;
		}
		dsu.init(2*n-1);
		sort(e.begin(),e.end(),[&](edge x,edge y){
			return x.w<y.w;
		});
		rt=n;
		for(auto &it:e)
		{
			x=dsu.find(it.x);
			y=dsu.find(it.y);
			if(x==y) continue;
			rt++;
			w[rt]=it.w;
			mp[rt].push_back(x);
			mp[rt].push_back(y);
			dsu.merge(x,rt,true);
			dsu.merge(y,rt,true);
		}
		return rt;
	}
	#undef type
}krsk;
/*
tr.build(n);
tr.upd(l,r,v);
tr.ask(l,r);
Segment_Tree::node res=tr.merge_node(nodex,nodey);
*/
struct Seg{int l,pos;};
vector<Seg> seg[MAX];
struct Q{int l,id;};
vector<Q> qst[MAX];
vector<int> mp[MAX];
set<int> s[MAX];
int w[MAX],n;
void dfs(int x)
{
	s[x].clear();
	for(auto &to:mp[x])
	{
		dfs(to);
		if(s[to].size()>s[x].size()) swap(s[x],s[to]);
		for(auto &it:s[to])
		{
			auto pre=s[x].lower_bound(it);
			if(pre!=s[x].begin())
			{
				pre--;
				seg[it].push_back({*pre,x});
			}
			auto nex=s[x].lower_bound(it);
			if(nex!=s[x].end()) seg[*nex].push_back({it,x});
		}
		for(auto &it:s[to]) s[x].insert(it);
	}
	if(1<=x && x<=n) s[x].insert(x);
}
int mx[MAX];
ll ans[MAX];
int main()
{
	int m,q,i,l,r,a,b,c,rt;
	ll sum;
	scanf("%d%d%d",&n,&m,&q);
	krsk.init();
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		a++;
		b++;
		krsk.add_edge(a,b,c);
	}
	rt=krsk.build_kruskal_tree(n,mp,w);
	for(i=1;i<=n;i++)
	{
		seg[i].clear();
		qst[i].clear();
	}
	dfs(rt);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&r);
		l++;
		r++;
		qst[r].push_back({l,i});
	}
	sum=0;
	for(i=n+1;i<=rt;i++)
	{
		mx[i]=0;
		sum+=w[i];
	}
	tr.init(n);
	for(i=1;i<=n;i++)
	{
		for(auto &it:seg[i])
		{
			if(mx[it.pos]<it.l)
			{
				if(mx[it.pos]) tr.upd(mx[it.pos],-w[it.pos]);
				mx[it.pos]=it.l;
				tr.upd(mx[it.pos],w[it.pos]);
			}
		}
		for(auto &qs:qst[i]) ans[qs.id]=tr.ask(qs.l,i);
	}
	for(i=1;i<=q;i++) printf("%lld\n",sum-ans[i]);
	return 0;
}
/*
突破口是li+1=ri，发现答案要减去Kruskal重构树上lca(li,ri)的点权。
推出答案要减去区间中任意两点lca的集合的点权和。
考虑每个节点作为lca时，有哪些[x,y]能提供贡献。
发现贡献需要两个不同子树的节点提供，但暴力是O(n^2)条[x,y]。
现在需要减少[x,y]的数量，考虑启发式合并的过程。
在合并过程中，枚举x，只有[pre,x]和[x,nex]这两条有用，其他更长更不优。
这样总的数量降至O(nlogn)级别。
对这些[x,y]进行扫描线。
考虑维护每个点为l的答案，在y时更新[1,x]的结果？发现会重复覆盖很难处理。
考虑维护每个点为l的贡献，在y时更新x位置，然后区间查询。
对于每个[x,y,w]，维护最远的x，避免重复更新。 
*/
