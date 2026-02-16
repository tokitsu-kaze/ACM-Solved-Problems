#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
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
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type qv;
	struct node
	{
		int sz;
		type sum;
		void init(){sz=sum=0;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.sz=x.sz+y.sz;
		res.sum=x.sum+y.sum;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void build(int l,int r,int id)
	{
		t[id].init();
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			t[id].sz++;
			t[id].sum+=qv;
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	type query_kth_sum(int l,int r,int id,int k)
	{
		if(!k) return 0;
		if(l==r) return 1LL*k*d.get_val(l);
		int mid=(l+r)>>1;
		type res=0;
		if(k<=t[ls].sz) res+=query_kth_sum(l,mid,ls,k);
		else
		{
			res+=t[ls].sum;
			res+=query_kth_sum(mid+1,r,rs,k-t[ls].sz);
		}
		return res;
	}
	void build(int _n)
	{
		n=_n;
		build(1,n,1);
		null_node.init();
	}
	void upd(int x,type v)
	{
		ql=qr=x;
		qv=v;
		update(1,n,1);
	}
	type ask_kth_sum(int k)
	{
		return query_kth_sum(1,n,1,k);
	}
	#undef type
	#undef ls
	#undef rs
}tr;
/*
tr.build(n);
tr.upd(l,r,v);
tr.ask(l,r);
Segment_Tree::node res=tr.merge_node(nodex,nodey);
*/
struct node{int k,id,sgn;};
vector<node> qst[MAX];
int a[MAX];
ll ans[MAX];
int main()
{
	int n,q,i,c,op,l,r,tot;
	scanf("%d",&n);
	d.init();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		d.add(a[i]);
		qst[i].clear();
	}
	d.work();
	scanf("%d",&q);
	c=tot=0;
	for(i=1;i<=q;i++)
	{
		scanf("%d",&op);
		if(op==1) c++;
		else
		{
			scanf("%d%d",&l,&r);
			tot++;
			qst[min(n,r+c)].push_back({r,tot,1});
			if(l>1) qst[min(n,l-1+c)].push_back({l-1,tot,-1});
			ans[tot]=0;
		}
	}
	tr.build(n);
	for(i=1;i<=n;i++)
	{
		tr.upd(d.get_pos(a[i]),a[i]);
		for(auto &qs:qst[i]) ans[qs.id]+=qs.sgn*tr.ask_kth_sum(qs.k);
	}
	for(i=1;i<=tot;i++) printf("%lld\n",ans[i]);
	return 0;
}
/*
前缀[1,l]在经过c轮冒泡排序后，数字构成是原来前缀[1,l+c]中前l小的数。
考虑把区间询问拆成[1,l-1+c] [1,r+c]，
离线下来，扫描线+线段树上二分求前k小之和。
*/

