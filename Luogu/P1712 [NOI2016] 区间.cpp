#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
struct Discretization
{
	#define type int
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
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	struct node
	{
		type mx;
		void init()
		{
			mx=-INF;
		}
	}t[MAX<<2];
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	node merge(node x,node y)
	{
		node res;
		res.mx=max(x.mx,y.mx);
		return res;
	}
	void pushup(int id){t[id]=merge(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		t[ls].mx+=tag[id];
		t[rs].mx+=tag[id];
		tag[ls]+=tag[id];
		tag[rs]+=tag[id];
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id].mx=0;
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
			t[id].mx+=qv;
			tag[id]+=qv;
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
		return merge(query(l,mid,ls),query(mid+1,r,rs));
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,type v)
	{
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	type ask(int l,int r)
	{
		ql=l;
		qr=r;
		return query(1,n,1).mx;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
struct node{int l,r,v;};
int main()
{
	int n,m,i,j,l,r,ans,sz;
	scanf("%d%d",&n,&m);
	vector<node> a;
	d.init();
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&l,&r);
		a.push_back({l,r,r-l});
		d.add(l);
		d.add(r);
	}
	d.work();
	for(i=0;i<n;i++)
	{
		a[i].l=d.get_pos(a[i].l);
		a[i].r=d.get_pos(a[i].r);
	}
	sort(a.begin(),a.end(),[&](node x,node y){
		return x.v<y.v;
	});
	ans=INF;
	sz=d.size();
	tr.build(sz);
	for(i=0,j=0;i<n;i++)
	{
		while(j<n&&tr.ask(1,sz)<m)
		{
			tr.upd(a[j].l,a[j].r,1);
			j++;
		}
		if(tr.ask(1,sz)>=m) ans=min(ans,a[j-1].v-a[i].v);
		tr.upd(a[i].l,a[i].r,-1);
	}
	if(ans==INF) ans=-1;
	printf("%d\n",ans);
	return 0;
}
