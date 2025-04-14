#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
struct Segment_Tree
{
	#define type int
	static const type inf=INF;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		type mx;
		void init(){mx=-inf;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.mx=max(x.mx,y.mx);
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
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
			tag[id]+=qv;
			t[id].mx+=qv;
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
		if(l>r) return null_node.mx;
		ql=l;
		qr=r;
		return query(1,n,1).mx;
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
vector<int> pos[MAX];
int a[MAX],p[MAX],cnt[MAX];
int main()
{
	int n,i,ans,suf,pre;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		pos[i].clear();
		p[i]=cnt[i]=0;
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++) pos[a[i]].push_back(i);
	tr.build(n);
	suf=0;
	for(i=1;i<=n;i++)
	{
		if(pos[i].size()>=2) tr.upd(pos[i][0],pos[i].back()-1,1);
		if(pos[i].size()>0) suf++;
	}
	ans=0;
	pre=0;
	for(i=1;i<=n;i++)
	{
		if(pos[a[i]].size()-p[a[i]]>=2)
		{
			tr.upd(pos[a[i]][p[a[i]]],pos[a[i]].back()-1,-1);
		}
		p[a[i]]++;
		if(pos[a[i]].size()-p[a[i]]>=2)
		{
			tr.upd(pos[a[i]][p[a[i]]],pos[a[i]].back()-1,1);
		}
		else if(pos[a[i]].size()-p[a[i]]==0) suf--;
		cnt[a[i]]++;
		if(cnt[a[i]]==1) pre++;
//		printf("%d %d %d %d\n",i,pre,suf,tr.ask(i+1,n-1));
		ans=max(ans,pre+suf+tr.ask(i+1,n-1));
	}
	printf("%d\n",ans);
	return 0;
}

