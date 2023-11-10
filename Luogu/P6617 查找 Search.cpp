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
			t[id].mx=qv;
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
	type ask_max(int l,int r)
	{
		ql=l;
		qr=r;
		return query(1,n,1).mx;
	}
	#undef type
	#undef ls
	#undef rs
}trpre;
set<int> s[MAX];
int a[MAX];
int main()
{
	int n,m,w,i,op,x,y,cnt,pos,pre,suf;
	scanf("%d%d%d",&n,&m,&w);
	for(i=0;i<=w;i++)
	{
		s[i].clear();
		s[i].insert(0);
		s[i].insert(n+1);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[a[i]].insert(i);
	}
	trpre.build(n);
	for(i=1;i<=n;i++)
	{
		pre=*(--s[w-a[i]].lower_bound(i));
		suf=*s[a[i]].upper_bound(pre);
		if(suf<i) pre=0;
		trpre.upd(i,i,pre);
	}
	cnt=0;
	while(m--)
	{
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)
		{
			s[a[x]].erase(x);
			s[y].insert(x);
			pos=*s[a[x]].upper_bound(x);
			if(pos<=n)
			{
				pre=*(--s[w-a[pos]].lower_bound(pos));
				suf=*s[a[pos]].upper_bound(pre);
				if(suf<pos) pre=0;
				trpre.upd(pos,pos,pre);
			}
			pos=*s[w-a[x]].upper_bound(x);
			if(pos<=n)
			{
				pre=*(--s[w-a[pos]].lower_bound(pos));
				suf=*s[a[pos]].upper_bound(pre);
				if(suf<pos) pre=0;
				trpre.upd(pos,pos,pre);
			}
			
			a[x]=y;
			
			pre=*(--s[w-a[x]].lower_bound(x));
			suf=*s[a[x]].upper_bound(pre);
			if(suf<x) pre=0;
			trpre.upd(x,x,pre);
			
			pos=*s[a[x]].upper_bound(x);
			if(pos<=n)
			{
				pre=*(--s[w-a[pos]].lower_bound(pos));
				suf=*s[a[pos]].upper_bound(pre);
				if(suf<pos) pre=0;
				trpre.upd(pos,pos,pre);
			}
			pos=*s[w-a[x]].upper_bound(x);
			if(pos<=n)
			{
				pre=*(--s[w-a[pos]].lower_bound(pos));
				suf=*s[a[pos]].upper_bound(pre);
				if(suf<pos) pre=0;
				trpre.upd(pos,pos,pre);
			}
		}
		else
		{
			x^=cnt;
			y^=cnt;
			if(trpre.ask_max(x,y)>=x)
			{
				cnt++;
				puts("Yes");
			}
			else puts("No");
		}
	//	for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
	//	for(i=1;i<=n;i++) printf("%d%c",trpre.ask_max(i,i)," \n"[i==n]);
	}
	return 0;
}
/*
一定要判合法，不合法要更新成0，不然会出问题 

10 100000 10
1 2 3 4 5 6 7 8 9 0
1 6 2
1 4 8
1 5 2
1 5 8
2 4 5
1 4 2
1 3 8
1 7 2
1 6 8
1 5 5
1 5 2
1 5 8
1 4 5
2 4 6
*/
