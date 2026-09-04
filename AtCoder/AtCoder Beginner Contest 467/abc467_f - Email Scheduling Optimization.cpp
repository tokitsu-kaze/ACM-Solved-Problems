#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct Segment_Tree
{
	#define type ll
	static const int LOG=31*4; //range upd more *4
	static const type inf=LLINF;
	struct node
	{
		type v,sz;
		void init(){v=-inf,sz=0;}
	}t[MAX*LOG],null_node;
	int root[MAX],ls[MAX*LOG],rs[MAX*LOG],rt,tot,qop;
	int st[MAX*LOG],top;
	int ql,qr,n;
	type qv,tag[MAX*LOG];
	Segment_Tree &operator[](const int _rt){this->rt=_rt;return *this;}
	void init(int _n)
	{
		n=_n;
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
		res.v=max(x.v,y.v);
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls[id]],t[rs[id]]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		if(!ls[id]) ls[id]=newnode();
		if(!rs[id]) rs[id]=newnode();
		int mid=(l+r)>>1;
		t[ls[id]].v+=tag[id];
		t[rs[id]].v+=tag[id];
		tag[ls[id]]+=tag[id];
		tag[rs[id]]+=tag[id];
		tag[id]=0;
	}
	void update(int l,int r,int &id)
	{
		if(!id) id=newnode();
		if(l>=ql&&r<=qr)
		{
			if(qop==1)
			{
				if(qv<0)
				{
					t[id].sz--;
					if(t[id].sz==0) t[id].v+=-inf+qv;
				}
				else
				{
					t[id].sz++;
					if(t[id].sz==1) t[id].v+=inf+qv;
				}
			}
			else
			{
				t[id].v+=qv;
				tag[id]+=qv;
			}
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
		ql=l;
		qr=r;
		qv=v;
		qop=op;
		update(1,n,root[rt]);
	}
	type ask(int l,int r)
	{
		ql=l;
		qr=r;
		return query(1,n,root[rt]).v;
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
int a[MAX],b[MAX];
int main()
{
	int n,q,i,op,x,v;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) scanf("%d",&b[i]);
	tr.init(1e9);
	tr.build();
	for(i=1;i<=n;i++)
	{
		tr.upd(b[i],b[i],b[i],1);
		tr.upd(1,b[i],a[i],2);
	}
	while(q--)
	{
		scanf("%d%d%d",&op,&x,&v);
		if(op==1)
		{
			tr.upd(1,b[x],v-a[x],2);
			a[x]=v;
		}
		else
		{
			tr.upd(b[x],b[x],-b[x],1);
			tr.upd(1,b[x],-a[x],2);
			b[x]=v;
			tr.upd(b[x],b[x],b[x],1);
			tr.upd(1,b[x],a[x],2);
		}
		printf("%lld\n",tr.ask(1,1e9));
	}
	return 0;
}
/*
按b从大到小排序，答案为max{sum{a1..ai}+bi}
要注意，每个有b的位置只能加上一个b。
*/
