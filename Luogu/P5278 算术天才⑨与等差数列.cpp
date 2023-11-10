#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
struct Segment_Tree
{
	#define type int
	#define ls (id<<1)
	#define rs (id<<1|1)
	struct node
	{
		type mn,mx,mxpre,g;
		void init()
		{
			mn=INF;
			mx=mxpre=-INF;
			g=0;
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
		res.g=__gcd(x.g,y.g);
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
			if(l>1) t[id].g=abs(a[l]-a[l-1]);
			else t[id].g=0;
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(l==r)
		{
			t[id].mx=t[id].mn=a[l];
			t[id].mxpre=pre[l];
			if(l>1) t[id].g=abs(a[l]-a[l-1]);
			else t[id].g=0;
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
		qr=min(n,r);
		update(1,n,1);
	}
	int ask(int l,int r,int k)
	{
		if(l==r) return 1;
		ql=l;
		qr=r;
		auto res=query(1,n,1);
		if(res.mx-res.mn!=1ll*(r-l)*k) return 0;
		if(res.mxpre>=l&&k!=0) return 0;
		ql=l+1;
		qr=r;
		res=query(1,n,1);
		if(res.g==k||res.g==0) return 1;
		return 0;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
map<int,int> id;
set<int> s[MAX<<1];
int lst[MAX<<1];
int main()
{
	int n,m,i,op,x,y,k,tot,cnt,cas;
	scanf("%d%d",&n,&m);
	id.clear();
	tot=0;
	for(i=1;i<=(n+m);i++)
	{
		s[i].clear();
		lst[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&tr.a[i]);
		if(!id.count(tr.a[i])) id[tr.a[i]]=++tot;
		tr.pre[i]=0;
		tr.nex[i]=n+1;
		if(lst[id[tr.a[i]]])
		{
			tr.pre[i]=lst[id[tr.a[i]]];
			tr.nex[lst[id[tr.a[i]]]]=i;
		}
		lst[id[tr.a[i]]]=i;
		s[id[tr.a[i]]].insert(i);
	}
	tr.build(n);
	cnt=0;
	cas=0;
	while(m--)
	{
		cas++;
		scanf("%d%d%d",&op,&x,&y);
		x^=cnt;
		y^=cnt;
		if(op==1)
		{
			if(tr.a[x]==y) continue;
			if(!id.count(y)) id[y]=++tot;
			if(tr.nex[x]<=n)
			{
				tr.pre[tr.nex[x]]=tr.pre[x];
				tr.upd(tr.nex[x],tr.nex[x]);
			}
			if(tr.pre[x]) tr.nex[tr.pre[x]]=tr.nex[x];
			s[id[tr.a[x]]].erase(x);
			tr.a[x]=y;
			s[id[tr.a[x]]].insert(x);
			auto it=s[id[tr.a[x]]].lower_bound(x);
			if(it!=s[id[tr.a[x]]].begin()) tr.pre[x]=*(--it);
			else tr.pre[x]=0;
			it=s[id[tr.a[x]]].upper_bound(x);
			if(it!=s[id[tr.a[x]]].end()) tr.nex[x]=*it;
			else tr.nex[x]=n+1;
			tr.upd(x,x+1);
			if(tr.nex[x]<=n)
			{
				tr.pre[tr.nex[x]]=x;
				tr.upd(tr.nex[x],tr.nex[x]);
			}
			if(tr.pre[x]) tr.nex[tr.pre[x]]=x;
		}
		else
		{
			scanf("%d",&k);
			k^=cnt;
			puts(tr.ask(x,y,k)?cnt++,"Yes":"No");
		}
	}
	return 0;
}
