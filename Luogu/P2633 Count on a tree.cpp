#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct Discretization
{
	#define type ll
	#define all(x) x.begin(),x.end()
	vector<type> a;
	void init(){a.clear();}
	void add(type x){a.push_back(x);}
	void work(){sort(all(a));a.resize(unique(all(a))-a.begin());}
	int get_pos(type x){return upper_bound(all(a),x)-a.begin();} // <= x
	type get_val(int pos){return a[pos-1];}
	int size(){return a.size();}
	#undef type
	#undef all
}d;
struct LCA
{
	static const int N=MAX;
	static const int LOG=log2(N)+2;
	int fa[LOG][N],dep[N];
	vector<int> *mp;
	void dfs(int x,int pre)
	{
		int i;
		fa[0][x]=pre;
		for(i=1;i<LOG;i++) fa[i][x]=fa[i-1][fa[i-1][x]];
		for(auto &to:mp[x])
		{
			if(to==pre) continue;
			dep[to]=dep[x]+1;
			dfs(to,x);
		}
	}
	void work(int n,int root,vector<int> *_mp)
	{
		mp=_mp;
		for(int j=0;j<LOG;j++) fa[j][0]=0;
		dep[root]=0;
		dfs(root,0);
	}
	int go(int x,int d)
	{
		for(int i=0;i<LOG;i++)
		{
			if((d>>i)&1) x=fa[i][x];
		}
		return x;
	}
	int lca(int x,int y)
	{
		if(dep[x]<dep[y]) swap(x,y);
		x=go(x,dep[x]-dep[y]);
		if(x==y) return x;
		for(int i=LOG-1;~i;i--)
		{
			if(fa[i][x]!=fa[i][y])
			{
				x=fa[i][x];
				y=fa[i][y];
			}
		}
		return fa[0][x];
	}
	int get_len(int a,int b){return dep[a]+dep[b]-2*dep[lca(a,b)];}
}lca;
/*
O(nlogn)-O(logn)
lca.work(n,root,mp);
*/
struct Persistent_Segment_Tree
{
	#define type int
	int root[MAX],ls[MAX<<5],rs[MAX<<5],tot,ql,qr,n;
	type v[MAX<<5],qv,res;
	void init(int _n)
	{
		n=_n;
		root[0]=0;
		ls[0]=rs[0]=v[0]=tot=0;
	}
	int copy_node(int x)
	{
		++tot;
		ls[tot]=ls[x];
		rs[tot]=rs[x];
		v[tot]=v[x];
		return tot;
	}
	void update(int l,int r,int &id,int pre)
	{
		if(!id) id=copy_node(pre);
		v[id]+=qv;
		if(l==r) return;
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls[id]=0,ls[pre]);
		else update(mid+1,r,rs[id]=0,rs[pre]);
	}
	int kth_small(int l,int r,int x,int y,int z,int faz,int k)
	{
		if(l==r) return l;
		int mid=(l+r)>>1;
		int tmp=v[ls[x]]+v[ls[y]]-v[ls[z]]-v[ls[faz]];
		if(tmp>=k) return kth_small(l,mid,ls[x],ls[y],ls[z],ls[faz],k);
		else return kth_small(mid+1,r,rs[x],rs[y],rs[z],rs[faz],k-tmp);
	}
	void create_ver(int now_ver,int pre_ver,int pos,type v)
	{
		root[now_ver]=0;
		ql=qr=pos;
		qv=v;
		update(1,n,root[now_ver],root[pre_ver]);
	}
	void copy_ver(int now_ver,int pre_ver)
	{
		root[now_ver]=root[pre_ver];
	}
	void update_ver(int now_ver,int pos,type v)
	{
		int now_root=root[now_ver];
		root[now_ver]=0;
		ql=qr=pos;
		qv=v;
		update(1,n,root[now_ver],now_root);
	}
	int ask_kth_small(int x,int y,int z,int faz,int k)
	{
		return kth_small(1,n,root[x],root[y],root[z],root[faz],k);
	}
	#undef type
}tr;
/*
tr.init(n);
tr.create_ver(now_ver,pre_ver,pos,v);
tr.copy_ver(now_ver,pre_ver);
tr.update_ver(now_ver,pos,v);
tr.ask_kth_small(l,r,k);
tr.ask_valsum(l,r,val_l,val_r);
*/
int v[MAX];
vector<int> mp[MAX];
void dfs(int x,int fa)
{
	tr.create_ver(x,fa,d.get_pos(v[x]),1);
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
	}
}
int main()
{
	int n,m,i,x,y,z,k,lst;
	scanf("%d%d",&n,&m);
	d.init();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&v[i]);
		d.add(v[i]);
		mp[i].clear();
	}
	d.work();
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
	lca.work(n,1,mp);
	lst=0;
	tr.init(n);
	dfs(1,0);
	while(m--)
	{
		scanf("%d%d%d",&x,&y,&k);
		x^=lst;
		z=lca.lca(x,y);
		lst=d.get_val(tr.ask_kth_small(x,y,z,lca.fa[0][z],k));
		printf("%d\n",lst);
	}
	return 0;
}
