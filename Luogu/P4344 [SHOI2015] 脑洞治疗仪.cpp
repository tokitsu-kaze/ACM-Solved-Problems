#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	struct node
	{
		type mx,lmx,rmx,v,len;
		void init()
		{
			mx=lmx=rmx=v=0;
		}
	}t[MAX<<2];
	int n,ql,qr,qop;
	type tag[MAX<<2],qv;
	node merge(node x,node y)
	{
		node res;
		res.v=x.v+y.v;
		res.lmx=x.lmx;
		if(x.lmx==x.len) res.lmx=x.len+y.lmx;
		res.rmx=y.rmx;
		if(y.rmx==y.len) res.rmx=y.len+x.rmx;
		res.mx=max({x.mx,y.mx,x.rmx+y.lmx});
		res.len=x.len+y.len;
		return res;
	}
	void pushup(int id){t[id]=merge(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(tag[id]==-1) return;
		int mid=(l+r)>>1;
		t[ls].v=tag[id]*(mid-l+1);
		if(!tag[id]) t[ls].lmx=t[ls].rmx=t[ls].mx=(mid-l+1);
		else t[ls].lmx=t[ls].rmx=t[ls].mx=0;
		t[rs].v=tag[id]*(r-mid);
		if(!tag[id]) t[rs].lmx=t[rs].rmx=t[rs].mx=(r-mid);
		else t[rs].lmx=t[rs].rmx=t[rs].mx=0;
		tag[ls]=tag[rs]=tag[id];
		tag[id]=-1;
	}
	void build(int l,int r,int id)
	{
		tag[id]=-1;
		t[id].init();
		if(l==r)
		{
			t[id].len=1;
			t[id].v=1;
			t[id].lmx=t[id].rmx=t[id].mx=0;
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
			t[id].v=(r-l+1)*qv;
			if(!qv) t[id].mx=t[id].lmx=t[id].rmx=(r-l+1);
			else t[id].mx=t[id].lmx=t[id].rmx=0;
			tag[id]=qv;
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
	type ask_sum(int l,int r)
	{
		ql=l;
		qr=r;
		return query(1,n,1).v;
	}
	type ask_max(int l,int r)
	{
		ql=l;
		qr=r;
		return query(1,n,1).mx;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
int main()
{
	int n,m,i,op,l,r,x,y,mid,s;
	scanf("%d%d",&n,&m);
	tr.build(n);
	while(m--)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op==0) tr.upd(l,r,0);
		else if(op==1)
		{
			s=tr.ask_sum(l,r);
	//		printf("s:%d\n",s);
			tr.upd(l,r,0);
			scanf("%d%d",&x,&y);
			if(s==0) continue;
			l=x;
			r=y;
			while(l<r)
			{
				mid=(l+r)>>1;
				if((mid-x+2)-tr.ask_sum(x,mid+1)<=s) l=mid+1;
				else r=mid;
			}
			tr.upd(x,l,1);
	//		printf("l,r: %d %d\n",x,l);
		}
		else printf("%d\n",tr.ask_max(l,r));
	}
	return 0;
}

