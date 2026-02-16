#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Segment_Tree
{
	#define type ll
	static const type inf=LLINF;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],b[MAX],tag[MAX<<2],qva,qvb;
	struct node
	{
		type Atot,Btot;
		type Apmax,Asmax,Bpmax,Bsmax;
		type ansAR,ansAL,ansBR,ansBL;
		type ansALBL,ansALBR,ansARBL,ansARBR;
		type Asubmax,Bsubmax;
		type ans;
		void init()
		{
			Atot=-inf; // sum of A within the node
			Btot=-inf; // sum of B

			Apmax=-inf; // A array max prefix sum
			Asmax=-inf; // A array max suffix sum
			Bpmax=-inf; // B array max prefix sum
			Bsmax=-inf; // B array max suffix sum

			ansAR=-inf; // answer, such that A subarray touch Right end
			ansAL=-inf; // answer, such that A subarray touch Left end
			ansBR=-inf; // answer, such that B subarray touch Right end
			ansBL=-inf; // answer, such that B subarray touch Left end

			ansALBL=-inf; // answer such that A array touch Left, B touches Left
			ansALBR=-inf; // answer such that A array touch Left, B touches Right
			ansARBL=-inf; // answer such that A array touch Right, B touches Left
			ansARBR=-inf; // answer such that A array touch Right, B touches Right

			Asubmax=-inf; // maximal subarray sum of A array
			Bsubmax=-inf; // maximal subarray sum of B array
			
			ans=-inf; // answer for the node
		}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.init();
		
		res.Atot=x.Atot+y.Atot;
		res.Btot=x.Btot+y.Btot;
		
		res.Apmax=max(x.Apmax,x.Atot+y.Apmax);
		res.Bpmax=max(x.Bpmax,x.Btot+y.Bpmax);
		res.Asmax=max(y.Asmax,y.Atot+x.Asmax);
		res.Bsmax=max(y.Bsmax,y.Btot+x.Bsmax);
		
		res.Asubmax=max(res.Asubmax,x.Asubmax);
		res.Asubmax=max(res.Asubmax,y.Asubmax);
		res.Asubmax=max(res.Asubmax,x.Asmax+y.Apmax);
		
		res.Bsubmax=max(res.Bsubmax,x.Bsubmax);
		res.Bsubmax=max(res.Bsubmax,y.Bsubmax);
		res.Bsubmax=max(res.Bsubmax,x.Bsmax+y.Bpmax);
		
		res.ansAR=max(res.ansAR,y.ansAR);
		res.ansAR=max(res.ansAR,y.ansARBL+x.Bsmax);
		res.ansAR=max(res.ansAR,x.ansAR+y.Atot);
		res.ansAR=max(res.ansAR,y.Bsubmax+y.Atot+x.Asmax);
		res.ansAR=max(res.ansAR,x.ansARBR+y.Atot+y.Bpmax);
		
		res.ansAL=max(res.ansAL,x.ansAL);
		res.ansAL=max(res.ansAL,x.ansALBR+y.Bpmax);
		res.ansAL=max(res.ansAL,y.ansAL+x.Atot);
		res.ansAL=max(res.ansAL,x.Bsubmax+x.Atot+y.Apmax);
		res.ansAL=max(res.ansAL,y.ansALBL+x.Atot+x.Bsmax);
		
		res.ansBR=max(res.ansBR,y.ansBR);
		res.ansBR=max(res.ansBR,y.ansALBR+x.Asmax);
		res.ansBR=max(res.ansBR,x.ansBR+y.Btot);
		res.ansBR=max(res.ansBR,y.Asubmax+y.Btot+x.Bsmax);
		res.ansBR=max(res.ansBR,x.ansARBR+y.Btot+y.Apmax);
		
		res.ansBL=max(res.ansBL,x.ansBL);
		res.ansBL=max(res.ansBL,x.ansARBL+y.Apmax);
		res.ansBL=max(res.ansBL,y.ansBL+x.Btot);
		res.ansBL=max(res.ansBL,x.Asubmax+x.Btot+y.Bpmax);
		res.ansBL=max(res.ansBL,y.ansALBL+x.Btot+x.Asmax);
		
		res.ansALBL=max(res.ansALBL,x.ansALBL);
		res.ansALBL=max(res.ansALBL,x.Atot+y.Apmax+x.Bpmax);
		res.ansALBL=max(res.ansALBL,x.Btot+y.Bpmax+x.Apmax);
		res.ansALBL=max(res.ansALBL,x.Atot+x.Btot+y.ansALBL);
		
		res.ansARBR=max(res.ansARBR,y.ansARBR);
		res.ansARBR=max(res.ansARBR,y.Atot+x.Asmax+y.Bsmax);
		res.ansARBR=max(res.ansARBR,y.Btot+x.Bsmax+y.Asmax);
		res.ansARBR=max(res.ansARBR,y.Atot+y.Btot+x.ansARBR);
		
		res.ansALBR=max(res.ansALBR,x.Atot+y.Btot+x.Bsmax+y.Apmax);
		res.ansALBR=max(res.ansALBR,x.Atot+y.ansALBR);
		res.ansALBR=max(res.ansALBR,y.Btot+x.ansALBR);
		
		res.ansARBL=max(res.ansARBL,y.Atot+x.Btot+y.Bpmax+x.Asmax);
		res.ansARBL=max(res.ansARBL,y.Atot+x.ansARBL);
		res.ansARBL=max(res.ansARBL,x.Btot+y.ansARBL);
		
		res.ans=max(res.ans,x.ans);
		res.ans=max(res.ans,y.ans);
		
		res.ans=max(res.ans,x.ansAR+y.Apmax);
		res.ans=max(res.ans,y.ansAL+x.Asmax);
		res.ans=max(res.ans,x.ansARBR+y.ansALBL);
		
		res.ans=max(res.ans,x.ansBR+y.Bpmax);
		res.ans=max(res.ans,y.ansBL+x.Bsmax);
		res.ans=max(res.ans,x.ansARBR+y.ansALBL);
		
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			t[id]={a[l],b[l],
				   a[l],a[l],b[l],b[l],
				   a[l]+b[l],a[l]+b[l],a[l]+b[l],a[l]+b[l],
				   a[l]+b[l],a[l]+b[l],a[l]+b[l],a[l]+b[l],
				   a[l],b[l],
				   a[l]+b[l]};
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
			a[l]=qva;
			b[l]=qvb;
			t[id]={a[l],b[l],
				   a[l],a[l],b[l],b[l],
				   a[l]+b[l],a[l]+b[l],a[l]+b[l],a[l]+b[l],
				   a[l]+b[l],a[l]+b[l],a[l]+b[l],a[l]+b[l],
				   a[l],b[l],
				   a[l]+b[l]};
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
	void upd(int l,int r,type va,type vb)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qva=va;
		qvb=vb;
		update(1,n,1);
	}
	type ask(int l,int r)
	{
		if(l>r) assert(0);
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
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%lld",&tr.a[i]);
		for(i=1;i<=n;i++) scanf("%lld",&tr.b[i]);
		tr.build(n);
		printf("%lld\n",tr.ask(1,n));
	}
	return 0;
}
