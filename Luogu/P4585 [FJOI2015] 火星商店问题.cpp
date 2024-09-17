#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct Trie
{
	#define type int
	static const int LOG=17;
	static const int K=LOG*LOG+2;
	static const type inf=INF;
	int rt,root[MAX<<2],tot,ch[MAX*K][2],mx[MAX*K];
	Trie &operator[](const int _rt){this->rt=_rt;return *this;}
	int newnode()
	{
		tot++;
		memset(ch[tot],0,sizeof ch[tot]);
		mx[tot]=-inf;
		return tot;
	}
	void init(int n=1)
	{
		ch[0][0]=ch[0][1]=0;
		mx[0]=-inf;
		tot=1;
		for(int i=0;i<=n;i++) root[i]=0;
		rt=1;
	}
	void insert(type x,int d)
	{
		int id,t,i;
		if(!root[rt]) root[rt]=newnode();
		id=root[rt];
		for(i=LOG;~i;i--)
		{
			mx[id]=max(mx[id],d);
			t=(x>>i)&1;
			if(!ch[id][t]) ch[id][t]=newnode();
			id=ch[id][t];
		}
		mx[id]=max(mx[id],d);
	}
	type ask_max(type x,int d)
	{
		int id,i;
		type res,t;
		if(!root[rt]) return -inf;
		id=root[rt];
		res=0;
		for(i=LOG;~i;i--)
		{
			t=(x>>i)&1;
			if(ch[id][t^1]&&mx[ch[id][t^1]]>=d) t^=1;
			res|=(t<<i);
			id=ch[id][t];
		}
		return res^x;
	}
	#undef type
}trie;
struct Segment_Tree
{
	#define type int
	static const type inf=INF;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	type qv,qd;
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
	void build(int l,int r,int id)
	{
		t[id].init();
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
	}
	void update(int l,int r,int id)
	{
		trie[id].insert(qv,qd);
		if(l>=ql&&r<=qr) return;
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
	}
	node query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			t[id].mx=trie[id].ask_max(qv,qd);
			return t[id];
		}
		int mid=(l+r)>>1;
		if(qr<=mid) return query(l,mid,ls);
		if(ql>mid) return query(mid+1,r,rs);
		return merge_node(query(l,mid,ls),query(mid+1,r,rs));
	}
	void build(int _n)
	{
		n=_n;
		build(1,n,1);
		trie.init(n);
		null_node.init();
	}
	void upd(int l,int r,type v,type d)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		qd=d;
		update(1,n,1);
	}
	type ask(int l,int r,int x,int d)
	{
		if(l>r) return null_node.mx;
		ql=l;
		qr=r;
		qv=x;
		qd=d;
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
int main()
{
	int n,q,i,op,l,r,x,d,now;
	scanf("%d%d",&n,&q);
	tr.build(n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		tr.upd(i,i,x,INF);
	}
	now=0;
	while(q--)
	{
		scanf("%d",&op);
		if(op==0)
		{
			now++;
			scanf("%d%d",&l,&x);
			tr.upd(l,l,x,now);
		}
		else
		{
			scanf("%d%d%d%d",&l,&r,&x,&d);
			printf("%d\n",tr.ask(l,r,x,now-d+1));
		}
	}
	return 0;
}
