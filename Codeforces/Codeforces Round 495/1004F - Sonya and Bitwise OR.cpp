#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int xlimt;
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop,qv;
	type a[MAX],tag[MAX<<2];
	struct val_seg{int v,cnt;};
	struct node
	{
		type ans;
		int prelen,suflen;
		val_seg pre[35],suf[35];
		void init(){ans=prelen=suflen=0;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		if(x.prelen==0) return y;
		if(y.prelen==0) return x;
		int i,j,cnty,newv;
		node res;
		
		res.ans=x.ans+y.ans;
		cnty=0;
		for(i=0,j=y.prelen-1;i<x.suflen;i++)
		{
			while(j>=0&&(x.suf[i].v|y.pre[j].v)>=xlimt)
			{
				cnty+=y.pre[j].cnt;
				j--;
			}
			res.ans+=1LL*x.suf[i].cnt*cnty;
		}
		
		res.prelen=x.prelen;
		for(i=0;i<x.prelen;i++) res.pre[i]=x.pre[i];
		for(i=0;i<y.prelen;i++)
		{
			newv=(x.pre[x.prelen-1].v|y.pre[i].v);
			if(res.pre[res.prelen-1].v==newv) res.pre[res.prelen-1].cnt+=y.pre[i].cnt;
			else res.pre[res.prelen++]={newv,y.pre[i].cnt};
		}
		
		res.suflen=y.suflen;
		for(i=0;i<y.suflen;i++) res.suf[i]=y.suf[i];
		for(i=0;i<x.suflen;i++)
		{
			newv=(y.suf[y.suflen-1].v|x.suf[i].v);
			if(res.suf[res.suflen-1].v==newv) res.suf[res.suflen-1].cnt+=x.suf[i].cnt;
			else res.suf[res.suflen++]={newv,x.suf[i].cnt};
		}
		
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void maintain(int l,int r,int id,int v)
	{
		if(v>=xlimt) t[id].ans=1;
		else t[id].ans=0;
		t[id].prelen=t[id].suflen=1;
		t[id].pre[0]={v,1};
		t[id].suf[0]={v,1};
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
			maintain(l,r,id,a[l]);
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
	void upd(int l,int r,int v)
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
int main()
{
	int n,q,i,op,l,r,x,y;
	scanf("%d%d%d",&n,&q,&xlimt);
	for(i=1;i<=n;i++) scanf("%lld",&tr.a[i]);
	tr.build(n);
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&x,&y);
			tr.upd(x,x,y);
		}
		else
		{
			scanf("%d%d",&l,&r);
			printf("%lld\n",tr.ask(l,r));
		}
	}
	return 0;
}
/*
做法跟这个题几乎一致，只不过这题求的是 gcd：P4435 [COCI 2017/2018 #2] ??Gara?a
考虑用线段树合并区间的答案。
当两个区间合并时，新产生的贡献需要拼接左端点的后缀，以及右端点的前缀。
由于前缀 or 只有 log 种值，直接暴力合并，合并复杂度是 O(log^2 V) 的。
但 or 有单调性，考虑双指针一下。
维护的时候直接维护整段的所有 or 的值，前后缀 or 都维护一下。
总复杂度为 O(n log n log V)。
*/
