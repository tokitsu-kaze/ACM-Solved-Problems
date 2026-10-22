#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
const int mod=998244353;
struct Segment_Tree
{
	#define type ll
	static const int LOG=31*4; //range upd more *4
	static const int delta=1;
	struct node
	{
		type v,cnt;
		void init(){v=cnt=0;}
	}t[MAX*LOG],null_node;
	int root[MAX],ls[MAX*LOG],rs[MAX*LOG],rt,tot,qop;
	int st[MAX*LOG],top;
	int ql,qr,n;
	type qv,tag[MAX*LOG];
	Segment_Tree &operator[](const int _rt){this->rt=_rt;return *this;}
	void init(int _n)
	{
		n=_n+delta;
		rt=1;
		tot=top=0;
		t[0].init();
		ls[0]=rs[0]=0;
		null_node.init();
	}
	void build(){root[rt]=0;}
	void delnode(int id){st[top++]=id;}
	int newnode()
	{
		int id;
		id=top?st[--top]:++tot;
		t[id].init();
		ls[id]=rs[id]=0;
		tag[id]=0;
		return id;
	}
	node merge_node(node x,node y)
	{
		node res;
		res.v=(x.v+y.v)%mod;
		res.cnt=x.cnt+y.cnt;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls[id]],t[rs[id]]);}
	void pushdown(int l,int r,int id)
	{
		
	}
	void update(int l,int r,int &id)
	{
		if(!id) id=newnode();
		if(l>=ql&&r<=qr)
		{
			t[id].v=(t[id].v+qop*qv)%mod;
			t[id].cnt+=qop;
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls[id]);
		if(qr>mid) update(mid+1,r,rs[id]);
		pushup(id);
	}
	node query(int l,int r,int id)
	{
		if(!id) return null_node;
		if(l>=ql&&r<=qr) return t[id];
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(qr<=mid) return query(l,mid,ls[id]);
		if(ql>mid) return query(mid+1,r,rs[id]);
		return merge_node(query(l,mid,ls[id]),query(mid+1,r,rs[id]));
	}
	void upd(int l,int r,type v,int op)
	{
		ql=l+delta;
		qr=r+delta;
		qv=v;
		qop=op;
		update(1,n,root[rt]);
	}
	node ask(int l,int r)
	{
		ql=l+delta;
		qr=r+delta;
		return query(1,n,root[rt]);
	}
	#undef type
}tr;
/*
tr.init(n);
tr.build();
tr.upd(l,r,v);
tr.ask(l,r);
Segment_Tree::node res=tr.merge_node(nodex,nodey);
*/
ll ans;
void add(int x,int sgn)
{
	auto res=tr.ask(0,x);
	if(sgn==1) ans=(ans+sgn*x*(res.cnt+1))%mod;
	else ans=(ans+sgn*x*res.cnt)%mod;
	res=tr.ask(x+1,1e9+1);
	ans=(ans+sgn*res.v)%mod;
	tr.upd(x,x,x,sgn);
	ans=(ans+mod)%mod;
}
int main()
{
	int n,q,op,x,i;
	scanf("%d%d",&n,&q);
	tr.init(1e9+1);
	tr.build();
	ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		add(x,1);
	}
	while(q--)
	{
		scanf("%d",&op);
		if(op<=2) scanf("%d",&x);
		if(op==1) add(x,1);
		else if(op==2) add(x,-1);
		else printf("%lld\n",ans);
	}
	return 0;
}
