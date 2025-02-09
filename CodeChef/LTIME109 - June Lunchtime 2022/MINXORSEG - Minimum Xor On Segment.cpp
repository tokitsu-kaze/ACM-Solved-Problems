#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
struct Segment_Tree
{
	#define type int
	static const type inf=2e9;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		type mn;
		void init(){mn=inf;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.mn=min(x.mn,y.mn);
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
			t[id].mn=min(t[id].mn,qv);
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
		if(l>r) return null_node.mn;
		ql=l;
		qr=r;
		return query(1,n,1).mn;
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
struct Q{int l,id;};
vector<Q> qst[MAX];
vector<int> pos[MAX];
pair<int,int> tmp[MAX];
int a[MAX],ans[MAX];
int main()
{
	int n,q,i,j,l,r;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pos[i].clear();
		qst[i].clear();
	}
	for(j=0;j<=30;j++)
	{
		for(i=1;i<=n;i++) tmp[i]={a[i]>>j,i};
		sort(tmp+1,tmp+1+n);
		for(i=2;i<=n;i++)
		{
			if(tmp[i].first!=tmp[i-1].first) continue;
			pos[tmp[i].second].push_back(tmp[i-1].second);
		}
	}
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&r);
		qst[r].push_back({l,i});
	}
	tr.build(n);
	for(i=1;i<=n;i++)
	{
		for(auto &it:pos[i]) tr.upd(it,it,a[it]^a[i]);
		for(auto &it:qst[i]) ans[it.id]=tr.ask(it.l,i);
	}
	for(i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
