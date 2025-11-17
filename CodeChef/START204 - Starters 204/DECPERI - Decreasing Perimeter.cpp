#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Disjoint_Set_Union
{
	int pre[MAX],sz[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
			sz[i]=1;
		}
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int x,int y,bool dir=false)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(!dir && sz[x]>sz[y]) swap(x,y);
		pre[x]=y; // x -> y
		sz[y]+=sz[x];
		return 1;
	}
}pre,nex;
struct Segment_Tree
{
	#define type ll
	static const type inf=LLINF;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		type v;
		void init(){v=0;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.v=x.v+y.v;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		t[ls].v+=tag[id];
		t[rs].v+=tag[id];
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
			t[id].v=a[l];
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
			t[id].v+=qv;
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
		if(l>r) return null_node.v;
		ql=l;
		qr=r;
		return query(1,n,1).v;
	}
	type ask(int x)
	{
		if(x<1 || x>n) return null_node.v;
		ql=x;
		qr=x;
		return query(1,n,1).v;
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
struct node
{
	int l,r;
	friend bool operator <(node x,node y)
	{
		return x.r-x.l>y.r-y.l;
	}
};
int ck(int l,int r)
{
	ll a,b,c;
	a=tr.ask(l-1);
	b=tr.ask(l);
	c=tr.ask(r+1);
	if(a>b && c>b) return 1;
	return 0;
}
int main()
{
	int T,n,i,l,r;
	ll k,now,ans,tmp,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld",&n,&k);
		pre.init(n);
		nex.init(n);
		tr.a[0]=tr.a[n+1]=0;
		vector<node> res;
		l=r=-1;
		now=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&tr.a[i]);
			if(tr.a[i]==tr.a[i-1])
			{
				r++;
				if(i-1>=1)
				{
					pre.merge(i,i-1,true);
					nex.merge(i-1,i,true);
				}
			}
			else
			{
				if(l>=1) res.push_back({l,r});
				l=r=i;
			}
			now+=abs(tr.a[i]-tr.a[i-1]);
			now+=2;
		}
		now+=tr.a[n];
		res.push_back({l,r});
		tr.build(n);
		priority_queue<node> q;
		for(auto &it:res)
		{
			if(ck(it.l,it.r)) q.push(it);
		}
		ans=0;
		while(!q.empty() && now>k)
		{
			node t=q.top();
			q.pop();
			tmp=min(tr.ask(t.l-1),tr.ask(t.r+1))-tr.ask(t.l);
			if(tmp==0) continue;
			tmp=min((now-k+1)/2,tmp);
			ans+=(t.r-t.l+1)*tmp;
			now-=2*tmp;
			tr.upd(t.l,t.r,tmp);
			x=tr.ask(t.l);
			if(tr.ask(t.l-1)==x)
			{
				if(t.l-1>=1)
				{
					pre.merge(t.l,t.l-1,true);
					nex.merge(t.l-1,t.l,true);
				}
			}
			if(tr.ask(t.r+1)==x)
			{
				if(t.r+1<=n)
				{
					pre.merge(t.r+1,t.r,true);
					nex.merge(t.r,t.r+1,true);
				}
			}
			t.l=pre.find(t.l);
			t.r=nex.find(t.r);
			if(ck(t.l,t.r)) q.push(t);
		}
		if(now>k) ans=-1;
		printf("%lld\n",ans);
	}
	return 0;
}

