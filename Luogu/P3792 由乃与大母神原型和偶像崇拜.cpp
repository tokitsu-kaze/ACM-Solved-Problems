#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=5e5+10;
struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	struct node
	{
		type mn,mx,mxpre;
		void init()
		{
			mn=INF;
			mx=mxpre=-INF;
		}
	}t[MAX<<2];
	int n,ql,qr,qop;
	type a[MAX],pre[MAX],nex[MAX],qv;
	node merge(node x,node y)
	{
		node res;
		res.mn=min(x.mn,y.mn);
		res.mx=max(x.mx,y.mx);
		res.mxpre=max(x.mxpre,y.mxpre);
		return res;
	}
	void pushup(int id){t[id]=merge(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		
	}
	void build(int l,int r,int id)
	{
		t[id].init();
		if(l==r)
		{
			t[id].mx=t[id].mn=a[l];
			t[id].mxpre=pre[l];
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
			t[id].mx=t[id].mn=a[l];
			t[id].mxpre=pre[l];
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
	void upd(int l,int r)
	{
		ql=l;
		qr=r;
		update(1,n,1);
	}
	type ask(int l,int r)
	{
		ql=l;
		qr=r;
		auto res=query(1,n,1);
		if(res.mx-res.mn==r-l&&res.mxpre<l) return 1;
		return 0;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
map<int,int> lst;
set<int> s[MAX];
int main()
{
	int n,m,i,op,x,y;
	scanf("%d%d",&n,&m);
	lst.clear();
	for(i=1;i<=n;i++) s[i].clear();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&tr.a[i]);
		tr.pre[i]=0;
		tr.nex[i]=n+1;
		if(lst.count(tr.a[i]))
		{
			tr.pre[i]=lst[tr.a[i]];
			tr.nex[lst[tr.a[i]]]=i;
		}
		lst[tr.a[i]]=i;
		if(tr.a[i]<=n) s[tr.a[i]].insert(i);
	}
	tr.build(n);
	while(m--)
	{
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)
		{
			if(tr.a[x]==y) continue;
			if(tr.nex[x]<=n)
			{
				tr.pre[tr.nex[x]]=tr.pre[x];
				tr.upd(tr.nex[x],tr.nex[x]);
			}
			if(tr.pre[x]) tr.nex[tr.pre[x]]=tr.nex[x];
			if(tr.a[x]<=n) s[tr.a[x]].erase(x);
			tr.a[x]=y;
			s[tr.a[x]].insert(x);
			auto it=s[tr.a[x]].lower_bound(x);
			if(it!=s[tr.a[x]].begin()) tr.pre[x]=*(--it);
			it=s[tr.a[x]].upper_bound(x);
			if(it!=s[tr.a[x]].end()) tr.nex[x]=*it;
			tr.upd(x,x);
			if(tr.nex[x]<=n)
			{
				tr.pre[tr.nex[x]]=x;
				tr.upd(tr.nex[x],tr.nex[x]);
			}
			if(tr.pre[x]) tr.nex[tr.pre[x]]=x;
		}
		else puts(tr.ask(x,y)?"damushen":"yuanxing");
	}
	return 0;
}
