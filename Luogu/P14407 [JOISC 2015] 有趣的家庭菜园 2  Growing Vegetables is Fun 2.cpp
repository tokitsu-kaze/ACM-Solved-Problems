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
struct Segment_Tree
{
	#define type ll
	static const type inf=LLINF;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		type v;
		void init(){v=0;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.v=max(x.v,y.v);
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void maintain(int l,int r,int id,type qv)
	{
		t[id].v+=qv;
		tag[id]+=qv;
	}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		maintain(l,mid,ls,tag[id]);
		maintain(mid+1,r,rs,tag[id]);
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id].v=-inf;
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
			if(qop==1) maintain(l,r,id,qv);
			else t[id].v=max(t[id].v,qv);
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
	void upd(int l,int r,type v,int op)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		qop=op;
		update(1,n,1);
	}
	type ask(int l,int r)
	{
		if(l>r) return null_node.v;
		ql=l;
		qr=r;
		return query(1,n,1).v;
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
int h[MAX],p[MAX],c[MAX];
ll dppre[MAX],dpsuf[MAX];
int main()
{
	int n,i,pos0,V;
	ll ans;
	scanf("%d",&n);
	d.init();
	d.add(0);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&h[i],&p[i],&c[i]);
		d.add(h[i]);
	}
	d.work();
	V=d.size();
	for(i=1;i<=n;i++) h[i]=d.get_pos(h[i]);
	pos0=d.get_pos(0);
	
	tr.build(V);
	tr.upd(pos0,pos0,0,2);
	dppre[0]=0;
	for(i=1;i<=n;i++)
	{
		dppre[i]=tr.ask(1,h[i])+p[i];
		tr.upd(1,h[i]-1,-c[i],1);
		tr.upd(h[i],h[i],dppre[i],2);
	}
	
	tr.build(V);
	tr.upd(pos0,pos0,0,2);
	dpsuf[n+1]=0;
	for(i=n;i;i--)
	{
		dpsuf[i]=tr.ask(1,h[i])+p[i];
		tr.upd(1,h[i]-1,-c[i],1);
		tr.upd(h[i],h[i],dpsuf[i],2);
	}
	
	ans=0;
	for(i=1;i<=n;i++) ans=max(ans,dppre[i]+dpsuf[i]-p[i]);
	printf("%lld\n",ans);
	return 0;
}
/*
发现最后正贡献的形状是一个先增后减的，山峰。
上升的情况，从左边比他矮的转移，并且要减掉中间比他高的。
考虑将中间比他高的，看成在之前就做过前缀减。
所以发现操作能用线段树维护：前缀减，前缀查询max，单点更新max。
下降的情况：反过来做上升。
最后枚举中间，拼一下。
*/
