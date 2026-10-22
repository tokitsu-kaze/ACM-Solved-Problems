#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=6e5+10;
const int mod=1e9+7;
struct Discretization
{
	#define type pair<int,int>
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
ll inv2[MAX];
struct Segment_Tree
{
	#define type ll
	static const type inf=INF;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		type ans,lsum,rsum,len;
		void init(){ans=lsum=rsum=len=0;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.len=x.len+y.len;
		res.lsum=(x.lsum+y.lsum*inv2[x.len])%mod;
		res.rsum=(y.rsum+x.rsum*inv2[y.len])%mod;
		res.ans=(x.ans+y.ans+x.rsum*y.lsum)%mod;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void maintain(int l,int r,int id,type qv)
	{
		if(qv>0)
		{
			t[id].len=1;
			t[id].lsum=t[id].rsum=qv*inv2[1]%mod;
			t[id].ans=0;
		}
		else t[id].init();
	}
	void pushdown(int l,int r,int id)
	{
		
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			//init
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			maintain(l,r,id,qv);
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	node query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr) return t[id];
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(qr<=mid) return query(l,mid,ls);
		if(ql>mid) return query(mid+1,r,rs);
		return merge_node(query(l,mid,ls),query(mid+1,r,rs));
	}
	void build(int _n)
	{
		n=_n;
		build(1,n,1);
		null_node.init();
	}
	void upd(int l,int r,type v)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	type ask(int l,int r)
	{
		if(l>r) return null_node.ans;
		ql=l;
		qr=r;
		return query(1,n,1).ans;
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
int p[MAX],x[MAX],v[MAX];
int main()
{
	int n,q,i,pos;
	scanf("%d",&n);
	d.init();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		d.add({p[i],i});
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&x[i],&v[i]);
		d.add({v[i],x[i]});
	}
	d.work();
	inv2[0]=1;
	inv2[1]=(mod+1)/2;
	for(i=2;i<=n+q;i++) inv2[i]=inv2[i-1]*inv2[1]%mod;
	tr.build(n+q);
	for(i=1;i<=n;i++)
	{
		pos=d.get_pos({p[i],i});
		tr.upd(pos,pos,p[i]);
	}
	printf("%lld\n",tr.ask(1,n+q));
	for(i=1;i<=q;i++)
	{
		pos=d.get_pos({p[x[i]],x[i]});
		tr.upd(pos,pos,-p[x[i]]);
		p[x[i]]=v[i];
		pos=d.get_pos({p[x[i]],x[i]});
		tr.upd(pos,pos,p[x[i]]);
		printf("%lld\n",tr.ask(1,n+q));
	}
	return 0;
}
/*
考虑排序后相邻两个数产生的贡献。
如果 pi pj 产生贡献，那么中间的数都不能选，所以贡献为 pi*pj*(1/2^(j-i+1))。
考虑线段树直接维护。但直接合并需要 O(len^2)，考虑把式子拆开。
*/
