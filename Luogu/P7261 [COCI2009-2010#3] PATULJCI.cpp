#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	struct node
	{
		type v,vote;
		void init()
		{
			v=vote=0;
		}
	}t[MAX<<2];
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	node merge(node x,node y)
	{
		node res;
		if(x.v==y.v)
		{
			res.v=x.v;
			res.vote=x.vote+y.vote;
		}
		else
		{
			if(x.vote>y.vote) res=x;
			else res=y;
			res.vote-=min(x.vote,y.vote);
		}
		return res;
	}
	void pushup(int id){t[id]=merge(t[ls],t[rs]);}
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
			t[id].v=a[l];
			t[id].vote=1;
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
		return query(1,n,1).v;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
vector<int> pos[MAX];
int a[MAX];
int cal(int l,int r,int x)
{
	return upper_bound(pos[x].begin(),pos[x].end(),r)-
		   lower_bound(pos[x].begin(),pos[x].end(),l);
}
int main()
{
	int n,c,q,i,l,r,res;
	scanf("%d%d",&n,&c);
	for(i=1;i<=n;i++) pos[i].clear();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&tr.a[i]);
		pos[tr.a[i]].push_back(i);
	}
	tr.build(n);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&l,&r);
		res=tr.ask(l,r);
		if(cal(l,r,res)*2<=r-l+1) puts("no");
		else printf("yes %d\n",res);
	}
	return 0;
}
