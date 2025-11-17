#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
const int mod=998244353;
ll qpow(ll a,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll inv(ll x){return qpow(x,mod-2);}
struct Discretization
{
	#define type ll
	#define all(x) x.begin(),x.end()
	vector<type> a;
	void init(){a.clear();}
	void add(type x){a.push_back(x);}
	void work(){sort(all(a));a.resize(unique(all(a))-a.begin());}
	int get_pos(type x){return lower_bound(all(a),x)-a.begin()+1;}
	type get_val(int pos){return a[pos-1];}
	int size(){return a.size();}
	#undef type
	#undef all
}d;
struct Segment_Tree
{
	#define type ll
	static const int LOG=20;
	struct node
	{
		type v;
		void init(){v=0;}
	}t[MAX*LOG],null_node;
	int root[MAX],ls[MAX*LOG],rs[MAX*LOG],rt,tot,qop,ql,qr,n;
	int st[MAX*LOG],top;
	type qv,tag[MAX*LOG],p,res;
	Segment_Tree &operator[](const int _rt){this->rt=_rt;return *this;}
	void init(int _n)
	{
		n=_n;
		rt=1;
		tot=top=0;
		t[0].init();
		ls[0]=rs[0]=0;
		null_node.init();
	}
	void build(){root[rt]=0;}
	void delnode(int id){st[top++]=id;}
	int newnode()
	{
		int id;
		id=top?st[--top]:++tot;
		t[id].init();
		ls[id]=rs[id]=0;
		tag[id]=1;
		return id;
	}
	node merge_node(node x,node y)
	{
		node res;
		res.v=(x.v+y.v)%mod;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls[id]],t[rs[id]]);}
	void pushdown(int l,int r,int id)
	{
		if(tag[id]==1) return;
		if(ls[id])
		{
			t[ls[id]].v=t[ls[id]].v*tag[id]%mod;
			tag[ls[id]]=tag[ls[id]]*tag[id]%mod;
		}
		if(rs[id])
		{
			t[rs[id]].v=t[rs[id]].v*tag[id]%mod;
			tag[rs[id]]=tag[rs[id]]*tag[id]%mod;
		}
		tag[id]=1;
	}
	void maintain(int id,type mul)
	{
		t[id].v=t[id].v*mul%mod;
		tag[id]=tag[id]*mul%mod;
	}
	void update(int l,int r,int &id)
	{
		if(!id) id=newnode();
		if(l>=ql&&r<=qr)
		{
			t[id].v=qv;
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls[id]);
		if(qr>mid) update(mid+1,r,rs[id]);
		pushup(id);
	}
	node query(int l,int r,int id)
	{
		if(!id) return null_node;
		if(l>=ql&&r<=qr) return t[id];
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(qr<=mid) return query(l,mid,ls[id]);
		if(ql>mid) return query(mid+1,r,rs[id]);
		return merge_node(query(l,mid,ls[id]),query(mid+1,r,rs[id]));
	}
	int merge(int l,int r,int x,int y,
			  type presumx,type sufsumx,
			  type presumy,type sufsumy)
	{
		if(!x||!y)
		{
			if(x) maintain(x,(p*presumy+(1-p+mod)*sufsumy)%mod);
			if(y) maintain(y,(p*presumx+(1-p+mod)*sufsumx)%mod);
			return x+y;
		}
		if(l==r)
		{
			assert(0);
			//merge info x <- y
			t[x].v+=t[y].v;
			delnode(y);
			return x;
		}
		pushdown(l,r,x);
		pushdown(l,r,y);
		int mid=(l+r)>>1;
		type lx=t[ls[x]].v;
		type rx=t[rs[x]].v;
		type ly=t[ls[y]].v;
		type ry=t[rs[y]].v;
		ls[x]=merge(l,mid,ls[x],ls[y],presumx,(sufsumx+rx)%mod,
									  presumy,(sufsumy+ry)%mod);
		rs[x]=merge(mid+1,r,rs[x],rs[y],(presumx+lx)%mod,sufsumx,
									  (presumy+ly)%mod,sufsumy);
		pushup(x);
		delnode(y);
		return x;
	}
	void merge_segtree(int y,type _p)
	{
		p=_p;
		if(root[rt]==0) root[rt]=root[y];
		else root[rt]=merge(1,n,root[rt],root[y],0,0,0,0);
		root[y]=0;
	}
	void upd(int l,int r,type v)
	{
		ql=l;
		qr=r;
		qv=v;
		update(1,n,root[rt]);
	}
	void dfs(int l,int r,int id)
	{
		if(!id) return;
		if(l==r)
		{
			res=(res+l*d.get_val(l)%mod*t[id].v%mod*t[id].v)%mod;
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		dfs(l,mid,ls[id]);
		dfs(mid+1,r,rs[id]);
	}
	type get_ans()
	{
		res=0;
		dfs(1,n,root[rt]);
		return res;
	}
	#undef type
}tr;
/*
tr.init(n);
tr.build();
tr.upd(l,r,v);
tr.ask(l,r);
Segment_Tree::node res=tr.merge_node(nodex,nodey);
---------
tr[x].build();
tr[x].merge_segtree(y);
tr[x].split_segtree(l,r,new_tree);
*/
vector<int> mp[MAX];
ll p[MAX];
void dfs(int x)
{
	tr[x].build();
	for(auto &to:mp[x])
	{
		dfs(to);
		tr[x].merge_segtree(to,p[x]);
	}
	if(mp[x].size()==0)
	{
		int v=d.get_pos(p[x]);
		tr[x].upd(v,v,1);
	}
}
int main()
{
	int n,i,fa;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&fa);
		if(i>1) mp[fa].push_back(i);
	}
	d.init();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		if(mp[i].size()>0) p[i]=p[i]*inv(10000)%mod;
		else d.add(p[i]);
	}
	d.work();
	tr.init(d.size());
	dfs(1);
	printf("%lld\n",tr[1].get_ans());
	return 0;
}
